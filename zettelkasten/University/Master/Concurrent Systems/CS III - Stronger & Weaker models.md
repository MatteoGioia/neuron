# Hardware assisted primitives

### Recall questions

1. <details markdown=1><summary markdown="span">  What are specialised hardware primitives?  </summary>
    
    \
    Specialised hardware primitives ==are combinations of instructions that behave atomically==. Operative systems often provide one of (or more):
    - ==test & set==: atomic ==read+write of boolean register== ![](../../../static/CS/swm1.png)
    - ==swap==: atomic ==read+write of a general register== ![](../../../static/CS/swm3.png)
    - ==fetch & add==: atomic ==read+increment of an integer register== ![](../../../static/CS/swm6.png)
    - ==compare & swap==: atomic ==comparison+write of general register + returns boolean result of the comparison== ![](../../../static/CS/swm4.png).
    
</details>

2. <details markdown=1><summary markdown="span">  Describe how we can implement mutual exclusion with the new primitives. </summary>
    
    \
    ==Test & Set==: ![](../../../static/CS/swm2.png)

	==Swap==: adapt previous implementation: note that ==X.test&set()=X.swap(1)==.

	==Compare & Swap==: ![](../../../static/CS/swm5.png)
    
</details>

3. <details markdown=1><summary markdown="span">  Why is fetch and & add "better" than previous solutions? What does it guarantee?  </summary>
    
    \
    All previous solutions ==guarantee deadlock freedom== but ==no starvation freedom==. One solution, besides using ==round robin==, would be using the ==fetch&add== primitive that grants ==bounded bypass with bound $n-1$==.

	![](../../../static/CS/swm7.png)

</details>

4. <details markdown=1><summary markdown="span">  What are safe registers? What happens when different operations overlap? Why? </summary>
    
    \
	We are interested in implementing ==mutual exclusion in contexts in which atomicity for registers is not granted==. \
	We describe 2 types of ==safe registers==:
	- ==MRSW Safe register==:
		1. every ==read that does not overlap with a write returns the value stored== in the register
		2. a ==read that overlaps with a write can return any value== from the register domain
	- ==MRMW Safe register==:
		1. behaves ==like MRSW Safe register when write operations do not overlap==
		2. otherwise it ==can contain any value== from the register domain. 

</details>

5. <details markdown=1><summary markdown="span">  Describer how the bakery algorithm works (hint: ticket). As usual, prove mutual exclusion and ...</summary>
    
    \
    Every process gets a ticket, the smallest pair grants access to the C.S. (typo in image, $MY\_TICKET[i]$ should be $MY\_TURN[i]$):
    ![](../../../static/CS/swm8.png)

	Proofs for:
	- lemma 1:  ![](../../../static/CS/swm9.png)
	- lemma 2:    ![](../../../static/CS/swm14.png)
	- mutual exclusion and ==bounded bypass with bound $n-1$==: ![](../../../static/CS/swm15.png)

</details>

6. <details markdown=1><summary markdown="span">  What is Aravind's algorithm? What problem does it solve? Explain the proofs for mutex and bounded bypass. </summary>
    
    \
    ![](../../../static/CS/swm10.png)

	This solves the problem that ==registers in the bakery's algorithm are unbounded==, and can be potentially increased to the point of overflowing.

	Proof for mutex:
	![](../../../static/CS/swm11.png)

	Proof for bounded bypass:
	![](../../../static/CS/swm12.png)
	![](../../../static/CS/swm13.png)

</details>

7. <details markdown=1><summary markdown="span">  Bonus exercise: improvement for aravind's algorithm.  </summary>
    
    \
    ![](../../../static/CS/bns1.png)
    
</details>