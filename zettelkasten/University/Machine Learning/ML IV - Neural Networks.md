# Neural networks

## Recall questions
      - 

## PLACEHOLDERre not capable

### Multi-layer network

### Mean Squared Error 

In the case of gradient descent, the error is computed by the Mean Squared Error function a.k.a  MSE

Our objective is minimising such function.

### Sigmoid function

We cannot use the same step function we used for perceptrons as it is not differentiable. One solution is 
to find a similar one, called Sigmoid function, which closely emulates its behaviour and its differentiable.

### Computing the derivative of MSE

The derivative can be more easily computed by just calculating the derivative of the MSE on each value...

However our MSE formulation the parameters we are tuning don't appear!

### Using error to tune weights

But what happens when the output node is an "intermediate" node in the network and its output can't be seen directly

### Computing the derivative of MSE for inward/outward nodes

### Computing the derivative of MSE for inner nodes

Since we cannot know...

The idea is to use backpropagation of the error: the error we observe on a node can be distributed among its predecessors 
proportionally to the weights of the edges.