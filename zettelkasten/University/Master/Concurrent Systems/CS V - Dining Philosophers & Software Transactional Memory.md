# Dining Philosophers 

### Recall questions on Dining Philosophers

1. <details markdown=1><summary markdown="span"> Describe the problem of dining philosophers. </summary>
    
    \
    We have ==$N$ philosophers seated at a circular table==:
    - there is ==$1$ chopstick between each philosopher==
    - ==a philosopher must pick its 2 nearest chopsticks== in order to eat
    - ==a philosopher cannot pick two chopsticks at once== 

	![](../../../static/CS/df1.png)

	We want a solution that is ==deadlock free== and, ideally,  ==starvation free==.

</details>

2. <details markdown=1><summary markdown="span"> Describe an intuitive solution using semaphores for the previous problem. What is the main issue?</summary>
    
    \
    We could simply ==protect each chopstick with a mutual exclusion semaphore==. This solution, although simple, ==results in deadlock==.
	
</details>

3. <details markdown=1><summary markdown="span"> Describe 3 "naïve" solutions for the previous problem. </summary>
    
    \
    Some "naïve" solutions include:
	- allow ==at most $N$ philosophers at the table, where $N = M - 1$ and $M$ is the number of resources== ![](../../../static/CS/df2.png)
	- odd philosophers pick ==first left then right==, while even  philosophers pick first right then left ![](../../../static/CS/df3.png)
	- ==numbering chopsticks== and always going for the ==smallest first== ![](../../../static/CS/df4.png)
	

</details>

4. <details markdown=1><summary markdown="span"> Describe the solution for the dining philosophers that uses monitors. Is it a "perfect" solution?  </summary>
    
    \
	The key points of this solution:
	- a philosopher ==goes into eating state only if both neighbours are not eating==
	- if ==one of my neighbours is eating, and I’m hungry, they can signal() me when they’re done==

	![](../../../static/CS/df5.png)
	
	This solution, again, is ==only deadlock free and not starvation free==.

</details>

#  Software Transactional Memory

### Recall questions on SMT

1. <details markdown=1><summary markdown="span"> What is an STM system?What are the main components and what is its purpose? Answer to these last questions first.</summary>
    
    \
    Main components:
    - ==transaction==: ==atomic unit of computation== that can ==access atomic objects== that we ==assume successfully terminate when executed alone==
    - ==program==: set of sequential processes, each ==alternating between transactional and non-transactional code==

	A STM system then is ==online algorithm that has to ensure the atomic execution of the transactional code  of the program==.

	The reason for which we want to create a STM is that we want to ==group together parts of the code that must look like atomic==, in a way that is ==transparent, scalable and easy-to-use for the programmer==.
    
	
</details>

2. <details markdown=1><summary markdown="span"> How do we ensure efficient execution? What is a necessary requirement? Is it always true? </summary>
    
    \
    To guarantee efficiency, we allow ==several transactions to be executed simultaneously,== i.e. we have an ==optimistic execution approach==. To make this work, ==there must exist a total ordering of the transaction==. This total ordering, however, ==does not always exist==.
	
</details>

3. <details markdown=1><summary markdown="span"> What is the structure of a transaction? Are there any other steps besides the "usual reads and writes"? Why? </summary>
    
    \
    A transaction is composed of 3 parts:
    - ==[READ]== of an ==atomic register==
    - some ==local computation==
    - ==[WRITE]== into ==shared memory==

	However, a "4th" step is necessary in order to ==ensure consistency==, a ==try to commit== step: provided the transaction ==has not been aborted==, a process will verify whether there are ==consistency issues== before effectively writing values in the shared memory.
	
</details>

4. <details markdown=1><summary markdown="span">  How are the operations of a transaction effectively implemented?  </summary>
    
    \
    Every transaction uses a ==local working space==:
    - the ==first READ copies the value of the reg. in the local copy==; successive ==READs will then read from the local copy==
    - every ==WRITE modifies the local copy== and ==puts the final value in the shared memory only at the end of the transaction== 

	We will make use of the ==following 4 operations==: ![](../../../static/CS/smt1.png)
    
</details>

5. <details markdown=1><summary markdown="span"> What is the read prefix of a transaction? </summary>
    
    \
    Let $T$ be a transaction, its ==read prefix is formed by all its successful READ before its potential abortion==.
	
</details>

6. <details markdown=1><summary markdown="span"> When do we say an execution is opaque? </summary>
    
    \
    An execution is opaque ==if all committed transactions and all the read prefixes of all aborted  transactions appear as if executed one after the other==, by following their real-time occurrence order.
    
	
</details>

7. <details markdown=1><summary markdown="span"> Describe the system implemented by Transactional Locking 2. What is the main idea behind it? What are the 2 main checks to ensure consistency? </summary>
    
    \
    ![](../../../static/CS/smt2.png)

	Main idea behind it: ==commit a transaction $\iff$ it could appear as executed at its birth-date time==. \
	To grant consistency, we have 2 checks:
	- it $T$ reads $X$, then it ==must be that $XX.date < birthdate(T)$==
	- to commit, all ==registers accessed by $T$ cannot have been modified after $T$'s birth-date==
	
</details>

8. <details markdown=1><summary markdown="span"> Explain the implementation of each operation for the TL2 system. How do we avoid deadlock? </summary>
    
    \
    ![](../../../static/CS/smt3.png)
    
	To ==avoid deadlock, there is a total order on the registers and locks are required by respecting  this order==.

</details>

9. <details markdown=1><summary markdown="span"> How can we weaken opacity? Why would we want to do so?  </summary>
    
    \
	We can weaken opacity by ==imposing that the read prefix of an aborted transaction is consistent only w.r.t. its causal past (i.e., its virtual world)==.

	![](../../../static/CS/smt4.png)

     We can then require ==Virtual World Consistency==:  we want a ==total ordering on all committed transaction== but only a ==partial ordering on committed transactions and the read prefixes of aborted transactions.==

	WVC allows ==for more transactions to commit==, being a more ==liberal== property than opacity.
    
    ![](../../../static/CS/smt5.png)
	
</details>

9. <details markdown=1><summary markdown="span"> Describe the Vector Clock based STM system. </summary>
    
    \
     ![](../../../static/CS/smt6.png)

	Operation implementation:

	![](../../../static/CS/smt7.png)
	
</details>