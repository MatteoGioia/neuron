
Also see [[BD VI - Dimensionality Reduction]]
### Exercises

List of exercises:
- TF-IDF
- PPMI

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is the difference between world similarity and relatedness? </summary>
    
    \
	Similarity is used to refer to ==words with similar meaning==, while relatedness for ==words that are generally associated together==.

	![](../../../static/NLP/vsm1.png)

</details>

2. <details markdown=1><summary markdown="span"> What is the distributional hypothesis? </summary>
    
    \
	The distributional hypothesis says that ==similar words tend to appear in similar contexts==.

	This can be also interpreted as ==word co-occurrences reveal meaning and semantic relations==. 

</details>

3. <details markdown=1><summary markdown="span"> What is the main idea of vector semantics? How do we call these vectors? How many "types" of embeddings exist? </summary>
    
    \
    VSMs are models ==focused on word similarity==, representing each of them ==as a vector (point)== in a space. This definition makes similarity easy to define, as ==words with the same meaning appear close in space==.

	Words embedding, which ==are infinite==, can be either ==sparse or dense==.

</details>

4. <details markdown=1><summary markdown="span"> What is a term-document matrix? And a word-word occurrence matrix? </summary>
    
    \
	Example of term-document matrix and the representation built from it: ![](../../../static/NLP/vsm2.png)

	Example of word-word occurrence matrix and a possible representation built from it: ![](../../../static/NLP/vsm3.png) 

</details>

5. <details markdown=1><summary markdown="span">  What is a bags-of-word model? Why it is a "better" than the previous representation? </summary>
    
    \
    Bag of words are ==real valued multi-sets of words==, which basically means a short form for representing the vectors we were talking about: ![](../../../static/NLP/vsm4.png)

	This makes it ==more compact than the previous representations==.


</details>

6. <details markdown=1><summary markdown="span"> What is TF-IDF? </summary>
    
    \
    It's a measure that ==promotes document-specific words, penalise non-specific words==: ![](../../../static/NLP/vsm5.png)

	Note that ==term frequency is computed on a per document basis, while the $idf$ is computed across all the documents==.

	An example: ![](../../../static/NLP/vsm6.png)

</details>

7. <details markdown=1><summary markdown="span"> What is Point-wise Mutual Information? What is the main issue and how is it solved? </summary>
    
    \
    It's a metric used to ==measure the co-occurrence of words by looking at the probability of a context word and a target word appearing together==. 

	In practice, ==Positive PMI== is used to handle possible ==negative values in the $log$== (i.e. words appearing together with a $p$ smaller than chance): ![](../../../static/NLP/vsm7.png)


</details>

8. <details markdown=1><summary markdown="span"> What is a side-effect of PPMI and how do we fix it?  </summary>
    
    \
    PPMI ==tends to overestimate infrequent events==, so we can either:
    - apply ==smoothing (e.g. laplacian)==, also seen in [[NLP IV - Syntax]]
    - tweak the formula, like in the example here: ![](../../../static/NLP/vsm8.png)

</details>