# Probabilistic machine learning

This section can be integrated with FDS V - PLM

## Recall questions

- How can we rephrase ML problems to a probabilistic formulation?

- What are the 2 probablistic formulations of a ML classifier? Explain both the generative models and discriminative models.

- What is the difference between generative and discriminative models?

![](../../../ML/pml2.png)

![](../../../ML/pml1.png)

### Maximum likelihood estimation (GEN)

- What is the main goal of modeling the problem with a generative model? 
  
![](../../../ML/pml3.png)

- What is the maximum likelihood estimation? Define the likelihood function and the others notions necessary to define the problem. Why likelihood is not the same as probability?
  
![](../../../ML/pml4.png)

- What is statistical parameter fitting? What is a necessary requirement for the data used?

- How is the MLE principle defined?  What is a sufficient statistics?

![](../../../ML/pml5.png)

- How is the Likelihood maximised? What is the function commonly used in place of the likelihood function?

- Define the workflow for MLE of discrete variables. Explain the steps for binomial and multinomial.

- How do the steps differ for something like a gaussian distribution?

- How do we compute the class after having estimated the parameters?

### Maximum a Posteriori estimate (GEN)

- What is MAP? What is the main difference with MLE?

![](../../../ML/pml9.png)

- What is the probabilistic model in MAP? How is it different from MLE?

- How is the bayes theorem used in MAP?
  
![](../../../ML/pml10.png)

- What happens when we calculate the joint probability of the parameters? Why is it an issue?

![](../../../ML/pml11.png)

### Naive bayes model 

- What is NBM based on? What assumption makes this model "naive"?

- Why does this assumption makes calculating the probability easier? How do we make a prediction?

![](../../../ML/pml6.png)

- How do we about estimating the parameters? What does the estimation depend upon?

- What is the final formulation for the prediction?

![](../../../ML/pml12.png)

- Make an example with the urn dataset and apply the naive bayes method for a prediction.

![](../../../ML/pml7.png)

- How can we deal with dataset that are too small? Why there could be issues in the calculation? Explain the new formulation.

![](../../../ML/pml8.png)

- How does the formula for naive bayes change if we assume a continuous distribution for the features? (e.g. a gaussian)

- What is the performance of a naive bayes model?