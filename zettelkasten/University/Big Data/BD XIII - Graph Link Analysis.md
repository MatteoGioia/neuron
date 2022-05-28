# Graph Link Analysis

### Recall questions

1. <details markdown=1><summary markdown="span">What is graph link analysis? </summary>

    \
	A ==data analysis technique, used to evaluate relationships between nodes of a graph==. 

</details>

2. <details markdown=1><summary markdown="span">What are 2 issues of traditional ranking approaches? </summary>

    \
	Two issues:
	- ==information overload==:  millions of pages must be ranked quickly
	- ==results trustworthiness==: traditional IR approaches work on "small sets of trusted documents"
	
</details>

3. <details markdown=1><summary markdown="span">Why do we say the web is a scale free graph? </summary>

    \
	Because the distribution of the degrees of its nodes ==follows a power law==.
	![](../../../static/BIG/gla1.png)

</details>

#### ==page rank==

4. <details markdown=1><summary markdown="span">What are the 2 main intuitions used in page rank? </summary>

    \
	Two main intuitions:
	- ==count incoming links as votes== of trustworthiness
	- ==weigh such links w.r.t. to the rank of the original page== from which the link originates

</details>

5. <details markdown=1><summary markdown="span">Define the formalism for Page Rank. </summary>

    \
	![](../../../static/BIG/gla2.png)

</details>

###### ==linear algebra interpretation==

6. <details markdown=1><summary markdown="span">What is the first formulation of Page Rank? What is the main issue? </summary>

    \
	The first formulation computes the ranking in the following way:
	![](../../../static/BIG/gla3.png)
	
	The most intuitive way of solving this ==recursive formulation is through flow equations==, as shown in the following. The main issue is that, in the case of web pages, these equations are in the order of millions!
	![](../../../static/BIG/gla4.png)

</details>

7. <details markdown=1><summary markdown="span">How can we fix the issue with flow equations? Explain the matrix formulation.</summary>

    \
	We can store the graph with a ==column stochastic matrix (since all columns sum up to 1)==. 
	![](../../../static/BIG/gla5.png)
	![](../../../static/BIG/gla6.png)

	We also have a rank vector of length $N$:
	![](../../../static/BIG/gla7.png)
	
</details>

8. <details markdown=1><summary markdown="span"> How can we express the vector of ranks? Why is it useful? What vector rank do we choose?</summary>

    \
	![](../../../static/BIG/gla8.png)
	
	As it can be easily seen, $\mathbb{M} \cdot \mathbb{r} = \mathbb{r}$. This implies that the ==rank vector is an eigenvector of matrix $\mathbb{M}$==  and ==it corresponds to the eigenvalue $\lambda =1$==. \ 
	We choose the rank vector for which the values add up to 1, which is associated to $\lambda = 1$. This is useful as ==column stochastic matrix have 1 as max eigenvalue, so $\mathbb{r$}$ is going to be exactly its principal eigenvector==.  \
	This can be solved iteratively with the ==power iteration method==
	
</details>

##### ==PROBABILISTIC INTERPRETATION==

9. <details markdown=1><summary markdown="span">What is the probabilistic interpretation of Page Rank?</summary>

    \
	==Consider a web crawler following the outgoing links from each page. Its behaviour can be described  as a Random Walk==. \
	![](../../../static/BIG/gla9.png)
	
	Interestingly, ==Random Walks are a known stochastic process with Markov property!==
	![](../../../static/BIG/gla10.png)
	
</details>

10. <details markdown=1><summary markdown="span">Can we say the 2 formulations are equivalent then?</summary>

    \
	![](../../../static/BIG/gla11.png)
	
	Note that a steady state indicates a situation where the  stochastic vector $\mathbb{p}^*$ does not change anymore
	
</details>

11. <details markdown=1><summary markdown="span">What conditions are necessary to ensure that both formulations work?</summary>

    \
	We are asking for both ==existence and uniqueness== of the solutions. Luckily, the ==Perron Frobenius theorem says==:
	![](../../../static/BIG/gla12.png)

</details>

##### ==GOOGLE's PAGE RANK==

12. <details markdown=1><summary markdown="span">?</summary>

    \
	

</details>