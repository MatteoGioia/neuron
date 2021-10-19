# Linear regression

## Recall questions
    - wip

## Linear Regression

### Definition of the problem

Linear regression is a supervised learning problem. The output is a continous function so it's a regressor.

Hypotesis (one var):

![](./static/FDS/hyp.png)

==Multivariate:==

![](./static/FDS/hyp2.png)

### ==Notation==

![](./static/FDS/regnotation.png)

### Gradient descent

To minimise the cost function we can use gradient descent.

![](./static/FDS/gd.png)

It's important to choose $\alpha$ so that it is:
- not too small, because descent will be low
- not too large, because there is the risk of not converging or diverging

Remember that gradient descent follows an orthogonal direction compared to the ellipses..

### Batch gradient descent (and mini batch)

### Normalisation

### Mean normalisation

### More on the learning rate

### Polynomial regression