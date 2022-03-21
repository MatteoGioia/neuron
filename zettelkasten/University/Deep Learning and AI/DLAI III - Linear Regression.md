# Linear regression, convexity and gradients

### Recall questions

Also see:
- jensen's inequality and convex functions (slide 8)
- computing the gradient of matrices
- euclidean distance (L-p norm)


1. <details markdown=1><summary markdown="span"> What is the model for linear regression? </summary>
    
    \
    Model: linear + bias \
    Parameters: $\Theta = \{a,b\}$ \
    Data: $n$ pairs $x_i,y_i$, $x_i$ are called regressors \
    Given $a$ and $b$, we have a mapping that gives new output from new input.

</details>


2. <details markdown=1><summary markdown="span"> What is the formal definition of linear regression? What is this problem called if $f_{\Theta}$ is linear?  </summary>
    
    \
    ![](./static/DEEP/lr1.png) 


</details>


3. <details markdown=1><summary markdown="span"> What is the chosen loss function? Is it the same without the $\frac{1}{n}$ factor? What we are minimizing w.r.t. to? </summary>
    
    \
    ![](./static/DEEP/lr2.png)

</details>

4. <details markdown=1><summary markdown="span"> What general optimization problem are we solving? What will be the type of problems we deal with?</summary>
    
    \
    We need to solve the ==general minimization problem $\varepsilon = min_{\Theta} l(\Theta)$==. So, we need to find the minimizer $\Theta$. \
    We will mostly deal with ==uncostrained problems==.

</details>

5. <details markdown=1><summary markdown="span"> What can we say about the global minimizer of a differentiable convex function? </summary>
    
    \
    The global minimizer $x$ is where $\frac{df(x)}{dx} = 0$ 

</details>

6. <details markdown=1><summary markdown="span"> What can be said about the convex functions in more than 1 space? </summary>
    
    \
    ![](./static/DEEP/lr3.png) \
    Note that 0 is a vector, known as additive identity!

</details>

7. <details markdown=1><summary markdown="span"> What can be said about the gradient (vector fields)? </summary>
    
    \
    The gradient is a vector field on the domain of the functions.

</details>

8. <details markdown=1><summary markdown="span"> Show the steps for minimizing the loss. Is this function linear? </summary>
    
    \
    ![](./static/DEEP/lr4.png) \
    Yes, w.r.t. to the parameters.

</details>

9. <details markdown=1><summary markdown="span"> What is the matrix formulation for the linear regression? What is this? </summary>
    
    \
    ![](./static/DEEP/lr5.png) \
    Linear map as function of parameters.

</details>

10. <details markdown=1><summary markdown="span"> How is the MSE expressed in matricial form? </summary>
    
    \
    MSE : $l(\theta) = ||y - X\theta||_2^2$

</details>

11. <details markdown=1><summary markdown="span"> Show the steps for minimizing the loss expressed in matricial form. </summary>
    
    \
    ![](./static/DEEP/lr6.png)

</details>

12. <details markdown=1><summary markdown="span"> How does linear regression work in higher dimensions? </summary>
    
    \
    In the more general case, the data points $(x_i, y_i)$ are vectors in $R^d$. \
    The close form solution becomes $\Theta = (XX^T)^{-1}XY^T$

</details>