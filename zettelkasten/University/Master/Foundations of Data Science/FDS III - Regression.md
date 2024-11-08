# Regression

## Recall questions
    - What is linear regression? Why do we use gradient descent? 
    - What is alpha in gradient descent? Why it is important to choose an alpha of the right "size"?
    - What is batch gradient descent? Why is mini batch better?
    - What is normalization? Why is it important to normalize feature values before applying descent algorithms?
    - What is polynomial regression? What is the normal equation and what are the downsides/upsides compared to gd?
    - What are correlation/causation?
    - What is lowess?
    - Show how MLE and gradient descent are linked.

## Linear Regression

Linear regression is a supervised learning problem. The output is a continous function so it's a regressor.

Hypotesis (one var):

![](../../../static/FDS/hyp.png)

==Multivariate:==

![](../../../static/FDS/hyp2.png)

### ==Notation==

![](../../../static/FDS/regnotation.png)

### Gradient descent

To minimise the cost function we can use gradient descent.

![](../../../static/FDS/gd.png)

It's important to ==choose $\alpha$ so that it is:==
- ==not too small==, because descent will be low
- ==not too large==, because there is the risk of not converging or diverging

There is also no need to decrease alpha because gradient descent "automatically" takes smaller steps at each iteration.

Remember that gradient descent follows an ==orthogonal direction compared to the ellipses.==

### Batch gradient descent (and mini batch)

At each step of gradient descent, only ==one instance of the dataset is used to calculate the next step (markvov/stochastic):==

![](../../../static/FDS/batchpseudo.png)

The issue with this type of descent is that the ==descent pattern might no be so smooth==. Because of this, ==mini-batch gradient descent is actually used and a certain number of instances are used for each step.==
- it also is usually faster thanks to vectorization libraries

### Gradient descent with multiple features

![](../../../static/FDS/gdmulti2.png)

### Normalisation

==Having features on the same scale ensures that the gradient descent is smooth and doesn't "zig-zag" his way to the center:==

![](../../../static/FDS/zigzag.png)

The ==goal of normalization is to get features into approximately a $-1 \leq x_i \leq 1$ range==. To do so, we can apply mean normalization: $x_i = \frac{x_i - \mu_i}{s_j}$
- where $\mu_i$ is the mean value of the $i-th$ feature
- and $s_j$ is the range or standard deviation of the feature (calculated as max - min feature value)

## Polynomial regression

When dealing with more complex predictions, a linear combination of the feature values is often not enough. To deal with this, we can use more complex functions.
- e.g. $h_{\theta} = \theta_0 + \theta_1 x_1 + \theta_2 x_{2}^{2} + \theta_3 \sqrt{x_{3}}$

### Normal equation

The ==normal equation comes from the idea of trying to minimise the cost function expressed as a bidimensional matrix.==

>Normal equation $X^T X \theta = X^T \overline{y} \to \theta^{*} = (X^T X)^{-1} X^T \overline{y}$

But ==when to use the normal equation $\Theta(n^3)$ and when to use gradient descent?==

![](../../../static/FDS/gdvsne.png)

If $X^T X$ it's not invertible we can:
- remove redunant features, that are often linearly dependent (e.g. one is the linear combination of another)
- delete some of them, or use regularization

## MSE and Correlation

==Correlation: values track each other==
- positively, so they both "go up"
- negatively, if one "goes up" and the other "goes down"

==Causation: one value directly influences another one==

Two ==methods of measuring correlation:==
- ==pearson's product moment correlation==: 1 max. positive, 0 no corr., -1 max negative
- ==coefficient of determination== aka $r^2$: between 0 and 1, measures fit of any line curve to set of points, for simple linear regression is equal to Pearson$^2$

## Locally weighted regression

This type of regression is a non parametric learning algorithm, meaning that
the parameters grow with the data.

It is also called Loess or Lowess.

### Fitting best local curve

![](../../../static/FDS/lowess.png)

## Probabilistic interpretation of least squares

See slides. Also see probability theory review!!!