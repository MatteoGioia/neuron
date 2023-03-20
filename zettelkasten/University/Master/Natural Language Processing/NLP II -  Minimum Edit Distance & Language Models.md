# Language Models


### Exercises

List of potential exercises:
- computing the MED
- computing probabilities for a N-gram model (see final slides)
- exercises on Laplacian smoothing

### Brief Recap on Minimum Edit Distance

For this section, review the algorithm presented in 1.6 (Spelling and Mistakes correction).

### Recall questions on Language Models

1. <details markdown=1><summary markdown="span">  What is a language model? Why would we want to use one over a formal grammar?  </summary>
    
    \
    A language model is a ==probabilistic distribution over sequences of words==.
    In general, it is more ==flexible== compared to formal grammars, that only provide a binary choice when deciding whether or not a string belongs to the language.

</details>

2. <details markdown=1><summary markdown="span">  What is relative frequency estimation? Why using it with language models is unfeasible? </summary>
    
    \
    In our context, we refer to estimating the relative frequency of a sequence of words by ==counting how many times a sequence appears, then applying the conditional probability over that sequence==: ![](../../../static/NLP/lm1.png)

	This way of computing probabilities is very ==computationally expensive==: imagine applying the chain rule to the entire sequence (we'd also need to compute all the probabilities of the shorter sentences)! 

</details>

3. <details markdown=1><summary markdown="span">  What is the intuition behind N-gram models? Show you understanding by computing the formulas for the 2-gram and 3-gram. (Hint: Markov)</summary>
    
    \
    The intuition of the N-gram model is that ==we assume the Markov property to approximate the history of a sequence by just the last N-1 words==:

	![](../../../static/NLP/lm2.png)

	Formulas for 2/3-gram: ![](../../../static/NLP/lm3.png)

</details>

4. <details markdown=1><summary markdown="span"> What are the advantages of big/small N-gram models? And cons? </summary>
    
    \
    In general:
    - a ==larger N== implies ==more information about the context of a sequence==, but suffers more from ==sparsity and bias w.r.t. to the most frequent sentences==;
    - a ==smaller N== is ==less "precise"==, but provides more ==examples of statistical significance (i.e. more samples)==.

</details>

5. <details markdown=1><summary markdown="span">  What is Zipf's law? What does this imply? </summary>
    
    \
    Zipf's laws tells us that ==the frequency of any word is inversely proportional to its rank in the frequency table with exponential decay==: ![](../../../static/NLP/lm4.png)

	This implies that there will be a large amount of words for which there is a ==low probability==, creating a ==bias in our model==.

</details>

6. <details markdown=1><summary markdown="span">  What is the difference between closed and open vocabulary? </summary>
    
    \
    Vocabulary types:
	    - closed: we have a ==fixed vocabulary== and all ==words in the test set will be from such vocabulary==
	    - open: we model unknown words as ==Out-Of-Vocabulary Words== (OOV). We ==convert them to a token (UNK)== of which we also estimate the probability, just like any other word.

</details>

7. <details markdown=1><summary markdown="span">  What is the difference between intrinsic and extrinsic evaluation metrics? Give an example of intrinsic metric for language models. </summary>
    
    \
    Types of metric:
    - extrinsic: assesses the quality of the model through "in-vivo" testing, i.e. embedding the model
    - intrinsic: assesses the quality of the model via internal metrics

	In the case of language models, we use ==perplexity==:
		- perplexity for a ==word sequence==: ![](../../../static/NLP/lm5.png)
		- perplexity for a ==corpus==: ![](../../../static/NLP/lm6.png)

</details>

8. <details markdown=1><summary markdown="span"> What is smoothing? Why is it necessary? </summary>
    
    \
    Smoothing is necessary ==to counter sparsity and take into account unigrams not seen in training==.

</details>

9. <details markdown=1><summary markdown="span"> Describe the steps for laplacian smoothing. What is the main drawback of using it? </summary>
    
    \
    Laplacian smoothing consists in ==simply adding 1 to the count of each unigram==; it is in fact also know as ==add one smoothing==.

	![](../../../static/NLP/lm7.png)

	The issue with Laplacian smoothing is that is a very ==imprecise (?) instrument, in the sense that it shifts a lot of probability mass to the zeros==, resulting in heavy discounts for the existing probabilities. 

</details>

10. <details markdown=1><summary markdown="span"> What is the add-k smoothing?  </summary>
    
    \
    Add-k smoothing is a ==generalized version of Laplacian smoothing in which a $k$ value is added instead==: ![](../../../static/NLP/lm8.png)

    It still suffers from the same issue of Laplacian smoothing, but it can be mitigated through hyper-parameters tuning.

</details>

12. <details markdown=1><summary markdown="span"> Describe model combination methods. Which techniques are available?  </summary>
    
    \
    We have different alternatives:
    - ==linear interpolation==: ![](../../../static/NLP/lm10.png)
    - ==katz back-off==: ![](../../../static/NLP/lm11.png)
    - ==stupid back-off==: ![](../../../static/NLP/lm9.png)
    - ==absolute discount==: ![](../../../static/NLP/lm12.png)

</details>
