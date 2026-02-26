import numpy as np
import plotly.graph_objects as go
# changes

class LogGraph:
    def __init__(self, x_range=(0.1, 10), num_points=500, specific_points=None):
        self.x = np.linspace(x_range[0], x_range[1], num_points)
        self.y = np.log(self.x)
        self.specific_points = specific_points or [0.1, np.e, 1, 2, 3]
        self.specific_y = np.log(self.specific_points)
        self.figure = go.Figure()

    def add_curve(self):
        """Add the logarithmic curve to the plot."""
        self.figure.add_trace(
            go.Scatter(
                x=self.x,
                y=self.y,
                mode="lines",
                name="y = log(x)",
                line=dict(color="blue"),
            )
        )

    def add_specific_points(self):
        """Add specific points to the plot."""
        self.figure.add_trace(
            go.Scatter(
                x=self.specific_points,
                y=self.specific_y,
                mode="markers+text",
                name="Specific Points",
                text=[
                    f"({xi:.1f}, {yi:.2f})"
                    for xi, yi in zip(self.specific_points, self.specific_y)
                ],
                textposition="top center",
                marker=dict(color="red", size=8),
            )
        )

    def configure_layout(self):
        """Update the layout of the plot."""
        self.figure.update_layout(
            title="Interactive Graph of y = log(x)",
            xaxis_title="x",
            yaxis_title="y",
            template="plotly_white",
            showlegend=True,
            hovermode="x unified",
        )

    def show(self):
        """Display the graph."""
        self.figure.show()


# Instantiate and use the LogGraph class
if __name__ == "__main__":
    log_graph = LogGraph()
    log_graph.add_curve()
    log_graph.add_specific_points()
    log_graph.configure_layout()
    log_graph.show()
