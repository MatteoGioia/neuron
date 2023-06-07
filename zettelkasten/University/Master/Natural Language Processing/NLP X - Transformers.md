Also see:
- [[AML VI - Transformer networks]]

Exercises:
- [x] transformers dimension check
### Recall questions on transformers 

1. <details markdown=1><summary markdown="span">  Describe the main limitations of recurrent models before transformers.</summary>
    
    \
    Two main issues:
    - ==linear time dependency==: two words require $O(T)$ time steps to interact, where $T$ is the sequence lenght;
    - ==lack of parallelisation==: $O(T)$ non parallel steps for each sequence.
    
</details>

2. <details markdown=1><summary markdown="span"> What is a possibile alternative that uses an architecture already tested on images? </summary>
    
    \
    We can use ==convolution==, as shown in the linked notes under the section "temporal convolution":  [[AML V - Sequence models]]
    
   
</details>

3. <details markdown=1><summary markdown="span">  Give a brief list of popular attention forms.</summary>
    
    \
    Attention types:
    
   
</details>


4. <details markdown=1><summary markdown="span">  Describe a classical ML problem in which attention was first seen and why it is relevant.  </summary>
    
    \
    First seen in ==Nadaraya-Wattson regression== (with various kernels for attention):
    ![](../../../static/NLP/tf1.png)

	The point is: why not ==learn the kernel (attention)== instead of manually tuning it?

</details>

1. <details markdown=1><summary markdown="span"> What happens to the output of each self-attention module? </summary>
    
    \
    A ==feed forward neural network is applied to each vector in output
   
</details>

1. <details markdown=1><summary markdown="span">  </summary>
    
    \
   
</details>

Also see:
- positional encoding
- masked self attention
- multi-head attention (cutting dimensionality)
- scaled dot product
- layernorm

### Recall questions BERT, pre-training