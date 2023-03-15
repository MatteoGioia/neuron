# Speech tagging 

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is the part of speech classification? Why is it necessary/useful ? </summary>
    
    \
   The goal of PoS (Part Of Speech) is ==classifying different words into classes==. This classification can help to ==understand context, to find mistakes= and so on.

</details>

2. <details markdown=1><summary markdown="span"> What are closed/open classes?  </summary>
    
    \
    Two main classes:
    - closed: ==new words for this class are unlikely to be coined==, e.g. prepositions;
    - open: ==new words for this class will likely be coined==, e.g. nouns or verbs.
   

</details>

3. <details markdown=1><summary markdown="span"> What is the main difficulty when determining PoS? </summary>
    
    \
   The main difficulty of tagging words is ==ambiguity==. The word "will"
   is a good example: it could be a name, a noun or even a verb depending on position and how is written.

</details>

3. <details markdown=1><summary markdown="span">  Describe the idea behind Stochastic PoS tagging. What are the main simplifications?  What do we do "in practice"? </summary>
    
    \
    The idea behind PoS stochastic tagging is to predict tag ==performing a MLE==: ![](../../../static/NLP/pos1.png)

	Using ==Bayes theorem and removing the denominator==, we can rewrite this as: ![](../../../static/NLP/pos2.png)

	To simplify things, we first assume ==probabilities to be independent (Naive Bayes)== and that ==the probability of each word only depends from its tag==: ![](../../../static/NLP/pos3.png)

	Then, we also assume that ==the prior of each tag only depends from the previous tag in the sequence== (and not the entire sequence of tags): ![](../../../static/NLP/pos4.png)

	The final formula to optimise is: ![](../../../static/NLP/pos5.png)

	If we have a ==tagged corpus==, we can now estimate probabilities using the relative frequency: ![](../../../static/NLP/pos6.png)

</details>

3. <details markdown=1><summary markdown="span">  </summary>
    
    \
   

</details>