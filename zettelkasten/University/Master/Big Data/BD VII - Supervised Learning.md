# Supervised learning 

### Recall questions

While the content of the slides is different, it is strongly advised to look at:
- #[[../Machine Learning/ML III - Supervised Learning]]
- #[[../Machine Learning/ML V - Data PreProcessing and Feature Engineering]]
- #[[../Machine Learning/ML VI - Performance Evaluation]]  
- #[[../Foundations of Data Science/FDS VI - Bias and Variance]]

1. <details markdown=1><summary markdown="span"> Why can't we learn the true function from labeled data? What do we learn instead?</summary>
    
    \
    Finding the true function that represents the real distribution of the data is impossible, as we would need all the data in the world to get a good approximation. \
    What we find instead is an ==hypotesis function $h^*$, chosen from a family of functions in a hypotesis space $H$ which minimises the loss function.==

</details>

2. <details markdown=1><summary markdown="span"> What is the domain of the Loss function? What are we estimating? What is the proper name of this task?</summary>
    
    \
    Domain is $H \times D \to R$, we are estimating the ==out of sample error==, a.k.a. ==expected loss/risk==, with the ==in-sample error==, a.k.a. ==empirical loss==. \
    As a matter of fact, what we are doing is called ==Empirical risk minimization==.

</details>