# Visual search

### Recall questions on object search

1. <details markdown=1><summary markdown="span"> Describe the most popular standard techniques (in the past) for object search.  What is the main issue with them? </summary>
    
    \
	Popular techniques ==in the past==:
	- ==histograms/shape descriptors==
	- ==local representations/interest points detectors==: SIFT/Harris PD
	- ==global representation==: visual codebook starting from bag of local descriptors

	==Local features descriptors== have been shown to work the best, however they ==require lots of computational power==.

</details>

2. <details markdown=1><summary markdown="span">  What was the first deep approach for object search? Why doesn't it work well? </summary>
    
    \
	The first deep approach was ==using a pre-trained CNN to output the feature vectors==. The main issue here is that a ==CNN is trained to recognise many generic instances of a class, while we are interested in one specific object!==

</details>

3. <details markdown=1><summary markdown="span"> Describe the R-MAC feature descriptor and the network used for object search presented by Gordo et al.  </summary>
    
    \
	R-MAC feature descriptor:

	![](../../static/AML/os1.png)

	The network used for solving object search is the following and is ==trained with a triplet loss.== (more on this in the following question)

	![](../../static/AML/os2.png)

</details>

4. <details markdown=1><summary markdown="span"> Describe the loss used for training the network of qst. 3 </summary>
    
    \
    The loss used is a ==triplet loss==:
	![](../../static/AML/os3.png)

</details>

5. <details markdown=1><summary markdown="span"> Describe three main issues of object search and discuss their solutions. </summary>
    
    \
	Main issues:
	![](../../static/AML/os4.png)

</details>

## Recall questions on person search


6. <details markdown=1><summary markdown="span"> What is person re-identification? Why is it a good base for person search? </summary>
    
    \
	In person re-id, we focus on ==retrieving the same person from different cameras. This works well for search as we assume image crops are produced by the person detector==.

	![](../../static/AML/os5.png)

</details>

7. <details markdown=1><summary markdown="span"> What is a really simple approach for person re-id? What are a few things we need to pay attention to? </summary>
    
    \
	Idea: use ==same structure used for object search with a few tweaks==:
	![](../../static/AML/os6.png)

	==Hard triplets are triplets where the positive/negative are really close==.

</details>

8. <details markdown=1><summary markdown="span"> Briefly describe the OIM model for person search .</summary>
    
    \
    Online Instance Matching:

	![](../../static/AML/os7.png)

</details>

9. <details markdown=1><summary markdown="span"> Describe the structure proposed in QEEPS. What is its main benenifit? </summary>
    
    \
	==Query guided end to end person search==:

	![](../../static/AML/os8.png)

	Main benefit: ==can train end to end using query image extensively==.

</details>


## Recall questions on semantic search

9. <details markdown=1><summary markdown="span"> What is a good way to create descriptors for semantic search? </summary>
    
    \
	![](../../static/AML/os10.png)
	

</details>

