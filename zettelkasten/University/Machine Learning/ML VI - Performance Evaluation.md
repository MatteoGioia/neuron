# Performance Evaluation and Hypotesis Testing

## Recall questions
        - What is a necessary prerequisite for measuring performance? What do we have to always keep in mind?
        - What are the measures for classifiers? Explain what are the ROC, AUROC and PR-curve and why they are useful.
        - Why it is important to understand where errors come from before actually trying to see if our estimates are accurate?
        - What is bias? Descrive the most common tpyes.

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

![](./static/ML/contingency.png)

Also useful:
- F score = $2 \frac{Precision \cdot Recall}{Precision + Recall}$
- Error rate = 1 - Accuracy
- False Positive Rate = $\frac{FP}{FP + TN}$
- False Negative Rate = $\frac{FN}{FN + TP}$

==Receiver Operator Curve: plot of Positive Recall and False Positive Rate, at various system settings.==

![](./static/ML/roc.png)

The ==Area Under the ROC can also be used too see the performance of our model. The closer it is to 1, the better our model is.==

The AUROC is also ==useful for measuring the uncertainty area, which tells us when our prediction is reliable and when, instead, the prediction could be inaccurate.==

![](./static/ML/uncertainty.png)

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

![](./static/ML/bias1.png)

The ==main causes for bias in the data are==:
- ==sample bias==: collected data is not representative, e.g. face recognition algorithm trained with white people faces only
- ==exclusion bias==: relevant features are excluded 
- ==prejudice bias==: the data represented in the model is influenced by prejudice
- ==measurement bias==: the feature values are impacted by the measuring tool (e.g. photos shoot with a camera that reduces brightness)

### Variance

Variance is defined as the mean of squared differences between values of $N$ individual outcomes $x_i$ and the mean (x), i.e. the dispersion around the mean.

...

Variance can't be reduced if it is inherent in our dataset, but there are ways to deal with it:
- train...
- validation...

### Estimators and errors

See [[An excursus about statistics]]#