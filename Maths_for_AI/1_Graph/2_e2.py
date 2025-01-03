import numpy as np
import plotly.graph_objects as go


class ExpGraph:
    def __init__(self, x_range=(-2, 2), num_points=500, specific_points=None):
        self.x = np.linspace(x_range[0], x_range[1], num_points)
        self.y = np.exp(self.x)
        self.specific_points = specific_points or [-2, -1, 0, 1, 2]
        self.specific_y = np.exp(self.specific_points)
        self.figure = go.Figure()

    def add_curve(self):
        """Add the exponential curve to the plot."""
        self.figure.add_trace(
            go.Scatter(
                x=self.x,
                y=self.y,
                mode="lines",
                name="y = e^x",
                line=dict(color="green"),
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
            title="Interactive Graph of y = e^x",
            xaxis_title="x",
            yaxis_title="y",
            template="plotly_white",
            showlegend=True,
            hovermode="x unified",
        )

    def show(self):
        """Display the graph."""
        self.figure.show()


# Instantiate and use the ExpGraph class
if __name__ == "__main__":
    exp_graph = ExpGraph()
    exp_graph.add_curve()
    exp_graph.add_specific_points()
    exp_graph.configure_layout()
    exp_graph.show()
