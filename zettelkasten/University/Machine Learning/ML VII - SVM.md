# Support Vector Machine

## Recall questions
        - WIP

## Linear SVM

A support vector machine is a discriminative classifier formally defined by a separating hyperplane.
Given labelled training data, the algorithm outputs an optimal hyperplane that categorizes new examples.

SVM can learn an arbitrary function $f$ of $x$. It can be linear, like perceptron, but also non linear like NN.
In the following, we'll first examine the linear case and then the non-linear case.

### Classification 

The classification function is:

>$f(x,w,b) = sign(w^T x + b) = y$
>- $sign() > 0$ positive classification
>- $sign() < 0$ negative classification
>- $sign() = 0$ no classification

![](./static/ML/svm1.png)

The issue with a simple linear function is that we have infinitely possible solutions. To choose the best one, we focus on a line that is exactly in between the ==uncertainty area==.

The optimization problem then becomes classifying the instances and choosing the line that maximizes the margin.  

### Functional margin and Geometric Margin

We define a margin as the width that the boundary could be increased by before hitting a data point in the learning set.

![](./static/ML/svm2.png)

One margin we can consider is the so called functional margin, defined, for a training example vector $x_i$ in the training set $D$ as:

>$fm(x_i) = y_i (w^T x_i + b)$

It's easy to see that:
- $fm(x_i) > 0$ means a correct prediction, since both $y_i$ and $w^T x_i + b$ have the same sign
- $fm(x_i) >> 0$ also means that our prediction has high confidence

However, since the functional margin is not scale invariant, we can make it as large as we want just muplying $w,b$ for a constant. For this reason, we use the geometric margin, that is instead scale invariant:

>$gm(x_i) = \frac{|(\sum_i w_i x_i) + b|}{\sqrt{\sum_i w_i^2}} = \frac{|w^T \cdot x_i + b|}{\| w \|}$

### Maximising the geometric margin

In order to maximise the margins, we are going to use special vectors called support vectors. Consider 2 vectors right on the margin, called $x^+$ and $x^-$ and scale them accordingly s.t. 

>$H_1 = w^T x^- + b = 1$

>$H_2 = w^T x^+ + b = - 1$

![](./static/ML/svm3.png)

Given what was previously said about classification, it is then true that:

> (1) an instance is positive if $y = w^T x + b \geq 1$

> (2) an instance is negative if $y = w^T x + b \leq 1$

This is true, by construction, only for SV. We can also note that

> $distance(H_1, H) = \frac{|w^T \cdot x^+ + b}{\| w \|} = \frac{1}{\| w \|}$

> $distance(H_1, H_2) = 2 \frac{1}{\| w \|} = \frac{2}{\| w \|}$

### Optimization problem and the Lagrangian

Our optimization problem can be written as 

>maximize $\frac{2}{\| w \|}$ s.t. $y(w^T x + b) \geq 1$ (compact form of 1 and 2)

or equivalently

>minimize $\frac{1}{2} \|w \|^2$ s.t. $y(w^T x + b) \geq 1$ 

We can use the lagrangian method to build the constraint in the formula

>minimize $L_p (w, b,\alpha_i) = \frac{1}{2} \|w \|^2 - \sum_{i = 1}^{n} \alpha_i (y_i(w^T x_i + b) - 1)$ s.t. $\alpha_i \geq 0$

<small> $L(x,\alpha) = f(x) - \sum \alpha_i c_i (x)$ where $c_i$ are the constraints </small>

The ==Karush-Kuhn-Tucker conditions== (KKT) tell us that the optimum is a point where:
1. $\nabla f(x) - \sum \alpha_i \nabla c_i (x) = 0$
2. $\alpha_i \geq 0$
3. $\alpha_i c_i (x) = 0 \space \forall i$ - a.k.a. complementary condition: at least one of $a_i$,$c_i$ must be zero

The "issue" is that we do not know the weights $w_i$ or $b$. We'd like to find an alternative formulation, where only known terms appear. To do so, we can use to the dual of the original problem:

>$maximize $\sum_{i=1}^n \alpha_i - \frac{1}{2} \sum_{i = 1}^n \sum_{j=1}^n \alpha_i \alpha_j y_i y_j x_{i}^T x_j$ s.t. $\alpha_i \geq 0$ and $\sum_{i=1}^n \alpha_i y_i = 0$ 

It must also be said that only data points on the margin, so the SV themselves, will have a non-zero $\alpha$, since they are the only ones for which $y_i(w^T x_i + b) - 1 = 0$. 
- for non support vectors $y_i(w^T x_i + b) \geq 1$ so, for 3, $\alpha_i$ must be 0

<small> for the detailed steps, refer to the paper notes or the original slides </small> 

### Working example


### Overfitting and Soft margins

Sacrificing accuracy on the training data to allow for better generalization


## Non linear SVM

### Non linear kernels