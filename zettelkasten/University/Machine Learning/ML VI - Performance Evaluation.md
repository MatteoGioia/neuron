# Performance Evaluation and Hypotesis Testing

## Recall questions
        - What is a necessary prerequisite for measuring performance? What do we have to always keep in mind?
        - What are the measures for classifiers? Explain what are the ROC, AUROC and PR-curve and why they are useful.
        - Why it is important to understand where errors come from before actually trying to see if our estimates are accurate?
        - What is bias? Descrive the most common tpyes.
        - What is variance? Can we always deal with it?
        - How can estimate how precise is our estimate of the error of a model? Answer reviewing the Excursus.
        - How can we compare 2 different hyp? What are the 2-tailed and 1-tailed tests?
        - What is KFV?

## Choosing the right performance measure

==Performance can be only evaluated when we have a ground truth==, since we can evaluate the error with a performance measure.

When evaluating, we have to use the ==right measure:==
- for classifiers the error function is binary: either the class is right or it is wrong
- for regressors we can take into account the distance between the predicted value and the ground truth

It is important to remember that ==the learnt function, a.k.a the hypotesis, can only be compared to an approximation of the *real* function.==
- the ==real data distribution is often slightly different==

### Measures for classifiers

>$error(h(x)) = \sum_{i=1}^{n} \delta(c(x_i), h(x_i))$ 

$\delta$ is a Kronecker function:
- $\delta(x,y) = 0 \iff x==y$
- $\delta(x,1) = 1$ otherwise

Another easy way to visualize results (ADD ALL THE MEASURES):

![](../../..//ML/contingency.png)

Also useful:
- F score = $2 \frac{Precision \cdot Recall}{Precision + Recall}$
- Error rate = 1 - Accuracy
- False Positive Rate = $\frac{FP}{FP + TN}$
- False Negative Rate = $\frac{FN}{FN + TP}$

==Receiver Operator Curve: plot of Positive Recall and False Positive Rate, at various system settings.==

![](../../..//ML/roc.png)

The ==Area Under the ROC can also be used too see the performance of our model. The closer it is to 1, the better our model is.==

The AUROC is also ==useful for measuring the uncertainty area, which tells us when our prediction is reliable and when, instead, the prediction could be inaccurate.==

![](../../..//ML/uncertainty.png)

==PR-curve: graph of Recall and Precision at various system settings. It is generally better for imbalanced problems, since Precision is highly sensitive to FP but it is not impacted by a total TN denominator.==

### Measure for regressors

==Mean Absolute Error (MAE): $\frac{1}{n} \sum_{i = 1}^{n} |f(x_i) - h(x_i)|$==

==Root Mean Squared Error (RMSE): $\sqrt{\frac{1}{n}(\sum_{i=1}^{n} (f(x_i) - h(x_i))^2}$==

==Residual Sum of Squares (RSS): $(\sum_{i=1}^{n} (f(x_i) - h(x_i))^2$==

## Accuracy of estimation

The ==goal of creating a ML model is being able to generalize over unseen instances.==
If we are not able to do so, our hypotesis will produce errors.

>Total Error = Bias$^2$ + Variance + Irreducible Error

Our goal is the ==finding a good balance in minimising both Bias and Variance, since Irreducible error is mostly due to the inherent complexity of the model.==

### Bias

==Bias is the average of the difference between the predicted values and the actual results. It originates from wrong assumptions of various types in the learning model.==

>$Bias^2=(E[h(x)] - f(x))^2$ where $E[h(x)]$ is the expected value (mean) of the hypotesis $h(x)$

For instance, ==bias in the model== could be due to the assumption that the real function is linear.

![](../../..//ML/bias1.png)

The ==main causes for bias in the data are==:
- ==sample bias==: collected data is not representative, e.g. face recognition algorithm trained with white people faces only
- ==exclusion bias==: relevant features are excluded 
- ==prejudice bias==: the data represented in the model is influenced by prejudice
- ==measurement bias==: the feature values are impacted by the measuring tool (e.g. photos shoot with a camera that reduces brightness)

### Variance

==Variance is defined as the mean of squared differences between values of $N$ individual outcomes $x_i$ and the mean (x), i.e. the dispersion around the mean.==

>$\sigma^2 = var(x) = \frac{\Sigma_{i=1}^{N}(x_i - \overline{x})^2}{N}$

Variance ==can't be reduced if it is inherent in our dataset==, but there are ways to ==deal with it:==
- ==train different models, like in ensambles==
- ==use validation techniques that reduce the possibility of being unlucky==

==K-Fold Cross-Validation== or KFV in short is an example of the latter strategy:

![](../../..//ML/kfv.png) 

### ==Estimators and errors==

==See [[An excursus about statistics]]#==

<small> Note: the following notes <b>require</b> reading the excursus or at least having a decent knowledge of probability and statistics. </small> 

### Comparing two learned hypotesis

>**Q2**: Given that one hypothesis $h_1$ outperforms another hypotesis $h_2$over some sample data $S$, how probable is it that this hypothesis is more accurate in general?

To ==decide wheter or not an alternative hypotesis is better than the one we have, we need to list the alternatives==.
One of the alternatives is called Null Hypotesis $h_0$ and it's usually used to disconfirm our findings.

Suppose we find that the error rate of $h_1$ and $h_2$ is different and the difference $d = error_{S_1} (h_1) - error_{S_2} (h_2) \neq 0$. We can perform 3 tests:
- 2-tailed test
- one tailed right test
- one tailed left test

### Two tailed test

We ==formulate and test 2 alternatives:==
1. ==$h_0$ : data does not support that $h_1 \neq h_2$== 
2. ==$h_1$ : data supports that $h_1 \neq h_2$==

We wish to estimate the real difference $d_D$ between the unknown true errors of the 2 hypotesis. Again, the true errors are unknow, so we need some kind of estimator! We use $d_S$ as an unbiased estimator for $d_D$.

>$d_S = error_{S_1} (h_1) - error_{S_2} (h_2)$

To obtain a conf. interval, we need again to compute the std. deviation. We can exploit the fact that the difference of gaussians still follows a gaussian distribution!

>$\sigma_{d_S} = \sqrt{VAR(d_S)} \approx \sqrt{\frac{error_{S_1} (h_1) \cdot (1 - error_{S_1} (h_1))}{n_1} + \frac{error_{S_2} (h_2) \cdot (1 - error_{S_2} (h_2))}{n_2}}$

If the null hyp. holds true, we must have that:

> $error_D (h_1) = error_D(h_2) \implies d_D = 0$

So we need to test the likelihood of $h_0$: 

![](../../..//ML/comparison1.png)

==If in our calculations the area lies in the non critical region, usually $N \leq 95\%$ ($-2\sigma, +2\sigma)$, the Null Hyp. is accepted and the real difference is negligible.==

In simpler terms, ==we can conclude that there is no difference only when the probability of having observed value $d_S$ if $d_D = 0$ is high enough. Otherwise, we must reject $h_0$.==

In practice, ==if the $p$-value, which is the probability of observing our estimate if $h_0$ holds, is $p < 0.05$ then we reject $h_0$.==

### One tailed test

==Right test ($d > 0$):==
- $h_0$ data does not support that $h_2 > h_1$
- $h_1$ data support $h_2 > h_1$, so $h_1$ has significantly lower error

==Left test ($d < 0$):==
- $h_0$ data does not support that $h_2 < h_1$
- $h_1$ data support $h_1 > h_2$, so $h_1$ has significantly higher error

![](../../..//ML/onetail1.png)

Example:

![](../../..//ML/onetail2.png)

### Comparing 2 learning algorithms

We want to measure $E_{S \subset D} (error_D (L_A(S)) - error_D (L_B(S)))$, where $L_x(S)$ represents the hyp. learnt by algorithm $L_x$ from training data $S$.

To do so, ==we have to average over multiple, indipendent training and test sets. One possible technique is K-Fold Cross Validation==:

![](../../..//ML/kfv2.png)

KFV improves confidence in our estimate of $\delta$ since it is computed as an average of $\delta_i$.