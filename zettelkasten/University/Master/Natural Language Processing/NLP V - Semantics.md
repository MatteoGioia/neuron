
### Exercises

List of exercises:

### Recall questions 

1. <details markdown=1><summary markdown="span"> What  is syntax driven semantic analysis? What is a possible solution to implement it?  </summary>
    
    \
	As the name suggests, it is a kind of ==semantic analysis driven by syntax==: ![](../../../static/NLP/sem1.png)

	One possible solution is to ==augment CFGs with semantic meanings, using first order logic==.

</details>

2. <details markdown=1><summary markdown="span"> How can we use lambda calculus to further generalise semantic analysis? Why it is, again, kind of unfeasible?  </summary>
    
    \
    Lambda notation can be used ==to abstract from fully specified FOL==, creating rules that can generate new FOL expressions:

	![](../../../static/NLP/sem2.png)

	This technique, however, has 2 drawbacks:
	- it is ==difficult== to perform
	- ==assumes that each terminal has just one meaning==
    

</details>

3. <details markdown=1><summary markdown="span">  Describe the idea behind lexical semantics. </summary>
    
    \
	The idea of lexical semantics is to ==concentrate on the single words and to understand their meaning==

</details>

4. <details markdown=1><summary markdown="span"> What are word senses? Does a word have just one sense?  Why is choosing the right word sense difficult? </summary>
    
    \
	The term ==word sense is a synonym for word meaning==. Each word can have ==multiple senses==. Choosing the right sense is often complicated by numerous factors:
	- homonymy
	- metonymy 
	- metaphors
	- personification
	- and so on...

	We'll thus ==first focus on how to represent word senses, and then on how to disambiguate==. 

</details>

5. <details markdown=1><summary markdown="span">  How can we represent word senses? Describe the various strategies. </summary>
    
    \
	To describe word senses, we have various strategies:
	- ==enumeration==: using a ==sense inventory== to store all possible meanings and using the ==words in the context to activate one of them==: ![](../../../static/NLP/sem3.png)
	- ==graded word senses==: use ==annotators to create generative rules== to describe the senses (similar to PoS tagging): ![](../../../static/NLP/sem4.png)
	- ==computational lexicons==: ==machine readable dictionaries==

</details>

6. <details markdown=1><summary markdown="span">  What is WordNet? Why is it more than a simple graph? </summary>
    
    \
    WordNet is a ==computational lexicon of English==, expressing each ==word as a synset (group of synonyms)==. On top of that, each word is connected to the others via ==lexical and semantics links==, creating a graph that is effectively a ==semantic network==.

	![](../../../static/NLP/sem5.png)

</details>

7. <details markdown=1><summary markdown="span"> What is BabelNet? How does it "extend" WordNet?  </summary>
    
    \
	BabelNet is another ==computational lexicon==, however it is ==multilingual== and it includes multiple sources: ![](../../../static/NLP/sem6.png)

</details>

8. <details markdown=1><summary markdown="span"> What is word sense disambiguation? </summary>
    
    \
    Given ==a word in context and a fixed inventory of possible word senses==, the goal is to ==decide the most suitable synset== if there is one.

</details>

9. <details markdown=1><summary markdown="span"> What is entity linking?  </summary>
    
    \
    Entity linking is the ==task of assigning a unique identity to entities== (such as famous individuals,  locations, or companies) mentioned in text: ![](../../../static/NLP/sem7.png)
	

</details>

7. <details markdown=1><summary markdown="span"> </summary>
    
    \
	

</details>