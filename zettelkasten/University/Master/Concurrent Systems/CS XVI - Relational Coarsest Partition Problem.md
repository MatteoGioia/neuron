# Alternatives way of proving bi-similarity pt.3

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is the relational coarsest partition problem? How is it related to deciding bi-similarity? </summary>
    
    \
    RPCC is a generic problem that can be described as follows:
    - start from a given ==set partitioned in the coarsest way possible==, e.g. the entire set;
    - using a ==splitting rule==, divide the set into ==smaller blocks of equivalent elements and repeat until splitting is not possible anymore==;
    - output the final solution, two ==elements are equivalent if they are in the same block==

	As it can be seen, RPCC is a more generic problem than bi-similarity. In fact, the ==splitting rule used in RPCC== is what effectively decides which equivalence the algorithm is proving.
    
</details>

2. <details markdown=1><summary markdown="span"> What is the condition for splitting a block in the algorithm? </summary>
    
    \
	Let $B$ be a generic block of a partition and $s,t$  be two states $\in B$.  
	Let us call $block(s)$ the set of states belonging to the same block as $s$.  
	According to bi-similarity, ==$s$ and $t$ must be separated (and, hence, $B$ must be split) if and only if==: ![](../../../static/CS/algo1.png)

	This condition can be ==also formulated as==: ![](../../../static/CS/algo2.png)
  
</details>

3. <details markdown=1><summary markdown="span"> Describe the algorithm for solving the RCPP. Use the example as an aid. </summary>
    
    \
	The algorithm works as follows: ![](../../../static/CS/algo3.png)

	Where the splitting condition is: ![](../../../static/CS/algo4.png)

</details>

4. <details markdown=1><summary markdown="span"> Prove that the algorithm works. </summary>
    
    \
    ==Termination== can be easily proved:
    - every cycle operates on a finite number of elements
    - the cardinality of $P$ is at most $|S|$ (worst case, a block for each state)
    - in this case, no block can be split further and we terminate.

	We now want to prove ==soundness==, i.e. that $s \sim t \iff \exists B \in P_f | \{s,t\} \in P_f$

	![](../../../static/CS/algo5.png)![](../../../static/CS/algo6.png)
    
  
</details>

5. <details markdown=1><summary markdown="span"> What is the complexity of the algorithm proposed?  </summary>
    
    \
    Let $n = |S$ and $m = |\to|$. Then, consider the number of executions in the main function's body:
    - last loop costs $O(n)$
    - main loop is executed $O(n)$ times at worst
    - the check in the if condition and updating the partition costs $O(1)$

	We need to determine how expensive is looping over every state, every transition and then checking whether we split or not: ![](../../../static/CS/algo7.png)

	==The final cost is then $O(nm)$.==
  
</details>

6. <details markdown=1><summary markdown="span"> Describe an efficient way to implement the algorithm.  </summary>
    
    \
    We build a symbolic representation for the blocks as follows:
    - every ==block is a list of states==
    - every ==block is associated to a binary string== 

	Then, we consider a table of triples $(\alpha, s, \sigma)$, where $\sigma$ is the binary index of a certain block: ![](../../../static/CS/algo8.png)

	Ordering this table lexicographically requires $O(m\log m)$ at the start, but ==updates do not require reordering==. The update is then done as follows: ![](../../../static/CS/algo9.png)

</details>