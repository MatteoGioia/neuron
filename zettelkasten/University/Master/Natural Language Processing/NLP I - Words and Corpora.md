# Words and corpora

### Recall questions

1. <details markdown=1><summary markdown="span"> What is a corpus? And an utterance?  </summary>
    
    \
    A corpus is a ==computer-readable== collection of text or speech. An utterance is ==the spoken equivalent of a sentence==, complete with pauses and micro-expressions like "uh".

</details>

2. <details markdown=1><summary markdown="span"> What is a lemma? And a word form?  </summary>
    
    \
	A lemma is a ==set of lexical forms having the same stem and similar word sense==.
	A wordform is a ==full inflected or derived form of a word==.

</details>

3. <details markdown=1><summary markdown="span">  What is the difference between word types and word tokens? What is tokenization and why it might not be easy? </summary>
    
    \
    Word types: ==set of distinct words in a corpus==. If $V$ is the vocabulary of the corpus, then $|V|$ is the amount of word types.

	Word tokens instead is ==the collection of all the words used==.

	Example: ![](../../../static/NLP/wac1.png)

</details>

4. <details markdown=1><summary markdown="span">  What are the 3 steps of text normalization?  </summary>
    
    \
    Before processing it is common to normalise text. This includes three main steps:
    - ==tokenising (segmenting) words==
    - ==normalising word formats==
    - ==segmenting sentences==

</details>

5. <details markdown=1><summary markdown="span"> Describe the Penn-Treebank algorithm. What are possible issues that you'd encounter using it?   </summary>
    
    \
    Treebank alg: ![](../../../static/NLP/wac2.png)

	Potential issues with ==foreign languages, like Chinese/Japanese==. 

</details>

6. <details markdown=1><summary markdown="span"> Describe the byte-pair encoding process. What are the 2 main components? </summary>
  
    \
    The byte pair encoding is comprised of two elements:+
    - token ==learner==: ![](../../../static/NLP/wac3.png)
    - token ==parser==

	See the slides for a full example.

</details>

7. <details markdown=1><summary markdown="span"> What is word normalization?   Describe possible steps it could include and the way they work.  </summary>
    
    \
	Word normalisation is the task of putting ==words in a "standard" format==. Some examples include:
	- making all words ==lowercase==;
	- ==lemmatization by stemming==, for example with a Porter Stemmer;
	- and so on...

</details>


7. <details markdown=1><summary markdown="span"> What is sentence segmentation?  </summary>
    
    \
    Sentence segmentation is the task of ==identifying sentences' boundaries from text==.

</details>