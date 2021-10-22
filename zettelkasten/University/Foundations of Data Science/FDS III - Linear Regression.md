# Linear regression

## Recall questions
    - wip

## Linear Regression

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

There is also no need to decrease alpha because gradient descent "automatically" takes smaller steps at each iteration.

Remember that gradient descent follows an orthogonal direction compared to the ellipses.

### Batch gradient descent (and mini batch)

At each step of gradient descent, only one instance of the dataset is used to calculate the next step (markvov/stochastic):

![](./static/FDS/batchpseudo.png)

The issue with this type of descent is that the descent pattern might no be so smooth. Because of this, mini-batch gradient descent is actually used and a certain number of instances are used for each step.
- it also is usually faster thanks to vectorization libraries

### Gradient descent with multiple features

### Normalisation

Having features on the same scale ensures that the gradient descent is smooth and doesn't "zig-zag" his way to the center:

..

To normalise, we can apply mean normalization


### More on the learning rate

## Polynomial regression

When dealing with more complex predictions, a linear combination of the feature values is often not enough. To deal with this, we can use more complex functions:

### Normal equation