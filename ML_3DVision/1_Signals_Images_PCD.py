"""
Visualization Module
Generates and plots random images, signals, and 3D point clouds.
"""

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from loguru import logger

def create_random_rgb_image(height=100, width=100):
    """
    Create a random RGB image.

    Args:
        height: Image height in pixels
        width: Image width in pixels

    Returns:
        numpy.ndarray: Random RGB image with shape (height, width, 3)
    """
    image = np.random.rand(height, width, 3)
    logger.info(f"Random RGB Image - Shape: {image.shape}, "
                f"Min: {image.min():.3f}, Max: {image.max():.3f}, "
                f"Mean: {image.mean():.3f}, Dtype: {image.dtype}")
    return image


def create_black_image_with_insert(outer_height=300, outer_width=300,
                                   inner_height=100, inner_width=100):
    """
    Create a black image with a random RGB image inserted in the middle.

    Args:
        outer_height: Height of the black canvas
        outer_width: Width of the black canvas
        inner_height: Height of the RGB image to insert
        inner_width: Width of the RGB image to insert

    Returns:
        numpy.ndarray: Black image with RGB insert in the middle
    """
    # Create black image
    black_image = np.zeros((outer_height, outer_width, 3))

    # Create random RGB image
    rgb_insert = create_random_rgb_image(inner_height, inner_width)

    # Calculate center position
    start_y = (outer_height - inner_height) // 2
    start_x = (outer_width - inner_width) // 2

    # Insert RGB image in the middle
    black_image[start_y:start_y + inner_height,
                start_x:start_x + inner_width] = rgb_insert

    logger.info(f"Black Image with Insert - Shape: {black_image.shape}, "
                f"Insert position: ({start_y}:{start_y + inner_height}, {start_x}:{start_x + inner_width}), "
                f"Non-zero pixels: {np.count_nonzero(black_image)}, "
                f"Dtype: {black_image.dtype}")

    return black_image


def create_noisy_sine_signal(num_points=1000, frequency=5, noise_level=0.3):
    """
    Create a sine wave signal with random noise.

    Args:
        num_points: Number of points in the signal
        frequency: Frequency of the sine wave
        noise_level: Amplitude of the random noise

    Returns:
        tuple: (x_values, y_values) for the noisy sine signal
    """
    x = np.linspace(0, 2 * np.pi, num_points)
    sine_wave = np.sin(frequency * x)
    noise = noise_level * np.random.randn(num_points)
    noisy_signal = sine_wave + noise

    logger.info(f"Noisy Sine Signal - X shape: {x.shape}, Y shape: {noisy_signal.shape}, "
                f"Frequency: {frequency}, Noise level: {noise_level}, "
                f"Y Min: {noisy_signal.min():.3f}, Y Max: {noisy_signal.max():.3f}, "
                f"Y Mean: {noisy_signal.mean():.3f}, Y Std: {noisy_signal.std():.3f}")

    return x, noisy_signal


def create_random_point_cloud(num_points=500):
    """
    Create a random 3D point cloud.

    Args:
        num_points: Number of points in the cloud

    Returns:
        tuple: (x, y, z) coordinates of the point cloud
    """
    x = np.random.rand(num_points) * 10
    y = np.random.rand(num_points) * 10
    z = np.random.rand(num_points) * 10

    logger.info(f"3D Point Cloud - Number of points: {num_points}, "
                f"X range: [{x.min():.3f}, {x.max():.3f}], "
                f"Y range: [{y.min():.3f}, {y.max():.3f}], "
                f"Z range: [{z.min():.3f}, {z.max():.3f}], "
                f"Shape: ({x.shape[0]}, 3)")

    return x, y, z


def visualize_all():
    """
    Create and visualize all elements in a single figure with subplots:
    1. Random RGB image
    2. Black image with RGB insert
    3. Noisy sine signal
    4. 3D point cloud
    """
    logger.info("=" * 60)
    logger.info("Starting visualization generation...")
    logger.info("=" * 60)

    # Create figure with subplots
    fig = plt.figure(figsize=(14, 10))

    # 1. Random RGB Image
    ax1 = fig.add_subplot(2, 2, 1)
    rgb_image = create_random_rgb_image(100, 100)
    ax1.imshow(rgb_image)
    ax1.set_title('Random RGB Image')
    ax1.axis('off')

    # 2. Black Image with RGB Insert
    ax2 = fig.add_subplot(2, 2, 2)
    black_with_insert = create_black_image_with_insert(300, 300, 100, 100)
    ax2.imshow(black_with_insert)
    ax2.set_title('Black Image with RGB Insert in Middle')
    ax2.axis('off')

    # 3. Noisy Sine Signal
    ax3 = fig.add_subplot(2, 2, 3)
    x, y = create_noisy_sine_signal(num_points=1000, frequency=5, noise_level=0.3)
    ax3.plot(x, y, linewidth=0.8)
    ax3.set_title('Sine Wave with Random Noise')
    ax3.set_xlabel('x')
    ax3.set_ylabel('y')
    ax3.grid(True, alpha=0.3)

    # 4. 3D Point Cloud
    ax4 = fig.add_subplot(2, 2, 4, projection='3d')
    x_cloud, y_cloud, z_cloud = create_random_point_cloud(num_points=500)
    ax4.scatter(x_cloud, y_cloud, z_cloud, c=z_cloud, cmap='viridis',
                marker='o', s=10, alpha=0.6)
    ax4.set_title('Random 3D Point Cloud')
    ax4.set_xlabel('X')
    ax4.set_ylabel('Y')
    ax4.set_zlabel('Z')

    logger.info("=" * 60)
    logger.info("All visualizations created successfully!")
    logger.info("=" * 60)

    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    # Run visualization when module is executed directly
    visualize_all()