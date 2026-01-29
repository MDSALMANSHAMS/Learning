"""
02_Features_extraction.py
Feature extraction from 3D point clouds using Open3D.
Computes geometric features and stores them in a Pandas DataFrame.
"""

from pathlib import Path
from typing import Tuple

import numpy as np
import open3d as o3d
import pandas as pd
import requests


# =============================================================================
# Configuration
# =============================================================================

DATA_URL: str = "https://storage.openvinotoolkit.org/repositories/openvino_notebooks/data/data/pts/chair.pts"
LOCAL_DATA_DIR: Path = Path("data")
LOCAL_FILE_PATH: Path = LOCAL_DATA_DIR / "chair.pts"
NUM_OBJECTS: int = 10

# Distinct colors for each object
COLORS = [
    [0.9, 0.2, 0.2],   # Red
    [0.2, 0.7, 0.2],   # Green
    [0.2, 0.2, 0.9],   # Blue
    [0.9, 0.7, 0.1],   # Yellow
    [0.8, 0.2, 0.8],   # Magenta
    [0.2, 0.8, 0.8],   # Cyan
    [0.9, 0.5, 0.1],   # Orange
    [0.5, 0.2, 0.7],   # Purple
    [0.3, 0.9, 0.5],   # Lime
    [0.9, 0.4, 0.6],   # Pink
]


# =============================================================================
# Data Loading Functions
# =============================================================================

def download_file(url: str, local_path: Path) -> None:
    """Download a file from URL if it doesn't exist locally."""
    if local_path.exists():
        print(f"File already exists: {local_path}")
        return

    print(f"Downloading from {url}...")
    local_path.parent.mkdir(parents=True, exist_ok=True)

    response = requests.get(url, timeout=60)
    response.raise_for_status()

    with open(local_path, "wb") as f:
        f.write(response.content)

    print(f"Downloaded to {local_path}")


def load_pts_file(file_path: Path) -> np.ndarray:
    """Load a .pts file and return point coordinates as numpy array."""
    points = []

    with open(file_path, "r") as f:
        lines = f.readlines()

    start_idx = 0
    try:
        int(lines[0].strip())
        start_idx = 1
    except ValueError:
        pass

    for line in lines[start_idx:]:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) >= 3:
            points.append([float(parts[0]), float(parts[1]), float(parts[2])])

    return np.array(points, dtype=np.float64)


def numpy_to_pointcloud(points: np.ndarray) -> o3d.geometry.PointCloud:
    """Convert numpy array to Open3D PointCloud."""
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(points)
    return pcd


# =============================================================================
# Open3D Sample Data Loading
# =============================================================================

def load_open3d_samples() -> list[Tuple[str, o3d.geometry.PointCloud]]:
    """Load sample point clouds from Open3D datasets."""
    samples = []

    # Eagle Point Cloud
    print("  Loading Eagle point cloud...")
    try:
        dataset_eagle = o3d.data.EaglePointCloud()
        pcd_eagle = o3d.io.read_point_cloud(dataset_eagle.path)
        samples.append(("eagle", pcd_eagle))
        print(f"    Eagle: {len(pcd_eagle.points)} points")
    except Exception as e:
        print(f"    Failed: {e}")

    # Bunny Mesh -> Point Cloud
    print("  Loading Bunny mesh...")
    try:
        dataset_bunny = o3d.data.BunnyMesh()
        mesh_bunny = o3d.io.read_triangle_mesh(dataset_bunny.path)
        pcd_bunny = mesh_bunny.sample_points_uniformly(number_of_points=10000)
        samples.append(("bunny", pcd_bunny))
        print(f"    Bunny: {len(pcd_bunny.points)} points")
    except Exception as e:
        print(f"    Failed: {e}")

    return samples


# =============================================================================
# Point Cloud Generation
# =============================================================================

def generate_object_variants(
    base_objects: list[Tuple[str, np.ndarray]],
    num_objects: int
) -> list[Tuple[str, o3d.geometry.PointCloud]]:
    """
    Generate point cloud variants from base objects.
    Each variant has different transformations and colors.
    """
    np.random.seed(42)
    objects = []
    variant_count = {}

    for i in range(num_objects):
        # Cycle through base objects
        base_name, base_points = base_objects[i % len(base_objects)]
        points = base_points.copy()

        # Track variant number per base object
        if base_name not in variant_count:
            variant_count[base_name] = 0
        variant_count[base_name] += 1
        variant_num = variant_count[base_name]

        # Random scaling (0.8 to 1.2)
        scale = 0.8 + np.random.rand() * 0.4
        points *= scale

        # Random rotation around Z axis
        angle = np.random.rand() * 2 * np.pi
        cos_a, sin_a = np.cos(angle), np.sin(angle)
        rotation = np.array([
            [cos_a, -sin_a, 0],
            [sin_a, cos_a, 0],
            [0, 0, 1]
        ])
        points = points @ rotation.T

        # Random translation
        translation = np.array([
            np.random.rand() * 5 - 2.5,
            np.random.rand() * 5 - 2.5,
            np.random.rand() * 2
        ])
        points += translation

        # Subsample (70% to 100%)
        num_pts = int(len(points) * (0.7 + np.random.rand() * 0.3))
        indices = np.random.choice(len(points), num_pts, replace=False)
        points = points[indices]

        # Create point cloud with distinct color
        pcd = numpy_to_pointcloud(points)
        pcd.paint_uniform_color(COLORS[i % len(COLORS)])

        # Estimate normals
        pcd.estimate_normals(
            search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1, max_nn=30)
        )

        name = f"{base_name}_{variant_num}"
        objects.append((name, pcd))

    return objects


# =============================================================================
# Feature Extraction
# =============================================================================

def compute_obb_dimensions(
    pcd: o3d.geometry.PointCloud
) -> Tuple[float, float, float, o3d.geometry.OrientedBoundingBox]:
    """Compute OBB dimensions (Length >= Width >= Height)."""
    obb = pcd.get_oriented_bounding_box()
    dims = sorted(obb.extent, reverse=True)
    return dims[0], dims[1], dims[2], obb


def extract_features(pcd: o3d.geometry.PointCloud, object_id: int) -> dict:
    """Extract all geometric features from a point cloud."""
    num_points = len(pcd.points)
    length, width, height, obb = compute_obb_dimensions(pcd)

    volume = length * width * height
    density = num_points / volume if volume > 1e-10 else 0.0

    points = np.asarray(pcd.points)
    ground_dist = float(np.min(points[:, 2]))

    aspect_lw = length / width if width > 1e-10 else 0.0
    aspect_wh = width / height if height > 1e-10 else 0.0

    return {
        "ID": object_id,
        "NbPoints": num_points,
        "Length": round(length, 4),
        "Width": round(width, 4),
        "Height": round(height, 4),
        "Density": round(density, 4),
        "GroundDist": round(ground_dist, 4),
        "AspectRatio_LW": round(aspect_lw, 4),
        "AspectRatio_WH": round(aspect_wh, 4),
        "OBB": obb
    }


def categorize_value(value: float, low_thresh: float, high_thresh: float) -> str:
    """Categorize a value as low, medium, or high based on thresholds."""
    if value <= low_thresh:
        return "low"
    elif value >= high_thresh:
        return "high"
    else:
        return "medium"


def create_categorical_features(df: pd.DataFrame) -> pd.DataFrame:
    """
    Create a categorical version of features (low/medium/high).
    Uses percentile-based thresholds (33rd and 66th percentiles).
    """
    numeric_cols = ["NbPoints", "Length", "Width", "Height",
                    "Density", "GroundDist", "AspectRatio_LW", "AspectRatio_WH"]

    df_cat = df[["ID", "Name"]].copy()

    for col in numeric_cols:
        low_thresh = df[col].quantile(0.33)
        high_thresh = df[col].quantile(0.66)
        df_cat[col] = df[col].apply(lambda x: categorize_value(x, low_thresh, high_thresh))

    df_cat["label_chair"] = df["label_chair"]
    return df_cat


# =============================================================================
# Visualization
# =============================================================================

def visualize_pointcloud_with_obb(
    pcd: o3d.geometry.PointCloud,
    obb: o3d.geometry.OrientedBoundingBox,
    object_id: int,
    object_name: str
) -> None:
    """Visualize a point cloud with its OBB, centered."""
    # Create copies for visualization
    pcd_vis = o3d.geometry.PointCloud(pcd)
    obb_vis = o3d.geometry.OrientedBoundingBox(obb)

    # Center for visualization
    centroid = pcd_vis.get_center()
    pcd_vis.translate(-centroid)
    obb_vis.translate(-centroid)

    obb_vis.color = (1, 0, 0)

    title = f"Object {object_id} - {object_name} with OBB"
    print(f"\nVisualizing {title} (close window to continue)...")

    o3d.visualization.draw_geometries(
        [pcd_vis, obb_vis],
        window_name=title,
        width=800,
        height=600
    )


# =============================================================================
# Main
# =============================================================================

def main() -> None:
    """Main function."""
    print("=" * 60)
    print("3D Point Cloud Feature Extraction")
    print("=" * 60)

    # Step 1: Load all base point clouds
    print("\n[1/4] Loading point cloud data...")

    base_objects = []

    # Load chair from URL
    print("  Loading Chair from URL...")
    download_file(DATA_URL, LOCAL_FILE_PATH)
    chair_points = load_pts_file(LOCAL_FILE_PATH)
    base_objects.append(("chair", chair_points))
    print(f"    Chair: {len(chair_points)} points")

    # Load Open3D samples
    open3d_samples = load_open3d_samples()
    for name, pcd in open3d_samples:
        points = np.asarray(pcd.points)
        base_objects.append((name, points))

    print(f"\n  Total base objects: {len(base_objects)}")

    # Step 2: Generate 10 variants
    print(f"\n[2/4] Generating {NUM_OBJECTS} object variants...")
    all_objects = generate_object_variants(base_objects, NUM_OBJECTS)

    # Step 3: Extract features
    print("\n[3/4] Extracting features...")
    features_list = []

    for idx, (name, pcd) in enumerate(all_objects):
        object_id = idx + 1
        print(f"\nProcessing {name}...")

        features = extract_features(pcd, object_id)
        features["Name"] = name
        features["label_chair"] = "yes" if name.startswith("chair") else "no"

        visualize_pointcloud_with_obb(pcd, features["OBB"], object_id, name)

        features.pop("OBB")
        features_list.append(features)

        print(f"  NbPoints: {features['NbPoints']}")
        print(f"  Dimensions: {features['Length']} x {features['Width']} x {features['Height']}")

    # Step 4: Create DataFrame
    print("\n[4/4] Creating results...")

    df = pd.DataFrame(features_list)
    cols = ["ID", "Name", "NbPoints", "Length", "Width", "Height",
            "Density", "GroundDist", "AspectRatio_LW", "AspectRatio_WH", "label_chair"]
    df = df[cols]

    print("\n" + "=" * 60)
    print("RESULTS - NUMERIC FEATURES")
    print("=" * 60)
    print("\n" + df.to_string(index=False))

    # Create categorical features table
    df_categorical = create_categorical_features(df)

    print("\n" + "=" * 60)
    print("RESULTS - CATEGORICAL FEATURES (low/medium/high)")
    print("=" * 60)
    print("\n" + df_categorical.to_string(index=False))

    # Save both tables
    output_path = LOCAL_DATA_DIR / "features.csv"
    df.to_csv(output_path, index=False)
    print(f"\nSaved numeric features to: {output_path}")

    output_path_cat = LOCAL_DATA_DIR / "features_categorical.csv"
    df_categorical.to_csv(output_path_cat, index=False)
    print(f"Saved categorical features to: {output_path_cat}")


if __name__ == "__main__":
    main()