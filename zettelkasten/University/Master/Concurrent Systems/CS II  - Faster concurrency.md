# Faster protocols to handle mutex

### Recall questions

1. <details markdown=1><summary markdown="span">  Describe a way to reduce the cost of Peterson's algorithm. Why is it still not enough? </summary>
    
    \
    We use Peterson's algorithm in ==a tournament between processes==:
    
    ![](fc1.png)

	Since ==we have 2 processes in competition that take $O(1)$ and at most $log_2 n$ competition, the cost is $\rceil log_2 n\lceil$.==
    While this works well, we might ==want an algorithm that is constant in time==.
    
	
</details>

2. <details markdown=1><summary markdown="span"> Describe the idea for a faster mutual exclusion algorithm. What are the 2 main issues? </summary>
    
    \
    ![](fc2.png)
    Issues:
    - a process $p_i$ might write $X$ as the last one, but find the door closed
    - "FAIL" should be removed in order to handle failure inside the lock call
	
</details>

3. <details markdown=1><summary markdown="span">  Describe Lamport algorithm for faster mutual exclusion. Which form of liveness does it have? Prove safety & liveness. </summary>
    
    \
    ![](fc3.png)

	Note that ==without competition, this algorithm completes in $O(1)$==.
	It of course grants mutual exclusion:

	![](fc4.png)

	But only ==deadlock freedom==:

	![](fc5.png)

</details>

4. <details markdown=1><summary markdown="span">  Recap the cost of every algorithm seen so far. </summary>
    
    \
    With atomic R/W registers, we have:
    - if $n = 2$, a $O(1)$ algorithm with bounded bypass of $1$ (Peterson)
    - if $n >2$:
	    - $O(n^2)$ algorithm that satisfies starvation freedom (Peterson)
	    - $O(log n)$ algorithm that satisfies that satisfies bounded bypass with bound $\rceil log_2 n\lceil$ (max. number of competitions)
	    - $O(1)$ algorithm that satisfies deadlock freedom
	
</details>

5. <details markdown=1><summary markdown="span">  How can we transform a deadlock free algorithm into a bounded bypass one? What is the tradeoff?</summary>
    
    \
    We can transform ==any algorithm that grants deadlock freedom into a bounded bypass one== but its complexity will ==raise to $O(n^2)$==.

	![](fc6.png)
	
</details>

6. <details markdown=1><summary markdown="span">  Prove the previous claim. </summary>
    
    \
    We need to prove 2 claims:
    1. ==C1 deadlock freedom of RR==: if at least one process invokes RR.lock, then at least one process enters the CS  ![](fc7.png)
    2.  ==C2 bounded bypass of RR==: if a process invokes RR.lock, then it enters the CS in at most n(n-1) iterations. To prove this, we use the following 2 lemmas:
	    1. Lemma 1:  ![](fc8.png) ![](fc9.png)
	    2. Lemma 2: ![](fc10.png)
	
</details>