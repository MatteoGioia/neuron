# Multi Layer Perceptron

### Recall questions


1. <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    
</details>

2. <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    
</details>

3. <details markdown=1><summary markdown="span"> How can we express the deep composition as a linear combination? </summary>
    
    \
    We can express it as the product of $W \to (W \ b), \ x \to (x \ 1)$    
</details>

4. <details markdown=1><summary markdown="span"> How do we call each row of the weight matrix? What are we effectively doing when computing the linear combination? </summary>
    
    \
    Each row a weight matrix is called a neuron or hidden unit. Each layer is a vector to vector function,  $R^p \to R^q$. \
    Furthermore, each layer has $q$ units acting in parallel, and each unit acts as a scalar function $R^p \to R$.
    
</details>

5. <details markdown=1><summary markdown="span"> How is the codomain of the nn determined? </summary>
    
    \
    The output layer determines the co-domain of the network.
    
</details>

6. <details markdown=1><summary markdown="span"> Ridge function? </summary>
    
    \
    
</details>

7. <details markdown=1><summary markdown="span"> What happens if the function we are trying to approximate is not piecewise-linear? </summary>
    
    \
    We cannot approximate it with a Deep Relu network.
    
</details>

8. <details markdown=1><summary markdown="span"> What is the universal approximation theorem? Why does it matter? </summary>
    
    \
    
</details>

9. <details markdown=1><summary markdown="span"> What is a computational graph? What is the shape of the computational graph for the loss? </summary>
    
    \ 
    aaa ... \
    Shape: Input #params, Output: scalar
    
</details>

10. <details markdown=1><summary markdown="span"> What is forward mode and what is the key assumption we make? Why is inefficent in high dimensions? </summary>
    
    \
    
</details>

11. <details markdown=1><summary markdown="span"> What is the backward pass? Why is it necessary to compute the forward pass first? </summary>
    
    \
    
</details>

12. <details markdown=1><summary markdown="span"> Why is reverse mode inherently more efficient than forward mode? (Hint: huge jacobians) </summary>
    
    \
    
</details>

13. <details markdown=1><summary markdown="span"> What is backpropagation then? </summary>
    
    \
    
</details>