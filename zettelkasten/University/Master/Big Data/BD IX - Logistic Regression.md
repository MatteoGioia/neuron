# Logistic Regression

Also see:
- [[../Foundations of Data Science/FDS IV - Classification]]

Note that in the steps about going from MLE to Cross entropy it is assumed that the random distribution has samples with values (-1, +1), so the final formulation is different from the one shown in FDS ==although equivalent==.

Suggested read: extensive explanation of gradient descent (slides)

### Recall questions

1. <details markdown=1><summary markdown="span"> What is the main issue when trying to do classification with linear regression?</summary>
    
    \
	There is ==no natural way to convert a K-ary (K > 2) response  into a quantitative response that is ready for linear regression==

</details>

2. <details markdown=1><summary markdown="span"> What are odds? How are they linked to logistic regresssion?</summary>
    
    \
	We define the odds as:
	![](../../../static/BIG/log1.png) \
	==Logistic regression is an ordinary linear regression where logit is the response variable==.

</details>

3. <details markdown=1><summary markdown="span"> So why do we use odds instead of a probabilities?</summary>
    
    \
	Because ==odds are defined over the range $[-\infty, +\infty]$, so we cab use the standard regression equation==.
	![](../../../static/BIG/log2.png)

</details>

4. <details markdown=1><summary markdown="span">  Show that we can go from odds to probabilities.</summary>
    
    \
	![](../../../static/BIG/log3.png)

</details>

5. <details markdown=1><summary markdown="span"> Why do we use odd ratios?</summary>
    
    \
	Using odds rather ==provides an easier interpretationof the model's learnt coefficients==:
	![](../../../static/BIG/log4.png) \
	For instance, if ==we compute the odds ratio we can measure how much  a variable can influence the final probability==. (see slide 80 for an example)	

</details>

6. <details markdown=1><summary markdown="span"> Why (in this case) we are estimating a noisy target, rather than a deterministic function ?</summary>

	\
	Because ==our goal, in fact, is to approximate a noisy target $\phi$. We'll do this leveraging the logistic function as explained before.==
	![](../../../static/BIG/log5.png)

</details>

7. <details markdown=1><summary markdown="span"> What are the 2 formulations for cross entropy loss? Are they equivalent? </summary>

	\
	![](../../../static/BIG/log6.png) \
	Yes, they are ==indeed equivalent== and this can proven through simple algebra.

</details>

