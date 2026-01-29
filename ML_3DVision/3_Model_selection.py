"""
03_Model_selection.py
Model selection and training for binary classification of 3D objects.
Uses sklearn classifiers with K-Fold cross-validation and comprehensive evaluation.
"""

from pathlib import Path
from typing import Dict, List, Tuple

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.ensemble import (
    AdaBoostClassifier,
    BaggingClassifier,
    ExtraTreesClassifier,
    GradientBoostingClassifier,
    RandomForestClassifier,
)
from sklearn.linear_model import (
    LogisticRegression,
    RidgeClassifier,
    SGDClassifier,
)
from sklearn.model_selection import (
    cross_val_score,
    StratifiedKFold,
    train_test_split,
)
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.svm import SVC, LinearSVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import (
    accuracy_score,
    precision_score,
    recall_score,
    f1_score,
    roc_auc_score,
    roc_curve,
    confusion_matrix,
    classification_report,
    ConfusionMatrixDisplay,
)


# =============================================================================
# Configuration
# =============================================================================

DATA_PATH: Path = Path("output/features.csv")
OUTPUT_DIR: Path = Path("output/model_selection")
RANDOM_STATE: int = 42
TEST_SIZE: float = 0.2
N_FOLDS: int = 5

# Feature columns (excluding ID, Name, and target)
FEATURE_COLUMNS: List[str] = [
    "NbPoints",
    "Length",
    "Width",
    "Height",
    "Density",
    "GroundDist",
    "AspectRatio_LW",
    "AspectRatio_WH",
]
TARGET_COLUMN: str = "label_chair"


# =============================================================================
# Dataset
# =============================================================================

def load_dataset(data_path: Path) -> Tuple[pd.DataFrame, np.ndarray, np.ndarray]:
    """
    Load and preprocess the dataset.

    Returns:
        df: Original DataFrame
        X: Feature matrix (scaled)
        y: Target vector (encoded)
    """
    print("Loading dataset...")
    df = pd.read_csv(data_path)

    print(f"  Shape: {df.shape}")
    print(f"  Features: {FEATURE_COLUMNS}")
    print(f"  Target: {TARGET_COLUMN}")

    # Extract features and target
    X = df[FEATURE_COLUMNS].values
    y_raw = df[TARGET_COLUMN].values

    # Encode target (yes=1, no=0)
    label_encoder = LabelEncoder()
    y = label_encoder.fit_transform(y_raw)

    print(f"  Class distribution: {dict(zip(label_encoder.classes_, np.bincount(y)))}")

    # Scale features
    scaler = StandardScaler()
    X = scaler.fit_transform(X)

    return df, X, y


# =============================================================================
# Model Selection - All sklearn Classifiers
# =============================================================================

def get_classifiers() -> Dict[str, object]:
    """
    Return a dictionary of sklearn classifiers for model selection.

    Includes classifiers from multiple categories:
    - Linear Models
    - Support Vector Machines
    - Nearest Neighbors
    - Decision Trees
    - Ensemble Methods
    - Naive Bayes
    - Neural Networks
    """
    classifiers = {
        # --- Linear Models ---
        "LogisticRegression": LogisticRegression(
            random_state=RANDOM_STATE,
            max_iter=1000,
        ),
        "RidgeClassifier": RidgeClassifier(
            random_state=RANDOM_STATE,
        ),
        "SGDClassifier": SGDClassifier(
            random_state=RANDOM_STATE,
            max_iter=1000,
            tol=1e-3,
        ),

        # --- Support Vector Machines ---
        "SVC_RBF": SVC(
            kernel="rbf",
            random_state=RANDOM_STATE,
            probability=True,
        ),
        "SVC_Linear": SVC(
            kernel="linear",
            random_state=RANDOM_STATE,
            probability=True,
        ),
        "SVC_Poly": SVC(
            kernel="poly",
            degree=3,
            random_state=RANDOM_STATE,
            probability=True,
        ),
        "LinearSVC": LinearSVC(
            random_state=RANDOM_STATE,
            max_iter=1000,
            dual="auto",
        ),

        # --- Nearest Neighbors ---
        "KNN_3": KNeighborsClassifier(n_neighbors=3),
        "KNN_5": KNeighborsClassifier(n_neighbors=5),
        "KNN_7": KNeighborsClassifier(n_neighbors=7),

        # --- Decision Trees ---
        "DecisionTree": DecisionTreeClassifier(
            random_state=RANDOM_STATE,
        ),
        "DecisionTree_Depth5": DecisionTreeClassifier(
            max_depth=5,
            random_state=RANDOM_STATE,
        ),

        # --- Ensemble Methods: Bagging ---
        "RandomForest": RandomForestClassifier(
            n_estimators=100,
            random_state=RANDOM_STATE,
        ),
        "RandomForest_Depth5": RandomForestClassifier(
            n_estimators=100,
            max_depth=5,
            random_state=RANDOM_STATE,
        ),
        "ExtraTrees": ExtraTreesClassifier(
            n_estimators=100,
            random_state=RANDOM_STATE,
        ),
        "BaggingClassifier": BaggingClassifier(
            n_estimators=100,
            random_state=RANDOM_STATE,
        ),

        # --- Ensemble Methods: Boosting ---
        "AdaBoost": AdaBoostClassifier(
            n_estimators=100,
            random_state=RANDOM_STATE,
            algorithm="SAMME",
        ),
        "GradientBoosting": GradientBoostingClassifier(
            n_estimators=100,
            random_state=RANDOM_STATE,
        ),

        # --- Naive Bayes ---
        "GaussianNB": GaussianNB(),

        # --- Neural Networks ---
        "MLP_Small": MLPClassifier(
            hidden_layer_sizes=(50,),
            random_state=RANDOM_STATE,
            max_iter=1000,
        ),
        "MLP_Medium": MLPClassifier(
            hidden_layer_sizes=(100, 50),
            random_state=RANDOM_STATE,
            max_iter=1000,
        ),
    }

    return classifiers


def print_classifiers_summary(classifiers: Dict[str, object]) -> None:
    """Print a summary of all available classifiers."""
    print("\n" + "=" * 60)
    print("AVAILABLE CLASSIFIERS")
    print("=" * 60)

    categories = {
        "Linear Models": ["LogisticRegression", "RidgeClassifier", "SGDClassifier"],
        "Support Vector Machines": ["SVC_RBF", "SVC_Linear", "SVC_Poly", "LinearSVC"],
        "Nearest Neighbors": ["KNN_3", "KNN_5", "KNN_7"],
        "Decision Trees": ["DecisionTree", "DecisionTree_Depth5"],
        "Ensemble - Bagging": ["RandomForest", "RandomForest_Depth5", "ExtraTrees", "BaggingClassifier"],
        "Ensemble - Boosting": ["AdaBoost", "GradientBoosting"],
        "Naive Bayes": ["GaussianNB"],
        "Neural Networks": ["MLP_Small", "MLP_Medium"],
    }

    for category, names in categories.items():
        print(f"\n{category}:")
        for name in names:
            if name in classifiers:
                print(f"  - {name}")

    print(f"\nTotal: {len(classifiers)} classifiers")


# =============================================================================
# Train-Test Split
# =============================================================================

def split_data(
    X: np.ndarray,
    y: np.ndarray,
    test_size: float = TEST_SIZE,
) -> Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    """
    Split data into training and test sets using stratified sampling.
    """
    X_train, X_test, y_train, y_test = train_test_split(
        X, y,
        test_size=test_size,
        random_state=RANDOM_STATE,
        stratify=y,
    )

    print(f"\nTrain-Test Split (test_size={test_size}):")
    print(f"  Train set: {X_train.shape[0]} samples")
    print(f"  Test set: {X_test.shape[0]} samples")

    return X_train, X_test, y_train, y_test


# =============================================================================
# K-Fold Cross-Validation Training
# =============================================================================

def train_with_kfold(
    classifiers: Dict[str, object],
    X_train: np.ndarray,
    y_train: np.ndarray,
    n_folds: int = N_FOLDS,
) -> pd.DataFrame:
    """
    Train all classifiers using Stratified K-Fold cross-validation.

    Returns:
        DataFrame with cross-validation results for each classifier.
    """
    print("\n" + "=" * 60)
    print(f"K-FOLD CROSS-VALIDATION (k={n_folds})")
    print("=" * 60)

    skf = StratifiedKFold(n_splits=n_folds, shuffle=True, random_state=RANDOM_STATE)

    results = []

    for name, clf in classifiers.items():
        print(f"\nTraining {name}...")

        # Cross-validation scores
        cv_scores = cross_val_score(clf, X_train, y_train, cv=skf, scoring="accuracy")

        result = {
            "Classifier": name,
            "CV_Mean": cv_scores.mean(),
            "CV_Std": cv_scores.std(),
            "CV_Min": cv_scores.min(),
            "CV_Max": cv_scores.max(),
        }

        # Store individual fold scores
        for i, score in enumerate(cv_scores):
            result[f"Fold_{i+1}"] = score

        results.append(result)

        print(f"  Accuracy: {cv_scores.mean():.4f} (+/- {cv_scores.std():.4f})")

    df_results = pd.DataFrame(results)
    df_results = df_results.sort_values("CV_Mean", ascending=False).reset_index(drop=True)

    return df_results


# =============================================================================
# Evaluation Metrics
# =============================================================================

def evaluate_model(
    clf,
    X_test: np.ndarray,
    y_test: np.ndarray,
    model_name: str,
) -> Dict:
    """
    Evaluate a trained classifier on the test set.

    Returns:
        Dictionary with evaluation metrics.
    """
    y_pred = clf.predict(X_test)

    # Get probability predictions if available
    if hasattr(clf, "predict_proba"):
        y_proba = clf.predict_proba(X_test)[:, 1]
    elif hasattr(clf, "decision_function"):
        y_proba = clf.decision_function(X_test)
    else:
        y_proba = y_pred

    metrics = {
        "Classifier": model_name,
        "Accuracy": accuracy_score(y_test, y_pred),
        "Precision": precision_score(y_test, y_pred, zero_division=0),
        "Recall": recall_score(y_test, y_pred, zero_division=0),
        "F1_Score": f1_score(y_test, y_pred, zero_division=0),
        "ROC_AUC": roc_auc_score(y_test, y_proba),
    }

    return metrics, y_pred, y_proba


def evaluate_all_models(
    classifiers: Dict[str, object],
    X_train: np.ndarray,
    X_test: np.ndarray,
    y_train: np.ndarray,
    y_test: np.ndarray,
) -> Tuple[pd.DataFrame, Dict]:
    """
    Train and evaluate all classifiers on the test set.

    Returns:
        DataFrame with metrics and dictionary with predictions.
    """
    print("\n" + "=" * 60)
    print("MODEL EVALUATION ON TEST SET")
    print("=" * 60)

    all_metrics = []
    predictions = {}

    for name, clf in classifiers.items():
        print(f"\nEvaluating {name}...")

        # Train on full training set
        clf.fit(X_train, y_train)

        # Evaluate
        metrics, y_pred, y_proba = evaluate_model(clf, X_test, y_test, name)
        all_metrics.append(metrics)
        predictions[name] = {"y_pred": y_pred, "y_proba": y_proba}

        print(f"  Accuracy: {metrics['Accuracy']:.4f}")
        print(f"  F1 Score: {metrics['F1_Score']:.4f}")
        print(f"  ROC AUC:  {metrics['ROC_AUC']:.4f}")

    df_metrics = pd.DataFrame(all_metrics)
    df_metrics = df_metrics.sort_values("F1_Score", ascending=False).reset_index(drop=True)

    return df_metrics, predictions


# =============================================================================
# Visualization / Plots
# =============================================================================

def plot_cv_results(df_cv: pd.DataFrame, output_dir: Path) -> None:
    """Plot cross-validation results comparison."""
    fig, ax = plt.subplots(figsize=(12, 8))

    # Sort by mean accuracy
    df_sorted = df_cv.sort_values("CV_Mean", ascending=True)

    # Bar chart with error bars
    y_pos = np.arange(len(df_sorted))
    bars = ax.barh(y_pos, df_sorted["CV_Mean"], xerr=df_sorted["CV_Std"],
                   align="center", alpha=0.8, capsize=3, color="steelblue")

    ax.set_yticks(y_pos)
    ax.set_yticklabels(df_sorted["Classifier"])
    ax.set_xlabel("Accuracy")
    ax.set_title("K-Fold Cross-Validation Results")
    ax.set_xlim(0, 1.1)

    # Add value labels
    for i, (mean, std) in enumerate(zip(df_sorted["CV_Mean"], df_sorted["CV_Std"])):
        ax.text(mean + std + 0.02, i, f"{mean:.3f}", va="center", fontsize=9)

    plt.tight_layout()
    plt.savefig(output_dir / "cv_results.png", dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {output_dir / 'cv_results.png'}")


def plot_metrics_comparison(df_metrics: pd.DataFrame, output_dir: Path) -> None:
    """Plot comparison of evaluation metrics across models."""
    fig, axes = plt.subplots(2, 2, figsize=(14, 10))

    metrics_to_plot = ["Accuracy", "Precision", "Recall", "F1_Score"]
    colors = ["steelblue", "forestgreen", "darkorange", "firebrick"]

    for ax, metric, color in zip(axes.flat, metrics_to_plot, colors):
        df_sorted = df_metrics.sort_values(metric, ascending=True)

        y_pos = np.arange(len(df_sorted))
        ax.barh(y_pos, df_sorted[metric], color=color, alpha=0.8)
        ax.set_yticks(y_pos)
        ax.set_yticklabels(df_sorted["Classifier"], fontsize=8)
        ax.set_xlabel(metric)
        ax.set_title(f"{metric} Comparison")
        ax.set_xlim(0, 1.1)

        # Add value labels
        for i, val in enumerate(df_sorted[metric]):
            ax.text(val + 0.02, i, f"{val:.3f}", va="center", fontsize=8)

    plt.tight_layout()
    plt.savefig(output_dir / "metrics_comparison.png", dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {output_dir / 'metrics_comparison.png'}")


def plot_roc_curves(
    predictions: Dict,
    y_test: np.ndarray,
    output_dir: Path,
    top_n: int = 5,
) -> None:
    """Plot ROC curves for top N models."""
    fig, ax = plt.subplots(figsize=(10, 8))

    # Sort by ROC AUC and get top N
    roc_aucs = []
    for name, preds in predictions.items():
        auc = roc_auc_score(y_test, preds["y_proba"])
        roc_aucs.append((name, auc, preds["y_proba"]))

    roc_aucs = sorted(roc_aucs, key=lambda x: x[1], reverse=True)[:top_n]

    colors = plt.cm.tab10(np.linspace(0, 1, top_n))

    for (name, auc, y_proba), color in zip(roc_aucs, colors):
        fpr, tpr, _ = roc_curve(y_test, y_proba)
        ax.plot(fpr, tpr, label=f"{name} (AUC = {auc:.3f})", color=color, linewidth=2)

    # Diagonal line (random classifier)
    ax.plot([0, 1], [0, 1], "k--", linewidth=1, label="Random (AUC = 0.500)")

    ax.set_xlabel("False Positive Rate")
    ax.set_ylabel("True Positive Rate")
    ax.set_title(f"ROC Curves - Top {top_n} Models")
    ax.legend(loc="lower right")
    ax.grid(True, alpha=0.3)

    plt.tight_layout()
    plt.savefig(output_dir / "roc_curves.png", dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {output_dir / 'roc_curves.png'}")


def plot_confusion_matrices(
    classifiers: Dict[str, object],
    predictions: Dict,
    y_test: np.ndarray,
    output_dir: Path,
    top_n: int = 4,
) -> None:
    """Plot confusion matrices for top N models."""
    # Get top N by F1 score
    f1_scores = []
    for name, preds in predictions.items():
        f1 = f1_score(y_test, preds["y_pred"], zero_division=0)
        f1_scores.append((name, f1))

    top_models = sorted(f1_scores, key=lambda x: x[1], reverse=True)[:top_n]

    fig, axes = plt.subplots(2, 2, figsize=(12, 10))

    for ax, (name, _) in zip(axes.flat, top_models):
        y_pred = predictions[name]["y_pred"]
        cm = confusion_matrix(y_test, y_pred)

        disp = ConfusionMatrixDisplay(cm, display_labels=["No", "Yes"])
        disp.plot(ax=ax, cmap="Blues", colorbar=False)
        ax.set_title(f"{name}")

    plt.suptitle("Confusion Matrices - Top Models", fontsize=14)
    plt.tight_layout()
    plt.savefig(output_dir / "confusion_matrices.png", dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {output_dir / 'confusion_matrices.png'}")


def plot_feature_importance(
    classifiers: Dict[str, object],
    feature_names: List[str],
    output_dir: Path,
) -> None:
    """Plot feature importance for tree-based models."""
    # Models with feature_importances_
    tree_models = ["RandomForest", "ExtraTrees", "GradientBoosting", "DecisionTree"]
    available_models = [m for m in tree_models if m in classifiers]

    if not available_models:
        return

    fig, axes = plt.subplots(2, 2, figsize=(14, 10))

    for ax, model_name in zip(axes.flat, available_models):
        clf = classifiers[model_name]

        if hasattr(clf, "feature_importances_"):
            importances = clf.feature_importances_
            indices = np.argsort(importances)

            ax.barh(range(len(indices)), importances[indices], color="steelblue", alpha=0.8)
            ax.set_yticks(range(len(indices)))
            ax.set_yticklabels([feature_names[i] for i in indices])
            ax.set_xlabel("Importance")
            ax.set_title(f"{model_name}")

    plt.suptitle("Feature Importance (Tree-Based Models)", fontsize=14)
    plt.tight_layout()
    plt.savefig(output_dir / "feature_importance.png", dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {output_dir / 'feature_importance.png'}")


# =============================================================================
# Main
# =============================================================================

def main() -> None:
    """Main function for model selection and evaluation."""
    print("=" * 60)
    print("3D Object Classification - Model Selection")
    print("=" * 60)

    # Create output directory
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    # Step 1: Load Dataset
    print("\n[1/5] Loading Dataset...")
    df, X, y = load_dataset(DATA_PATH)

    # Step 2: Get all classifiers
    print("\n[2/5] Initializing Classifiers...")
    classifiers = get_classifiers()
    print_classifiers_summary(classifiers)

    # Step 3: Train-Test Split
    print("\n[3/5] Splitting Data...")
    X_train, X_test, y_train, y_test = split_data(X, y)

    # Step 4: K-Fold Cross-Validation
    print("\n[4/5] Running K-Fold Cross-Validation...")
    df_cv = train_with_kfold(classifiers, X_train, y_train)

    print("\n" + "-" * 60)
    print("CROSS-VALIDATION RESULTS (sorted by mean accuracy)")
    print("-" * 60)
    print(df_cv[["Classifier", "CV_Mean", "CV_Std"]].to_string(index=False))

    # Step 5: Evaluate on Test Set
    print("\n[5/5] Evaluating on Test Set...")
    df_metrics, predictions = evaluate_all_models(
        classifiers, X_train, X_test, y_train, y_test
    )

    print("\n" + "-" * 60)
    print("TEST SET METRICS (sorted by F1 Score)")
    print("-" * 60)
    print(df_metrics.to_string(index=False))

    # Generate Plots
    print("\n" + "=" * 60)
    print("GENERATING EVALUATION PLOTS")
    print("=" * 60)

    plot_cv_results(df_cv, OUTPUT_DIR)
    plot_metrics_comparison(df_metrics, OUTPUT_DIR)
    plot_roc_curves(predictions, y_test, OUTPUT_DIR)
    plot_confusion_matrices(classifiers, predictions, y_test, OUTPUT_DIR)
    plot_feature_importance(classifiers, FEATURE_COLUMNS, OUTPUT_DIR)

    # Save results to CSV
    df_cv.to_csv(OUTPUT_DIR / "cv_results.csv", index=False)
    df_metrics.to_csv(OUTPUT_DIR / "test_metrics.csv", index=False)
    print(f"\nSaved CSV results to: {OUTPUT_DIR}")

    # Print best model
    best_model = df_metrics.iloc[0]["Classifier"]
    best_f1 = df_metrics.iloc[0]["F1_Score"]

    print("\n" + "=" * 60)
    print("BEST MODEL")
    print("=" * 60)
    print(f"  {best_model}")
    print(f"  F1 Score: {best_f1:.4f}")

    # Print classification report for best model
    print("\n" + "-" * 60)
    print(f"Classification Report - {best_model}")
    print("-" * 60)
    y_pred_best = predictions[best_model]["y_pred"]
    print(classification_report(y_test, y_pred_best, target_names=["No (not chair)", "Yes (chair)"]))


if __name__ == "__main__":
    main()