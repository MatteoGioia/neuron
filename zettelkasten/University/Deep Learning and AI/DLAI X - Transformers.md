# Transformers

### Recall questions

1. <details markdown=1><summary markdown="span"> What is a seq2seq model? What fundamental property must be satisfied?</summary>

    \
	A ==seq2seq model== is a model that takes in input a sequence and returns a sequence.
	The ==key property of a sequential model is that the same weights apply to sequences of different lengths==. 
	![](../../../static/DEEP/tran1.png)

</details>

2. <details markdown=1><summary markdown="span"> What is the difference between causal and non-causal layers?</summary>

    \
	Two types of layer:
	- ==causal==: can ==only look backwards in time, including the present==
	- ==non causal==: ==can look backwards and in the present==, but can also ==look into the future==

	![](../../../static/DEEP/tran2.png)

</details>

3. <details markdown=1><summary markdown="span"> What is the basic idea behind auto-regressive modeling?</summary>

    \
	A common example of auto-regressive modeling is explained by the following picture, which is an example of ==next character prediction==
	![](../../../static/DEEP/tran3.png)

</details>

4. <details markdown=1><summary markdown="span"> What are possible architectures of seq2seq layers? What is the problem? Can we fix it?</summary>

    \
	We have many choices, but in general we would want a model that can look ==indefinitely far in the sequence== but also ==leverage parallel computation==. The issue is that the models seen so far cannot do this!
	
	![](../../../static/DEEP/tran4.png)

</details>

5. <details markdown=1><summary markdown="span"> Can you explain how a simple self attention mechanism works? Why we could say that we are not learning any "parameter", in a sense?</summary>

    \
	The basic idea of self attention ==is computing correlations between two inputs (see img. below) and using them to compute weights==. This weights in fact are ==not learnable==; the ==inputs might be instead the result of a learned transformation==.
	![](../../../static/DEEP/tran5.png)
	
	![](../../../static/DEEP/tran6.png)

</details>

6. <details markdown=1><summary markdown="span"> Self attention has an interesting property, what is it? Why could it detrimental in some cases?</summary>

    \
	The property of the model previously described is to ==be permutation equivariant==, since sequences are treated as sets. Depending on the task, ==this can be either a strong or weak point==.

</details>

7. <details markdown=1><summary markdown="span"> How do we make self attention parameters "learnable"?</summary>

    \
	We note that each input vector ==plays three roles==: ==key,value and query==. If we consider them ==as the output of an affine function, we can make them learnable==.
	![](../../../static/DEEP/tran7.png)

</details>

8. <details markdown=1><summary markdown="span"> How do we fix the problem mentioned in 6? How is this technique called?</summary>

    \
	We can use ==masking==, i.e. ==summing over only the previous tokens in the sequence==.
	![](../../../static/DEEP/tran8.png)
	
	Note that ==other priors can be enforced through masking==.

</details>

9. <details markdown=1><summary markdown="span"> In some cases the sequential structure of the data contains information. Because of this, we want our model to **not be permutation equivariant**. How can we achieve that?</summary>

    \
	There are many possible ways, here a few examples are listed:
	- ==position embedding==: we also ==learn an embedding for each position and we sum it to the token==
	- ==position encoding==: we ==define the position embedding== with a ==mathematical rule== a priori
	- ==relative positions==: encode the relative positions 

</details>

10. <details markdown=1><summary markdown="span"> What is a transformer then? </summary>

    \
	A transformer is ==any model that primarily uses self-attention to propagate  
	information across the basic tokens==. The goal is to combine multiple of these models.	
	![](../../../static/DEEP/tran9.png)

</details>