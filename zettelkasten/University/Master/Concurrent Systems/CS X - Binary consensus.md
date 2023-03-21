
# Universal objects and consensus pt.2

Bonus ex: implement consensus with compare and swap that returns booleans
### Recall questions 

1. <details markdown=1><summary markdown="span">  What is the consensus number of an object type?  </summary>
    
    \
    The consensus number of an object of type $T$ is the ==greatest number $n$ such that it is possible to wait free implement a consensus object in a system of $n$ processes by only using objects of type $T$ and atomic R/W registers==.
   

</details>

2. <details markdown=1><summary markdown="span">  Prove the theorem on object implementation. </summary>
    
    \
    ![](../../../static/CS/cons1.png)

</details>

3. <details markdown=1><summary markdown="span"> What is a schedule? And a configuration? </summary>
    
    \
    Definitions:
    - ==schedule==: ==sequence of operations== issued by a process
    - ==configuration==: global state of a system at a given time of execution, including ==local states of each $p_i$ and shared memory==

	Given a configuration $C$ and a schedule $S$, ==we denote with $S(C)$ the configuration  obtained starting from $C$ and applying $S$==
   

</details>

4. <details markdown=1><summary markdown="span">  What is a configuration induced by an algorithm? What are possible nomenclatures for it? </summary>
    
    \
    Let us consider binary consensus implemented by an algorithm $A$ by using base objects and atomic R/W registers; we ==call $S_A$ a schedule induced by $A$==.

	A configuration $C$ obtained during the execution of $A$ is called:
	- ==$v$-valent== if $S_A(C)$ decides $v \ \forall \ S_A$
	- ==mono-valent== if $\exists \ v \in \{0,1\} \ | \ C$ is $v$-valent
	- ==bi-valent==, otherwise

</details>

5. <details markdown=1><summary markdown="span">  Prove there exist a bi-valent initial config ... </summary>
    
    \
    ![](../../../static/CS/cons2.jpg)


</details>

6. <details markdown=1><summary markdown="span"> Prove the impossibility of consensus with only read/write atomic registers. </summary>
    
    \
	Proof: ![](../../../static/CS/cons4.jpg) ![](../../../static/CS/cons5.jpg)  

</details>

7. <details markdown=1><summary markdown="span"> Describe and prove the implementation of consensus with test and set. What is the CN? </summary>
    
    \
	The $CN$ is 2: ![](../../../static/CS/cons3.png)

	![](../../../static/CS/cons6.jpg)


</details>

8. <details markdown=1><summary markdown="span"> Describe the implementation of consensus with fetch&add and swap. What is the CN?  </summary>
    
    \
    The $CN$ is 2: ![](../../../static/CS/cons7.png)

</details>

9. <details markdown=1><summary markdown="span"> Describe the implementation of consensus with compare&swap. What is the CN? </summary>
    
    \
    The $CN$ is $\infty$ : ![](../../../static/CS/cons8.png)

</details>