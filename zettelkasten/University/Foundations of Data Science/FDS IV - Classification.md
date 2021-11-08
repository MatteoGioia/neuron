# Classification and more

## Recall questions
        - WIP

## Logistic Regression 

In logistic regression, we use the same model as normal regression but with a twist. Since we are interested in classification, we output a value between 0 and 1. If such value is over a threshold, we then output a positive classification.

To achieve this result, our new hyp. is:

>$h_\theta (x) = g (\theta^T x)$
 
where the $g(z)$ fuction is the sigmoid function (or logistic function)

>$g(z) = \frac{1}{1 - e^{-z}}$

In the following, we will see how to ouput models able to:
- create linear decision boundaries 
- create non linearly separable decision boundaries 

### Gradient ascent in Logistic Regression

One way to calculate $\theta$ is to use gradient ascent. The logic is similar to the one of gradient descent, although now we need to maximise the log likelihood function.

Keep also in mind that, in this case, we assume our RV is a bernoulli (classification is either correct or not).

![](./static/FDS/lr1.png)

Gradient update equation (see notebook for full derivation):

![](./static/FDS/lr2.png)

### Newton's method for Logistic Regression

There is an alternative method to compute the best value for $\theta$ that, although more complex, is also faster at convergence. This method is Newton's method.

## Exponential Models

We can prove that the distributions we analyzed till now are all part of the family of exponential distribution:

>exp...

### Properties of exponential models

All the models of the exponential family of distributions have some property in common

## Generalized linear models

We can create a general algorithm to tackle data assumed to be from a distribution from the exponential family...

## Multiclass classification

