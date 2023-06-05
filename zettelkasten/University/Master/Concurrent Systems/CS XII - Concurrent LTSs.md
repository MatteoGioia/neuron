# Concurrent LTSs

Exercises list:
- TBA

CCS: language to model concurrent LTS

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is lacking in the original definition of LTSs? What are possible solutions (2)? </summary>
    
    \
    The current LTS model lacks:
    - ==simultaneous execution of processes==
    - ==inter-process interaction==

	We can fix this using:
	- ==parallel composition + interleaving semantics==
	- ==producer/consumer paradigm==

</details>

2. <details markdown=1><summary markdown="span"> What are events and co-events?</summary>
    
    \
	Given a set of names ==$N$ that denotes events==:
	- ==$a \in N$ denotes the consumption of event $a$==
	- ==$\bar{a} \in N$ denotes the production of event $a$==

	==$a,\bar{a}$ are two complementary actions== used by $p_i$'s to ==synch on action $a$==
   
</details>

3. <details markdown=1><summary markdown="span"> Is synchronization visible from the outside?</summary>
    
    \
    No, it only ==produces an event that we denote with $\tau$.==

	The set of ==possible action thus becomes $A = N \cup \bar{N} \cup \{\tau\}$==

   
</details>

4. <details markdown=1><summary markdown="span"> How can we restrict names to make them behave similarly to "local" variables in code? </summary>
    
    \
    We use the ==restriction operator $P/a$ to restrict the scope of name $a$ to process $P$.==

   
</details>

5. <details markdown=1><summary markdown="span"> Describe and explain the new formalism and the updated set of inference rules. </summary>
    
    \
    New formalism: ![](../../../static/CS/clts1.png)

	New inference rules: ![](../../../static/CS/clts2.png)

   
</details>

6. <details markdown=1><summary markdown="span"> Prove the image finiteness theorem. </summary>
    
    \
	Image finitess theorem (i.e. ==inference tree height is limited==): 
	![](../../../static/CS/clts3.png) ![](../../../static/CS/clts4.png) ![](../../../static/CS/clts5.png)
   
</details>

7. <details markdown=1><summary markdown="span"> What are re-namings? Prove that non-conflicting re-namings do not influence the original LTS.</summary>
    
    \
    Renamings are ==functions $\sigma \ : N \to N$== (i.e. that change names).
    We let:
    - $\sigma(\bar{a}) = \bar{\sigma(a)}$
    - $\sigma(\tau) = \tau$

	The rules are applied as follows: ![](../../../static/CS/clts6.png)

	We can then prove the following theorem: ![](../../../static/CS/clts7.png) ![](../../../static/CS/clts8.png)
   
</details>

8. <details markdown=1><summary markdown="span"> Prove that restricting the only transition for a process makes it bi-similar to 0. </summary>
    
    \
	Proof: ![](../../../static/CS/clts9.png)
   
</details>

9. <details markdown=1><summary markdown="span"> Prove the idempotency of sum. </summary>
    
    \
	Proof: ![](../../../static/CS/clts10.png)
   
</details>

10. <details markdown=1><summary markdown="span"> Describe an implementation for semaphores using CCS. </summary>
    
    \
    We can write down the formulation for a semaphore as shown here: ![](../../../static/CS/clts11.png)

	Note that the binary semaphore can be simulated by 2 unary semaphores in parallel, i.e. $(S^{(1)} | S^{(1)})$
   
</details>


11. <details markdown=1><summary markdown="span"> What is congruence? Why is it important to prove that bi-similarity is a congruence? Outline the proof for the congruence of bi-similarity theorem. </summary>
    
    \
    Congruence effectively ==allows us to use equivalent (in our case bi-similar) LTS interchangeably==.  To effectively prove this property, we ==first need to define an execution context==: ![](../../../static/CS/clts12.png)

	The updated formalism for CCS including contexts is now: ![](../../../static/CS/clts13.png)

	We can now prove that: ![](../../../static/CS/clts14.png)

	To prove this theorem, it is easier to deconstruct it in smaller pieces:
	![](../../../static/CS/clts15.png)![](../../../static/CS/clts16.png)![](../../../static/CS/clts17.png)![](../../../static/CS/clts18.png)


</details>