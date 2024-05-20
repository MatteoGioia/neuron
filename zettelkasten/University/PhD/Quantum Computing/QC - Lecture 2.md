# Lecture 2

## Part One

### Recall questions


1. <details markdown=1><summary markdown="span"> Are quantum algorithms probabilistic? How is randomness generated?  </summary>
    
    \
	    ![](../../../static/IQC/qc13.png)
	    Randomness is implicit to quantum computers, no need for PRGNs.

</details>


2. <details markdown=1><summary markdown="span"> What is the state of a qbit? What is the true state?  </summary>
    
    \
	    ![](../../../static/IQC/qc1.png)
		 $\alpha$ and $\beta$ are ==probability amplitudes==. Note that the ==true state of a qbit cannot be observed==.

</details>


3. <details markdown=1><summary markdown="span">  How is one able to find the content of a qbit?  </summary>
    
    \
	    ![](../../../static/IQC/qc2.png)
	    Note that ==once observed, the state of the qbit is going to be fixed to be either ..==
    

</details>


4. <details markdown=1><summary markdown="span"> Are quantum transformations linear? What does this imply?  </summary>
    
    \
    Yes, and this implies that ==they can be expressed as a product of matrices==.
     ![](../../../static/IQC/qc14.png)
    

</details>


5. <details markdown=1><summary markdown="span">  Describe the Pauli matrices used in Qbit gates </summary>
    
    \
     Three very common matrices:
     - $\sigma_x$ aka ==NOT==: $\begin{pmatrix}0&1\\1&0\end{pmatrix}$
     - $\sigma_y$ and $\sigma_z$: ![](../../../static/IQC/qc15.png)
    

</details>


6. <details markdown=1><summary markdown="span"> What is the Hadamard matrix and why is it useful? Can you think of a practical application?  </summary>
    
    \
	    ![](../../../static/IQC/qc16.png)
		 This matrix allows to ==go from a classical state to a quantum state of superposition!==.
		 A cool application is a ==generator of a truly random 50/50 0-1 bit==, as the amplitude $\frac{1}{\sqrt{2}}$ will return two bits with probability $\frac{1}{2}$ each.

</details>


7. <details markdown=1><summary markdown="span"> What is a necessary requirement for matrices expressing transformations that preserve quantum states?   </summary>
    
    \
	      ![](../../../static/IQC/qc17.png)
		  Matrices must be ==unitary== , i.e. they must preserve the original norm. In the case of qbits, where it is bound to be $1$, it must preserve it in order for probabilities to sum up to $1$ when measured.
    

</details>


1. <details markdown=1><summary markdown="span"> What is the appropriate abstraction used to represent qbits?  </summary>
    
    \
    

</details>

## Part Two

### Recall questions


1. <details markdown=1><summary markdown="span"> Explain how the following example of tensor product of qbits works. </summary>
    
    \
	    

</details>


1. <details markdown=1><summary markdown="span">  What are entangled states? Can you make an example of one and what this state entails? </summary>
    
    \
	    

</details>


1. <details markdown=1><summary markdown="span">  </summary>
    
    \
	    

</details>