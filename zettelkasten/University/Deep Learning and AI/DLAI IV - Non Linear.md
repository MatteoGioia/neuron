# Going Non Linear 

### Recall questions

Proof that CELOSS is convex: (https://math.stackexchange.com/questions/1582452/logistic-regression-prove-that-the-cost-function-is-convex)

1. <details markdown=1><summary markdown="span"> Why is polynomial regression still linear? </summary>
    
    \
    Because it ==is linear w.r.t. to the parameter, but polynomial w.r.t. to the data==.

</details>

2. <details markdown=1><summary markdown="span"> Express the polynomial model with matrices to prove it is still linear w.r.t. to the parameters. How many data points do we need (and why)?</summary>
    
    \
    ![](../../..//DEEP/poly1.png) \
    We can still solve this with MSE, but it is ==necessary that $k < n$==. Alternatively, we can say we need $k+1$ data points, e.g. infinite lines pass through one data point.

</details>

3. <details markdown=1><summary markdown="span"> What is polynomial fitting? How is it linked to poly regression (explain the consequences)? </summary>
    
    \
    Theorem:
    >Stone Weierstrass theorem: if $f$ is continuous on the interval $[a,b]$, then for every $\varepsilon$ there exists a polynomial $p$ s.t. $|f(x) - p(x)| < \varepsilon$ for all $x$.

    A consequence of this is that we can ==always fit a polynomial== to our data...but is it the right thing to do?

</details>

4. <details markdown=1><summary markdown="span"> What happens if we increase the degree of the polynomial? </summary>
    
    \
    ![](../../..//DEEP/poly2.png) \
    What happens is that adding complexity leads to overfitting and loss of generalization.

</details>

5. <details markdown=1><summary markdown="span"> What is Tikhonov regularization? What it is its goal/effect?</summary>
    
    \
    It is a ==form of weight decay used to counter large parameters==. It allows to do what's called ==shrinkage==. \
    The general form is $min \ l_{\Theta} + \lambda ||\Theta||_p$. Note that the function is ==still convex==.

</details>

6. <details markdown=1><summary markdown="span"> What happens to the loss when we do logistic regression? Is it still linear? </summary>
    
    \
    ![](../../..//DEEP/poly3.png) \
    Note that ==$\sigma$ has a saturation effect, as it maps $R \to (0,1)$==.

</details>

7. <details markdown=1><summary markdown="span"> How do we fix the non convexity of the loss? </summary>
   
    \
    The new ==loss function (cross entropy loss) is convex==:
    ![](../../..//DEEP/poly4.png) \
    ![](../../..//DEEP/poly5.png)

</details>

8. <details markdown=1><summary markdown="span"> Go through all the steps of the derivation. </summary>
    
    See slides 57-78.

</details>

9. <details markdown=1><summary markdown="span"> What is the issue when trying to solve for 0 in the optimization? </summary>
    
    \
    The ==parameters enter the gradient in a non linear way==. So the $\nabla l_{\Theta} = 0$ is not a linear system but a ==trascendental equation==, for which we have no close form solution.
    ![](../../..//DEEP/poly6.png) 

</details>