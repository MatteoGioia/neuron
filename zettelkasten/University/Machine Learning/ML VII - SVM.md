# Support Vector Machine

## Recall questions
        - WIP

## Linear SVM

SVM can learn an arbitrary function $f$ of $x$. It can be linear, like ...

This function can be expressed as

### Classification 

The classification function is:

>$f(x,w,b) = sign(w^T x + b) = y$

...

The issue with a simple linear function is that we have infinitely possible solutions. To choose the best one, we focus on a line that is exactly in between the ==uncertainty area==.

The optimization problem then becomes classifying the instances and choosing the line that maximizes the margin.  

### Functional margin and Geometric Margin

...

However, since the functional margin is ..., we use the geometric margin instead that is ...

### Maximising the geometric margin

...

### Optimization problem and the Lagrangian


### Working example


### Overfitting and Soft margins

Sacrificing accuracy on the training data to allow for better generalization


## Non linear SVM

### Non linear kernels