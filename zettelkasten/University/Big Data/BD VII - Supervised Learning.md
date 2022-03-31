# Supervised learning 

### Recall questions

While the content of the slides is different, it is strongly advised to look at:
- #[[ML III - Supervised Learning]]
- #[[ML V - Data PreProcessing and Feature Engineering]]
- #[[ML VI - Performance Evaluation]]  
- #[[FDS VI - Bias and Variance]]

1. <details markdown=1><summary markdown="span"> Why can't we learn the true function from labeled data? What do we learn instead?</summary>
    
    \
    Finding the true function that represents the real distribution of the data is impossible, as we would need all the data in the world to get a good approximation. \
    What we find instead is an ==hypotesis function $h^*$, chosen from a family of functions in a hypotesis space $H$.==

</details>

2. <details markdown=1><summary markdown="span"> What is the domain of the Loss function? What are we estimating?</summary>
    
    \
    Domain is $H \times D \to R$, we are estimating the ==out of sample error==, a.k.a. ==expected loss/risk==, with the ==in-sample error==, a.k.a. ==empirical loss==.

</details>