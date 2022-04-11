# Multi Layer Perceptron

### Recall questions


1. <details markdown=1><summary markdown="span"> How can we express a non linear parametric model through composition? </summary>
    
    \
    ![](../../../DEEP/mlp1.png)
    
</details>

2. <details markdown=1><summary markdown="span"> What is a deep feed forward neural network? (hint: leverage previous definition) </summary>
    
    \
    ![](../../../DEEP/mlp2.png) \
    Note that ==$f$ is linear, $\sigma$ is not==!
    
</details>

3. <details markdown=1><summary markdown="span"> How can we express the deep composition as a linear combination? </summary>
    
    \
    We can express it as the product of $W \to (W \ b), \ x \to (x \ 1)$. The weight of layer $\mathcal{l}$ are encoded in the matrix $W_{\mathcal{l}}$

</details>

4. <details markdown=1><summary markdown="span"> How do we call each row of the weight matrix? What are we effectively doing when computing the linear combination? </summary>
    
    \
    Each ==row of a weight matrix is called a neuron or hidden unit. Each layer is a vector to vector function,  $R^p \to R^q$==. \
    Furthermore, ==each layer has $q$ units acting in parallel==, and ==each unit acts as a scalar function $R^p \to R$==.
    
</details>

5. <details markdown=1><summary markdown="span"> How is the codomain of the nn determined? What is a common layer to use for the output? </summary>
    
    \
    The ==output layer determines the co-domain of the network==. In general, ==a linear layer== is a common choice for the output.
    
</details>

6. <details markdown=1><summary markdown="span"> What happens if we had a linear function as output layer? What is the "shape" of the final function? (hint: ridge) </summary>
    
    \
    The $y$ is expressed as a ==combination of ridge function==. This means that the final function will be ==piece-wise linear==. \
    ![](../../../DEEP/mlp3.png)
    
</details>

7. <details markdown=1><summary markdown="span"> What happens if the function we are trying to approximate is not piecewise-linear and we are using a deep relu net? </summary>
    
    \
    We ==cannot approximate it==.
    
</details>

8. <details markdown=1><summary markdown="span"> What is the universal approximation theorem? What type of network that the theorem refer to? Is this theorem unique? </summary>
    
    \
    ![](../../../DEEP/mlp4.png) \
    Note that ==$\sigma$ must be sigmoidal and that the network in question has just 1 layer==. Furthermore, ==for large enough $q$, we can make the tranining error arbitrarily small== (i.e. get better approx).

    
</details>

9. <details markdown=1><summary markdown="span"> What is a computational graph? What is the shape of the computational graph for the loss? </summary>

    \
    It's a ==directed acyclic graph that represents the computation of $f(x)$ with intermediate variables==. \
    ![](../../../DEEP/mlp5.png) \
    Shape: Input [[params]], Output: scalar
    
</details>

10. <details markdown=1><summary markdown="span"> What is forward mode and what is the key assumption we make? Why is inefficent in high dimensions? </summary>
    
    \
    Ideally, we want a ==lookup table to quickly compute the derivatives==. However, ==in high dimensions, the cost of computing $\nabla f(x) = p \times$ cost of computing $f(x)$==, since we have to compute partial derivatives w.r.t. to each input dimension.\
    In other words, we are simply applying the chain rule in a straightforward manner.
    
</details>

11. <details markdown=1><summary markdown="span"> What is reverse mode and the backward pass? Why is it necessary to compute the forward pass first? </summary>
    
    \
    ![](../../../DEEP/mlp6.png)
    
</details>

12. <details markdown=1><summary markdown="span"> Why is reverse mode inherently more efficient than forward mode? (Hint: huge jacobians) </summary>
    
    \
    ![](../../../DEEP/mlp7.png)
    
</details>

13. <details markdown=1><summary markdown="span"> What is backpropagation then? </summary>
    
    \
    We call backpropagation ==the reverse mode automatic differentiation applied to deep neural nets==. It is as fast as evaluating the original function! Always remember: backpropagation is ==a computational technique==.
    
</details>