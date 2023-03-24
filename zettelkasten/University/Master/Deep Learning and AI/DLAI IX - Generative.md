# Deep generative models

### Recall questions

Also see:
- [[BD VI - Dimensionality Reduction]]
- notes on entropy and divergence

1. <details markdown=1><summary markdown="span"> What is the idea behind generative models ? </summary>
    
    \
    We want to ==learn a distribution from some training samples, and generate new samples from the same distribution==.
  
</details>

2. <details markdown=1><summary markdown="span"> How can we use PCA as a generative model? Why it is not enough? (Hint: it is highly suggested to revise how PCA works before answering) </summary>
    
    \
	Once ==we learn the matrix of weights needed for reconstruction==, we can ==sample points from the space with lower dimensionality. Then, we multiply them with the weight matrix and obtain new objects==.
	![](../../../static/DEEP/gen1.png) \
	The thing is ==we want a more expressive model, and the linearity of PCA is just not enough!==.

</details>

3. <details markdown=1><summary markdown="span"> What is an autoencoder? What does it minimize? </summary>
    
    \
	An encoder is a ==deep neural network with an encoding portion and a decoding portion==. For a given dataset ${x_i}$, it will learn to ==minimize the reconstruction error $l_{\Theta} = \sum_i ||x_i - D_{\Theta}(E_{\Theta}(x_i))||$==
  	![](../../../static/DEEP/gen2.png)

</details>

4. <details markdown=1><summary markdown="span"> How do we ensure that no trivial solution is provided?  What is the real goal of an AE?</summary>
    
    \
  	Because of the ==bottleneck, no trivial solution is possible== (e.g. identity). \
	The task of an AE ==is always recostruction==, since what we are really interested in ==is the structure of the latent space and using E,D for new tasks== (e.g. generating new samples, denoising and so on).
	
</details>

5. <details markdown=1><summary markdown="span"> What can be said about the latent space and embedding in autoencoders? </summary>
    
    \
    The goal of the decoding portion of an AE is ==learning a mapping from a low dimensional latent space to a high dimensional embedding of the observed data== \
    The ==latent space is euclidean== while the ==data embedding space is a manifold==. 

</details>

6. <details markdown=1><summary markdown="span"> How do you define a manifold? What are the key requirements for charts in order to be manifolds? What are the domain and codomain of the function? </summary>
    
    \
	We define a manifold as ==a union of charts==, where each chart can be seen as a mapping $\phi \ : \ R^2 \to \textit{S} \subset R^3$. It is fundamental that $\phi$ is:
	- ==smooth==
	- ==invertible==

	And we call them a ==diffeomorphism==. The domain is the ==parametric space (euclidean)==, while the image is ==an embedding and is a surface==.
	![](../../../static/DEEP/gen3.png)
  

</details>

7. <details markdown=1><summary markdown="span"> Is the parametrization for an embedding unique? </summary>
    
    \
	No, the ==mapping is not unique==. In general, we can potentially have ==infinitely many mappings to the same embedding==.
  

</details>

8. <details markdown=1><summary markdown="span"> What is the link between an AE and a manifold then? What properties does it have? </summary>
    
    \
    The ==decoder is effectively a chart $D \ : \ R^k \to R^d$ from the latent space spanned by the codes $z$ to the data space of inputs $x$.== \
	This mapping is ==differentiable== and ==invertible through E==.
	![](../../../static/DEEP/gen5.png)

</details>

9. <details markdown=1><summary markdown="span"> What is the idea behind a variational autoencoder? </summary>
    
    \
	A variational autoencoder works by ==constructing a probability distribution on the latent space==. The ==data is seen as a sample of the learnt distribution, which is fixed and decided a priori==.

</details>

10. <details markdown=1><summary markdown="span"> How do we define this probabilistic encoder? What is the main issue and how do we "fix it"? Hint: for this part is highly suggested to refer to the slides.</summary>
    
    \
	![](../../../static/DEEP/gen6.png)
	![](../../../static/DEEP/gen7.png) \
	The main idea is that we try to maximize a relaxed version of the problem by "increasing" the first quantity enough. 

</details>

11. <details markdown=1><summary markdown="span"> What is the result of this probabilistic encoder? </summary>
    
    \
	The probabilistic encoder outputs a ==gaussian distribution==. In other words, ==it won't output $z$, but $\mu, \sigma$ of our gaussian!==.
	[](../../../static/DEEP/gen8.png)

</details>

12. <details markdown=1><summary markdown="span"> Why are we modeling our priors e.g. z as a gaussian? </summary>
    
    \
	This ensures that ==our latent space is compact==. In other words, ==two points close in the latent space will be similar once decoded==.

</details>

13. <details markdown=1><summary markdown="span"> Why do we need both reconstruction loss and continuity loss in our VAE? </summary>
    
    \
	![](../../../static/DEEP/gen9.png)

</details>