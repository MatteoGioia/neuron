# Support Vector Machine

## Recall questions

### Linear SVM   

- What is a linear SVM? What types of functions can it learn?

- What is the classification function? Why is it hard to find?

- How do we find the best separating line? What is the new version of the optimization problem?

- What is the functional margin? Why do we prefer to use the geometric margin instead?

- How can we use the support vector to find the best geometric margin? Describe the optimisation problem and how to solve it.

- Why it is easy to classify new instances once we have the support vectors? 

- Dot products and Linear Kernels...why do they matter? Why are SVs a "function of similarity"?

- What is the issue of linear SVMs and how can we address it? What is the new version of the optimisation problem?

- What is another way of dealing with non linearly separable data, using non linear kernels?

- What are the weaknesses and the issues of SVMs?

## Linear SVM

A support vector machine is a ==discriminative classifier formally defined by a separating hyperplane.==
Given labelled training data, ==the algorithm outputs an optimal hyperplane that categorizes new examples.==

SVM ==can learn an arbitrary function $f$ of $x$. It can be linear, like perceptron, but also non linear like NN.
In the following, we'll first examine the linear case and then the non-linear case.==

### Classification 

The ==classification function is:==

>$f(x,w,b) = sign(w^T x + b) = y$
>- $sign() > 0$ positive classification
>- $sign() < 0$ negative classification
>- $sign() = 0$ no classification

![](../../..//ML/svm1.png)

The issue with a simple linear function is that ==we have infinitely possible solutions==. To choose the best one, we focus on a line that is exactly in between the ==uncertainty area==.

The optimization problem then becomes ==classifying the instances and choosing the line that maximizes the margin.==  

### Functional margin and Geometric Margin

We define a ==margin as the width that the boundary could be increased by before hitting a data point in the learning set==.

![](../../..//ML/svm2.png)

One margin we can consider is the so called ==functional margin, defined, for a training example vector $x_i$ in the training set $D$ as:==

>$fm(x_i) = y_i (w^T x_i + b)$

It's easy to see that:
- $fm(x_i) > 0$ means a correct prediction, since both $y_i$ and $w^T x_i + b$ have the same sign
- $fm(x_i) >> 0$ also means that our prediction has high confidence

However, since the ==functional margin is not scale invariant, we can make it as large as we want just muplying $w,b$ for a constant==. For this reason, we use the ==geometric margin, that is instead scale invariant:==

>$gm(x_i) = \frac{|(\sum_i w_i x_i) + b|}{\sqrt{\sum_i w_i^2}} = \frac{|w^T \cdot x_i + b|}{\| w \|}$

### Maximising the geometric margin

In order to maximise the margins, ==we are going to use special vectors called support vectors==. Consider 2 vectors right on the margin, called $x^+$ and $x^-$ and scale them accordingly s.t. 

>$H_1 = w^T x^- + b = 1$

>$H_2 = w^T x^+ + b = - 1$

![](../../..//ML/svm3.png)

Given what was previously said about classification, it is then true that:

> (1) an instance is positive if $y = w^T x + b \geq 1$

> (2) an instance is negative if $y = w^T x + b \leq -1$

This is true, by construction, only for SV. We can also note that

> $distance(H_1, H) = \frac{|w^T \cdot x^+ + b}{\| w \|} = \frac{1}{\| w \|}$

> $distance(H_1, H_2) = 2 \frac{1}{\| w \|} = \frac{2}{\| w \|}$

### Optimization problem and the Lagrangian

Our ==ptimization problem can be written as==

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

Given what we have said so far, the dual problem (lagrangian becomes):

>find $\alpha_1, \ldots, \alpha_i$ s.t. $Q(\alpha) = \sum_i \alpha_i - \frac{1}{2} \sum_{i,j = 1}^n \alpha_i \alpha_j y_i y_j x_{i}^T x_j$ is maximised and
>1. $\sum_i \alpha_i y_i = 0$
>2. $\alpha_i \geq 0 \space \forall \alpha_i$, but the equality with 0 is true only for support vectors 

Both the original formulation and the dual are system of inequalities and can be solved with quadratic programming. 

Once we solve the lagrangian, the solution to the primal is:

>$w = \sum_i \alpha_i y_i x_i$ and $b = y_k - \sum_i \alpha_i y_i x_{i}^T x_k$ for any $\alpha_k > 0$

We don't need to compute $w$ explicitely though. Once we solve the problem, the classification function is the sign of:

>$\Phi(x) = \sum_i \alpha_i y_i x{i}^T x+ b$ where $x_i$ are the support vectors

So ==we only need to do the dot product of the 2 vectors to know to which class the instance belong.== The bad news is that, in order to solve the optimisation problem, we need to compute the dot product $x_{i}^T x_k$ between all training points.

<small> for the detailed steps, refer to the paper notes </small> 

It is also relevant that ==inner dot products are part of the kernel functions, in particular they are a linear kernel. In fact, the dot product is a similarity function of 2 vectors!==

>$sim(x_i, x_k) = \frac{x_{i}^T \cdot x_k}{|x_i||x_k|} = \cos \theta$

![](../../..//ML/svm4.png)


### Overfitting and Soft margins

As said before, ==data in real life is rarely perfectly linearly separable==. This means that even in cases where a linear (?) hyperplane is enough to predict the value of new instances, sometimes allowing for some slack in the optimisation function leads to better results:

>$\frac{1}{2} \| w \|^2 + C$ where $C =$ # of mistakes (HYPERPARAMETER!!)

To do so, ==we introduce a slack variable $\xi$, that is the distance of $x_i$ from the corresponding's class margin if $x_i$ is on the wrong side, otherwise 0. Points that are far away from the right margin get a bigger penalty:==

>$y_i(w^T x_i + b) \geq 1 - \xi_i$ where $\xi_i = max(0, y_i(w^T \cdot x_i + b))$

![](../../..//ML/svm5.png)

In the image, for example, if $1 - \xi_i$ in the left side is bigger or equal to 1 then the classification is correct, otherwise if it negative the classification is wrong and we add a penalty. 

The ==new optimisation problem becomes:==

>minimize $\frac{1}{2} \|w\|^2 + C \sum_{i=1}^n \xi_i$ s.t. $y_i(w^T x_i + b) \geq 1 - \xi_i$ where $\xi_i \geq 0$

This means that ==the slack variable allows an example in the margin $0 \leq \xi_i \leq 1$ to be misclassified, otherwise if $\xi_i > 1$ it treats it as an error.==

Incorporating the costraints (lagrangian):

>minimize $\frac{1}{2} \|w\|^2 + C \sum_{i=1}^n \xi_i + \sum_i \alpha_i(y_i(w^T x + b) - 1 + \xi_i)$

![](../../..//ML/svm6.png)

## Non linear SVM

Sometimes data is not linearly separable in the original space. However, ==using a mapping function we can move it to a different space where it becomes linearly separable.==

![](../../..//ML/svm7.png)

We can do this ==using non linear kernels.==

### Non linear kernels

==When using a mapping function $\phi$, our formulas become respectively:==

>$f(x) = w^T \phi(x) + b$

>$\sum_{i \in SV} \alpha_i y_i \phi(x_i)^T \phi(x) + b$

Again, $\phi(x_i)^T \phi(x_j)$ is a kernel $K(x_i,x_j)$, and there are plenty to choose from:
- linear kernel: this is the case of the previous examples
- polynomial kernel
- gaussian kernel
- sigmoid 
- etc...

### "Definitive" algorithm for SVM

        1. Choose a kernel function
        2. Choose a value for C
        3. Solve the quadratic programming problem
        4. Construct the discriminant function from the support vectors

> find $\alpha_i, \ldots, \alpha_n$ such that
> $Q(a) = \sum_{i=1}^n \alpha_i - \frac{1}{2} \sum_{i,j =1}^n \alpha_i \alpha_j y_i y_j K(x_i,x_j)$ is maximised
>1. s.t. $0 \leq \alpha_i \leq C$
>2. s.t. $\sum_{i=1}^n \alpha_i y_i = 0$

### Issues, properites and weaknesses of SVM

==Issues:==
- choosing kernel function: gaussian or polynomial are default
- choiche of kernel parameters
- optimisation criterion, e.g. soft or hard margin
- sensitivity to class imbalances and non-scaled data

==Properties:==
- flexibility when choosing the kernel
- deal with large data sets and many features
- overfitting can be controlled

==Weaknesses:==
- noise sensitivity
- only considers 2 classes: to discriminate $m$ classes, one must train $m$ SVM models
- data in real life is rarely in vectorial form, so pre-processing is almost always needed 