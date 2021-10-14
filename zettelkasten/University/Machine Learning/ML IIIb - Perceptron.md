# Perceptron

## Recall questions
      - 


## Introduction to neural networks

### Neural network

Neural network is a class of ML algorithm that belongs to the category of supervised and semi supervised learning.

The learned function is continuous and linear for the perceptrons, while other advanced algorithm learn non linear functions
- both classifiers and regressors can be trained.

### History of NN

Neural networks were born as a way to mimic the biological neural systems like the one in humans.
In these systems, intelligent behaviour is due to an "emergent" property of a large number of simple units rather than from explicitely encoded symbolic rules and algorithms. 
- but this emergent behaviour has not be explained yet

The idea is also to emulate the massive parallelism of human brain
- the human brain is infinetely less "powerful" compared to a pc, but can compute some tasks much faster, like for image recognition

The following aspects of the human brain were replicated:
- action potential fired when a certain threshold is reached
- synapses changing size with experience
- hebbian learning: neurons firing together create a strong connection

History of NN:
1. perceptron
2. backpropagation
3. convolutional NN, recurrent NN

## Perceptron

### The model

The network model of a single neuron is a graph with cells as nodes and synaptic connections as weighted edges from node $x_i$ to neuron node.
- $x_i$ are the feature values of instances $x$

![](./static/ML/perceptron.png)

The output is computed as a linear combination of the features of the instance $net = \sum_i w_i \cdot x_i$
- if $net(x) \geq \theta$, output = 1
- else $net(x) < \theta$, output = 0

The step function $\phi$, which is binary, emulates the activation function.

In this case, the parameters we need to tune is the weight of the edges and the right threshold.

This threshold can be easily incoporated in the convolution or the step function
- by subtracting it to $(\sum_i w_i \cdot x_i) - \theta$, modeling it as a dummy node with weight $w_{n+1} = - \theta$
- by moving further the threshold in the function $\phi$

![](./static/ML/thetaf.png)

### Linear Decision Boundary

The function $f(x) = \sum_i w_i \cdot x_i - \theta$  is an hyperplane in a $n$-dimensional space
- $n$ is the number of features

The classification function $\phi(x)$ classifies an instance as positive if $f(x) = \sum_i w_i \cdot x_i \geq \theta$

Note that $f(x)$ is the learned model, while $\phi(x)$ is just the classification function.

### Alternative representation

The hyperplane is also called a linear decision boundary. Indeed, we see the convolution as a function $y = mx + q$
- for instance, $w_1 x_1 + w_2 x_2 - \theta = 0 \to x_1 = \frac{w_1}{w_2}x_2 + \frac{\theta}{w_1}$

Similarly, we can obtain a geometric representation of objects $x$ in the dataset as vectors.

![](./static/ML/lineardec.png)

### Perceptron training algorithm

![](./static/ML/algoperc.png)

$\eta$ is a constant called the learning rate 

The until condition is instead called convergence condition
- each iteration is called an epoch

### More on the learning rules

The learning rules can also be interpreted as:
- if $o_j = y_j$ no update because output is correct
- if $o_j > y_j$ decrease the weight/threshold because false positive
- if $o_j < y_j$ increase the weight/threshold because false negative

The aumont of increase is "controlled" by $\eta$.

### Gradient descent (almost)

In the case of perceptrons the objective is minimize the classification error, so to find the minimum of the training error function:

![](./static/ML/trainingerr1.png)

### Shortcoming of perceptrons

Perceptrons are incapable of computing non linearly-separable functions. Sometihng more complex is needed.