# Dimensionality reduction

### Recall questions

Also see:
- variance and covariance (slide 55-60)
- mean of centered variable
- notes on eigenvectors and variance
- a really nice explanation (informal): https://stats.stackexchange.com/questions/2691/making-sense-of-principal-component-analysis-eigenvectors-eigenvalues

1. <details markdown=1><summary markdown="span"> What are 3 possible strategies to deal with high dimensional data ? </summary>

    \
    Possible strategies:
    - ==feature engineering==: using domain knowledge
    - ==making assumptions==
    - ==reduce dimensionality==

</details>

2. <details markdown=1><summary markdown="span"> What is a key aspect of dimensionality reduction? </summary>

    \
    ==Preserve as much structure (variance) of the original data==.

</details>

3. <details markdown=1><summary markdown="span">  What are 2 possible dimensionality reduction techniques? </summary>

    \
    Possible techniques:
    - ==feature selection==
    - ==feature extraction==

</details>

4. <details markdown=1><summary markdown="span">  How are the principal components defined in PCA? </summary>

    \
    ==PCA defines a set of principal components as follows==:
    1. ==direction of the greatest variance of data==
    2. ==perpendicular to 1st and greatest variance of what's left==
    3. and so on...

</details>

5. <details markdown=1><summary markdown="span"> Why do we look for the greates variance? </summary>

    \
    Intuitively, ==we want to minimize the chance that 2 points that are far away in the original dimension end up close in the reduced dimenension==.

</details>

6. <details markdown=1><summary markdown="span"> Explain all the steps of PCA. </summary>

    \
    See slides, but a simple list of steps would be:
    1. Center around the mean
    2. Compute eigenvalues and eigenvectors
    3. Pick the $k$ eigenvectors with the largest eigenvalues $\lambda$
    4. Obtain a new point within the new set of coordinates expressed by the set of chosen eigenvectors

</details>

7. <details markdown=1><summary markdown="span"> What does the $i-th$ eigenvalue express? How is it helpful in choosing the number of dimensions? </summary>

    \
    Since the ==$i-th$ eigenvalue expresses the variance along the $e_i$ eigenvector, we sort them in descending order and pick the subset that retains the most variance.==
    
</details>

8. <details markdown=1><summary markdown="span"> What are the practical issues of PCA? How can we deal with them? </summary>

    \
    Issues:
    - ==sensitivity to outliers== (fix: centering and scaling)
    - ==PCA assumes the projection subspace is linear== (use KernelPCA)
    

</details>