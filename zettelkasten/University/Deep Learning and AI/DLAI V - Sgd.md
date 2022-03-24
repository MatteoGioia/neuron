# Stochastic Gradient Descent

### Recall questions

Also see:
- isocurves / level sets (more generic)
- continuous gradient

1. <details markdown=1><summary markdown="span"> Why is the gradient orthogonal to level surfaces? </summary>
    
    \
    The directional derivative is zero along isocurves. In fact, the function value does not change on the isocurve, so it makes sense that the derivative (gradient) is 0. \
    The directional derivative can be computed as the product of the gradient with the vector and since the result is 0, they are clearly orthogonal.
    ![](./static/DEEP/sgd1.png)
  
</details>


2. <details markdown=1><summary markdown="span"> What is the key requirement of gradient descent? What is a common pitfall related to that? </summary>
    
    \
    GD requires $f$ to be differentiable at all points. 
    Note that if $f$ has partial (or even directional derivatives) it is not necessarily differentiable, while if $f$ has a continuous gradient it is.

</details>

3. <details markdown=1><summary markdown="span">  What is a stationary point? Is it always a local/global minimum? </summary>
    
    \
    A stationary point is a point for which... \
    It is not necessarily the local minimum, and it does not imply the existance of the global minimum.
    
</details>

4. <details markdown=1><summary markdown="span"> How can we find the optimal learning rate? Is the term lr synonim with step length?</summary>
    
    \
    Optimal values can be found via ==line search algorithms==. \
    No, step length refers to $\alpha || \nabla f||$
    ![](./static/DEEP/sgd2.png)

</details>

5. <details markdown=1><summary markdown="span"> What are possible strategies to choose the learning rate? </summary>
    
    \
    The learning rate can be adaptive or follow a schedule. For instance, it can decrease according to a decay parameter $\ro$ (to add: plots)
  
</details>

6. <details markdown=1><summary markdown="span"> What is momentum and how does it work? What is the step length?</summary>
    
    \
    The idea of momentum is to accumulate past gradients... \
    Step lenght $\alpha$ how aligned is the sequence of gradients...
    
</details>

7. <details markdown=1><summary markdown="span"> What is the generalised form of gradient descent? </summary>
    
    \
    First order accel. methods..
    
</details>

8. <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    
  
</details>