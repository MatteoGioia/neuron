# Stochastic Gradient Descent

### Recall questions

Also see:
- isocurves / level sets (more generic)
- continuous gradient

1. <details markdown=1><summary markdown="span"> Why is the gradient orthogonal to level surfaces? </summary>
    
    \
    The ==directional derivative is zero along isocurves==. In fact, the function value does not change on the isocurve, so it makes sense that the derivative (gradient) is 0. \
    The directional derivative can be computed as the product of the gradient with the vector and since the result is 0, they are clearly orthogonal.
    ![](../../../DEEP/sgd1.png)
  
</details>


2. <details markdown=1><summary markdown="span"> What is the key requirement of gradient descent? What is a common pitfall related to that? </summary>
    
    \
    ==GD requires $f$ to be differentiable at all points==. 
    Note that if $f$ has partial (or even directional derivatives) it is not necessarily differentiable, while if $f$ has a ==continuous gradient it is==.

</details>

3. <details markdown=1><summary markdown="span">  What is a stationary point? Is it always a local/global minimum? </summary>
    
    \
    A stationary point is a point for which $x^{t+1} = x^t$, as $\alpha \nabla f(x^t) \to 0$ \
    It is not necessarily the local minimum, and it does not imply the existance of the global minimum.
    
</details>

4. <details markdown=1><summary markdown="span"> How can we find the optimal learning rate? Is the term lr synonim with step length?</summary>
    
    \
    Optimal values can be found via ==line search algorithms==, however in practice we do something else (next question). \
    No, step length refers to $\alpha || \nabla f||$
    ![](../../../DEEP/sgd2.png)

</details>

5. <details markdown=1><summary markdown="span"> What are possible strategies to choose the learning rate? </summary>
    
    \
    The learning rate can be ==adaptive or follow a schedule==. For instance, it can decrease according to a decay parameter $\rho$. 
    ![](../../../DEEP/sgd3.png) \
    (Not sure about the graphs)
  
</details>

6. <details markdown=1><summary markdown="span"> What is momentum and how does it work? What is the step length?</summary>
    
    \
    The idea of momentum is to accumulate past gradients "energy". It is expressed as:
    ![](../../../DEEP/sgd4.png)

    Step lenght $\alpha$ how aligned is the sequence of gradients and it is $\frac{1}{1 - \lambda} \alpha ||\nabla f||$
    
</details>

7. <details markdown=1><summary markdown="span"> What is the generalised form of gradient descent? </summary>
    
    \
    ![](../../../DEEP/sgd5.png) 
    
    We can also have $\Gamma$ be a diagonal matrix.
    
</details>

8. <details markdown=1><summary markdown="span"> So is the point of GD finding the optimum? </summary>
    
    \
    While it is a good technique to find a local minimum and potentially the global one, ==we are not interested in finding the global minimum== (necessarily).
    
</details>

9. <details markdown=1><summary markdown="span"> What is the main issue of normal gradient descent? </summary>
    
    \
    In normal GD, we ==compute the loss on each training sample==. With ==many samples and many parameters== this quickly becomes computationally expensive!
  
    
</details>

10. <details markdown=1><summary markdown="span"> What is the idea behind SGD? </summary>
    
    \
    We use a small batch as representative of the entire dataset and compute the loss on that batch.
    ![](../../../DEEP/sgd7.png)
    
</details>

11. <details markdown=1><summary markdown="span"> Is sdg better than gd then? Why? Why not? </summary>
    
    \
    It depends (as usual)!
    ![](../../../DEEP/sgd6.png)

</details>