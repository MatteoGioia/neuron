# Neural networks

## Recall questions
      - Describe the general architecture of a neural network.
      - Why is tuning NN compared to hill climbing?
      - What is the gradient? How do we use it?
      - What is the Loss Function for NN?
      - Why in NN the activation function must be different from perceptrons?
      - How can we derive the loss function to tune the weigths? Why it's not as straightforward as just "deriving" it?
      - What is backpropagation? What is the new and more efficient rule that makes use of it?
      - Describe how the backpropagation algorithm works. What are the backward and forward step?
      - What are the common issues with basic backpropagation and how can we fix them?

## Neural networks

### Multi-layer network

Multi-layer network ==can represent arbitrary functions==.

Typically they consist of ==input, hidden and output layers==, each fully connected to the next with the activation feeding forward.

IN the following, an example $x \in D$ is now a pair of vectors $(<x_1, \ldots, x_m>, <y_1, \ldots, y_k>)$
- $x$ is the feature vector
- $y$ is the ground truth vector: complex output functions or a multiple classification

Each node $n_j$ will then receive a weighted sum of values $net_j$ and compute the activation function, $\phi(net_j - \theta_j)$

==Parameters: the weights $w_{ij}$==
- they are updated through backpropagation of the error

==Hyperparameters==:
- ==network architecture==
- ==neuron activation functions==

So the ==target is to learn the weights and the threshold that minimize error between output available on output nodes $o_j$ and the true output values $y_j$ in training set $D$==.
- output values can be continuous rather than discrete, so ==NN are a regressors, although they can be turned into a classifier==

### Hill climbing

The ==tuning process is similar to perceptron, but now we are using gradient descent in a multi-dimensional graph==:
1. we ==start with random weights== $W$ and $\theta$
2. we ==compute a solution, calculate the error== and then ==tune the weights and activation function==
3. we ==continue until our new solution doesn't improve any longer==

### Gradient and Gradient Descent

The ==gradient of a scalar field is a vector field that points in the direction of the greatest rate of increase (or decrease) of the scalar field, and whose magnitude is that rate==.
- in simpler terms, the variation of any quantity (the error in our case) can be represented by a slope
- the steepness and direction of this slope are represented by the gradient

The ==gradient is computed using the derivative of the function. We'll compute the gradient (derivative) of the error and do small steps into the negative
direction to find minima.==

![](../../..//ML/gradientdescent.png)

## Tuning Parameters

### Mean Squared Error 

In the case of ==NN, the error is computed by the Mean Squared Error function a.k.a  MSE==

Our objective is ==minimising the function Loss($W) = \frac{1}{|D|}\sum_{h \in D}\sum_{j=1 \ldots k}((y_{j}^{h} - o_{j}^{h})^2)$==
- $D$ is the dataset
- $n = |D|$ cardinality of the dataset
- $k$ number of output nodes in the NN
- $W$ set of weights including the thresholds 

Another common Loss$(W) = \frac{1}{2|D|}\sum_{h \in D}\sum_{j=1 \ldots k}((y_{j}^{h} - o_{j}^{h})^2)$
- this is used more when doing derivatives to get a cleaner result

### Sigmoid function

We ==cannot use the same step function we used for perceptrons as it is not differentiable==. One solution is 
to find a similar one, called ==Sigmoid function==, which closely emulates its behaviour and its differentiable.

![](../../..//ML/sigmoid.png)

The activation functions also acts a limiter of the nodes' output.

![](../../..//ML/sigmoid2.png)

<small> in the following the threshold is identified with $T$ or $\theta$ </small>

### Computing the derivative of MSE

When ==doing the derivative, we compute the inner values of the sum separately since we consider only one input-output pair==
- this makes for easier computation as we can just compute the overall gradient by summing them up and then dividing by $n$

![](../../..//ML/singleMSE.png)

For instance, ==loss on single output is computed as==:

![](../../..//ML/singleMSE2.png)

### Using error to tune weights

We ==need to tune the weights to minimise the error but as of now, the derivative formula does not contain them==!

To fix this, ==we can use gradient descent to adjust weights at each iteration: $w_{ij} = w_{ij} + \Delta w_{ij} = w_{ij} - \eta \frac{\delta Loss(w_ij)}{\delta w_{ij}}$==
- basically ==each weight is updated proportionally to the partial derivative==
- in simpler terms, is updated using only the fraction of the gradient that can be imputed to that particular weight.

![](../../..//ML/gradientder.png)

Where $\delta_j$ is the derivative of the error cause by a node $n_j$ when computing the convolution.
For example, we can visualize the contribution of a single $w_{ij}$ as follows:

![](../../..//ML/wjcon.png)

We can now compute the partial derivatives:

![](../../..//ML/derivatives1.png)

We only need to compute the last partial derivative, that depends on the layer of the node.

### Computing the derivative of MSE for inward/outward nodes

In the case of any output node $n_j$, we only have $B$ to derivate:

![](../../..//ML/lossout.png)

And so the loss function of single node is:

![](../../..//ML/derivatives2.png)

### Computing the derivative of MSE for inner nodes

==We don't know the error of inner nodes as we can't compare them to a ground truth!==

The idea is to use ==backpropagation of the error: the error we observe on a node can be distributed among its predecessors 
proportionally to the weights of the edges==.

Formally, ==we say that the error observed on an inner node $n_j$ in hidden layer $Y$ is the sum of the derivatives of the errors caused 
by the $L$ nodes $n_1, \ldots, n_L$ of layer $Y+1$ to which $n_j$ is connected, weighted by the value of the conecting synapses.==

### Backpropagation

We ==can use backpropagation to iteratively compute the partial derivative of the loss function
for any weight $w$ and threshold in the network, starting from the output nodes all the way up to the input.==

The ==learning rule then becomes $w_{ij} = w_{ij} - \eta \delta_j o_i$==
- if $j$ is an ==output unit, then $\delta_j = (o_j - y_j)o_j(1-o_j)$==
- if $j$ is an ==hidden node at layer $L$, then $\delta_j = (\sum_{l \in L} \delta_l w_{jl})o_j(1-o_j)$==

As we can see, in an hidden layer ==the error of a node is computed as the weigthed sum of the errors 
generated by all the nodes of the subsequent layer to which is connected.==

### Backpropagation algorithm

Hyperparameters: network arch, loss function, $\eta$

Parameters: synaptic weigths and thresholds.

![](../../..//ML/backprop1.png)

Note that this algorithm, although it works, has some flaws (due to the network's architecture) that will be fixed only when discussing about DNN.

### Issues with basic backpropagation

One ==issue with simple NN is convergence==: is it not guaranteed that any weigth choiche will lead to convergence
- it also take a lot of time to reach convergence
- a good rule of a thumb is to choose random weights in an interval $[- \alpha,\alpha]$

Another issue is ==local minima==: they can be avoided using
- multiple training runs
- ==momentum==: $\Delta w^{t}_{ij} = -\eta \frac{\delta Loss}{\delta w_{ij}} + \mu \Delta w^{t-1}_{ij}$ 

==Overfitting== caused by ==too many hidden units or too much traning==
- how to choose the number of units will be explained later
- the latter can be prevented by stopping when error on a test set stops decreasing

### Deep understanding of NN

While we understand how we create such networks, we don't yet understand *why* they interally work. So to us,
NN are like a black box...for now.