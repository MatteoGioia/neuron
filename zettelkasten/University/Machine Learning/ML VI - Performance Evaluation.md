# Performance Evaluation and Hypotesis Testing

## Recall questions
        -WIP

## Choosing the right performance measure

...

When evaluating the performance of ML system we must also use the appropriate measure:
- for classifiers, since the prediction is
- for regressors

When measuring the performance of a model we can only compare it to an approximation of the *real* function. In fact, we only have the dataset to use as ground truth and we can't really know the real distribution of the data.

### Measures for classifiers

To measure error on a classifier, we can use a Kronecker function: ...

We can also distinguish the type of error our system does (summarized in contingency table):
- TP or true positive
- TN or true negative
- FP or false positive
- FN or false negative

![](./static/ML/contingency.png)

F score (also add error rate and correct label for correct pic)

There are also advanced ways of visualizing the results through graphs. One of the is the ROC..

AUROC is also useful for measuring the uncertainty area

PR-curve 

Learning curve

### Measure for regressors

MAE

RMSE

RSS

## Accuracy of estimation

.....
But before doing this, we need to understand why these errors are present in the first place.

### The reasons behind errors

Total Error = Bias$^2$ + Variance + Irreducible Error

Bias data () and bias in algorithm