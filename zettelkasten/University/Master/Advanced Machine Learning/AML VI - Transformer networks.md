# Transformer networks

### Recall questions

1. <details markdown=1><summary markdown="span"> What is attention and how is it used? Use the RNN translation example, leveraging context at each step.  Are we limited to text only? </summary>
    
    \
    In the following image, we can see a common pipeline for ==text translation== leveraging RNNs.
    
    ![](tr1.png)

	The main issue here is given by the fact that not only we have a bottleneck on the ==size of the context==, but also ==that is harder to propagate information in the later stages of the pipeline==. Ideally, ==we'd want to use a new context vector at each step in order to "refresh" the relevant information==. \
	That is exactly what we do through ==attention==, as shown in the following image.

	![](tr2.png)

	In the net step, we are going to use $s_2$ to compute alignments and the new attentions, which will be multiplied together to compute the new context. \
	We can visualise ==how the context "changes" accordingly to the examined part in the following example==.

	![](tr3.png)

	We can use this approach for a multitude of tasks, as shown in ==image captioning with attention here==:

	![](tr4.png)

	Even if it's not shown here, the context is recomputed at each step.

</details>


2. <details markdown=1><summary markdown="span"> What is the shape of a general attention layer? Describe the key operations. What important property does attention have? Is it a good thing? </summary>
    
    \
	Here we see the =="unrolled" version of a general attention layer (only one head)==:
	![](tr5.png)

	Note that ==attention operation is permutation invariant==: this means that it does not "care" about the ordering of the vector. ==It generally isn't a good thing==, for instance when solving tasks like translation of sequences in which the position of a word does matter.

</details>


3. <details markdown=1><summary markdown="span">  What is the most recent choice for alignment? What tweak is necessary to make it work (hint: softmax peaks) ? </summary>
    
    \
    We have possible choices for ==alignment==:
	![](tr6.png)

	The main trick we use is diving by a factor of $\sqrt D$, otherwise the ==dot product== explodes creating ==peaks in the softmax==.

</details>


4. <details markdown=1><summary markdown="span">So what are keys, queries and values and why do we transform them?  What is the difference between attention and self-attention?</summary>
    
    \
    We transform the input and hidden states because ==we want more expressiveness  - otherwise the scaled dot product wouldn't work (being just "linear").

	![](tr7.png)

	In many cases we might want to compute queries starting from the inputs too. This is the case of ==self attention==.

	![](tr8.png)

</details>


5. <details markdown=1><summary markdown="span"> What is positional encoding and what is its purpose? What are the desired characteristics for it? What are some possible choices?</summary>
    
    \
	==Positional encoding "fixes" (probably?) the positional invariance of attention.==
	A good way of putting it would be: *"when you read positional encoding, you know exactly where you are in the sentence and how far you are from the other words"* \
	We want it to:

	![](tr9.png)

</details>


6. <details markdown=1><summary markdown="span"> What is masked self attention and why is it necessary?</summary>
    
    \
	We mainly use ==masked attention/self attention to avoid looking at future inputs== in the vector. One easy example would be next word prediction, in which knowing the next word would be considered cheating!

	![](tr10.png)

</details>


7. <details markdown=1><summary markdown="span"> Briefly describe the architecture of the transformer network presented by Vaswani et al. </summary>
    
    \
	Overview of whole model:

	![](tr11.png)

	Zoomed in encoder:

	![](tr12.png)

	Zoomed in decoder (==note that input for attn is encoder output==)
	
	![](tr13.png)

</details>

#### Transformer network applications


9. <details markdown=1><summary markdown="span"> How can transformers be adapted to handle images? What are possible operations we can do? </summary>
    
    \
	Possible ops:
	- ==prediction/classification==
	- ==conditional image completion==
	- ==super-resolution== on celebA
	- ==captioning== with Visual Transformers

</details>


10. <details markdown=1><summary markdown="span"> What is relative self attention? </summary>
    
    \
	It's a variant of attention that computes the positional encoding as the result of ==another convolution==.

	![](tr14.png)

</details>

#### Transfer learning



11. <details markdown=1><summary markdown="span"> What is the issue with bi-directionality in transformers?</summary>
    
    \
	We don't want ==words to "see themselves". Additionally, directionality is needed to generate well formed probability distributions==.

	![](tr15.png)

</details>


12. <details markdown=1><summary markdown="span"> Which approach was  in BERT in order to address those previously mentioned issues when dealing with next word prediction?</summary>
    
    \
    In BERT, ==15% of the words are masked==, in the following way (to account for the fact that ==we do not see masking tokens in fine tuning==):
    - 80% replaced with mask
    - 10% replaced with ==random word==
    - 10% replaced with ==same word==
	

</details>


13. <details markdown=1><summary markdown="span"> What about sentence order (i.e. next sentence prediction)?</summary>
    
    \
	Use additional encodings:
	![](tr16.png)

</details>


14. <details markdown=1><summary markdown="span"> What are ROBERTA and ELECTRA?</summary>
    
    \
    ==RoBERTa==: simply a ==BERT trained for more epochs and more data==, that outperformed original performance. \
    ==ELECTRA==: ==pretrain BERT as discriminator== lead to less computations and better performance
	

</details>


15. <details markdown=1><summary markdown="span"> What is distillation? (hint: teacher, student)</summary>
    
    \
	![](tr17.png)

</details>