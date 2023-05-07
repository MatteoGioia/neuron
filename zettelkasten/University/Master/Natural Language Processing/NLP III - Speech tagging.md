# Speech tagging 

### Exercises

List of exercises:
- viterbi algorithm

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is the part of speech classification? Why is it necessary/useful ? </summary>
    
    \
    The goal of PoS (Part Of Speech) is ==classifying different words into classes==. This classification can help to ==understand context, to find mistakes== and so on.

</details>

2. <details markdown=1><summary markdown="span"> What are closed/open classes?  </summary>

    \
    Two main classes:
    - closed: ==new words for this class are unlikely to be coined==, e.g. prepositions;
    - open: ==new words for this class will likely be coined==, e.g. nouns or verbs.

</details>

3. <details markdown=1><summary markdown="span">  What is the main difficulty when determining PoS? </summary>
    
    \
    The main difficulty of tagging words is ==ambiguity==. The word "will" is a good example: it could be a name, a noun or even a verb depending on position and how is written.

</details>

4. <details markdown=1><summary markdown="span">  Describe the idea behind Stochastic PoS tagging. What are the main simplifications?  </summary>
    
    \
    The idea behind PoS stochastic tagging is to predict tag ==performing a MLE==: ![](../../../static/NLP/pos1.png)

	Using ==Bayes theorem and removing the denominator==, we can rewrite this as: ![](../../../static/NLP/pos2.png)

	To simplify things, we first assume ==probabilities to be independent (Naive Bayes)== and that ==the probability of each word only depends from its tag==: ![](../../../static/NLP/pos3.png)

	Then, we also assume that ==the prior of each tag only depends from the previous tag in the sequence== (and not the entire sequence of tags): ![](../../../static/NLP/pos4.png)

	The final formula to optimise is: ![](../../../static/NLP/pos5.png)

	If we have a ==tagged corpus==, we can now estimate probabilities using the relative frequency: ![](../../../static/NLP/pos6.png)

</details>

5. <details markdown=1><summary markdown="span">  What is a Hidden Markov Model? Why do we use it?</summary>
    
    \
    Although we presented a way to "estimate" both the likelihood and the prior, we still ==need to find the global PoS tag sequence which maximises the final product==!

	To achieve our goal, we can use a ==Hidden Markov Model==: ![](../../../static/NLP/pos7.png)

	The great thing about HMM is that they ==respect our previous assumptions==:
	- ==the probability of ending in the next state only depends from the current state (Markov Assumption / Bi-gram assumption)== ![](../../../static/NLP/pos8.png)
	- ==the probability of a word being emitted depends only from its tag (output independence)== ![](../../../static/NLP/pos9.png)

</details>

6. <details markdown=1><summary markdown="span">  How do we apply the HMM in practice?</summary>
    
    \
    In practice, ==given a training dataset, i.e. a PoS tagged corpus==, ==$Q$ is the tagset, $O$ is the set of words==, $\pi$ is computed by counting how many times a PoS tag occurs at the start of a sentence.

	The probabilities can be computed as show in q.4
	
</details>

7. <details markdown=1><summary markdown="span"> What is MaxEnt? How is the probability for a certain class computed?  </summary>
    
    \
    MaxEnt belongs to the family of classifiers known as the ==exponential or log-linear classifiers==. It works by extracting a set of ==features $f_1 \dots f_n$ from the input== and combining them linearly.

	The goal is to maximise the following probability: ![](../../../static/NLP/pos10.png)
   

</details>

--- 

Note that the class can also be predicted using logistic regression, see [[BD IX - Logistic Regression]]