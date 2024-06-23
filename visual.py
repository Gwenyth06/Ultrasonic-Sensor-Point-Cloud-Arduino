import plotly.graph_objs as go
from plotly.offline import plot

# Read points from file
points = []
with open("points.txt", "r") as file:
    for line in file:
        x, y, z = map(float, line.strip().split(','))
        points.append((x, y, z))

xs, ys, zs = zip(*points)

# Create a 3D scatter plot using Plotly
scatter = go.Scatter3d(
    x=xs,
    y=ys,
    z=zs,
    mode='markers',
    marker=dict(
        size=5,
        color='red',
    )
)

layout = go.Layout(
    scene=dict(
        xaxis_title='X Label',
        yaxis_title='Y Label',
        zaxis_title='Z Label'
    )
)

fig = go.Figure(data=[scatter], layout=layout)

# Save the Plotly figure as an HTML file
plot(fig, filename='3d_plot.html')
