# Linear Regression

Also see #[[FDS III - Regression]]

### Recall questions


1. <details markdown=1><summary markdown="span"> What is the formulation of the supervised learning problem as an optimization problem?</summary>
    
    \
    We can define the supervised learning problem as the optimization problem known as ==Ordinary Least Squares (OLS)==.
    Our goal is to find $h^* = h_{\theta^*} = \text{arg min}_{\theta} \ L(h_{\theta},D)$.

</details>

2. <details markdown=1><summary markdown="span">What is the difference between errors and residuals (just a brief remark)?</summary>
    
    \
    ![](../../../static/BIG/linreg1.png)

</details>

3. <details markdown=1><summary markdown="span">What are the 5 key assumptions made in OLS? How do we check that they are true?. </summary>
    
    \
    Five key assumptions:
    - ==weak exogeneity==: ==predictor variables can be treated as error free constants==
    - ==linearity==
    - ==error indipendence==: we assume the errors on the variables are i.i.d
    - ==homoscedasticity==: ==different values of the response variable have the same variance in their errors, regardless of the feature values==.
    - ==no multicollinearity==

    To verify this assumptions, we can use ==residual plots==.

</details>

4. <details markdown=1><summary markdown="span">What is Residual standar error? What does it measure</summary>
    
    \
    RSE is one of the presented measures for =="goodness of a fit of a model==". Formally, it measures the ==std deviation of the error associated with each prediction==:
    ![](../../../static/BIG/linreg2.png)
    
</details>

5. <details markdown=1><summary markdown="span"> How do we compute the degree of freedom? Is it related to nr. of variables/features?</summary>
    
    \
    The $df = m - n - 1$ where:
    - $m$ = #observations
    - $n$ = #features
    - 1 is the intercept
    
</details>

6. <details markdown=1><summary markdown="span"> What is R²?</summary>
    
    \
    The other presented measure. In short, it measures ==the proportion of variability in $Y$ that can be explained with $X$==.
    ![](../../../static/BIG/linreg3.png)

</details>

7. <details markdown=1><summary markdown="span">Why do we need an adjusted version of R² in practice?</summary>
    
    \
    Since ==RSS can be drecreased arbitrarily by incrementing the number of features, we need to balance the fact that we could get a better score by simply adding useless features==.
    ![](../../../static/BIG/linreg4.png)
    

</details>

8. <details markdown=1><summary markdown="span"> What is the elastic net framework?</summary>
    
    \
    It's a ==more general framework, of which OLS is just a special case of==:
    ![](../../../static/BIG/linreg5.png)
    

</details>