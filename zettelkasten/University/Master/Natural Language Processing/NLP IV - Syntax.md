# Speech tagging 

### Exercises

List of exercises:
- Syntax tree (not in exam)

### Recall questions 

1. <details markdown=1><summary markdown="span"> What is a straightforward way of handling the syntax of a a sentence? Why it might not be ideal when applied to every language?  </summary>
    
    \
    We can try to express every sentence of a language with the help of a ==context free grammar==: ![](../../../static/NLP/syn1.png)

	To make things even easier, we can use a ==CFG in Chomsky Normal Form (CNF)==, as it has the advantage of ==generating a binary tree==: ![](../../../static/NLP/syn2.png)

	Most languages however have ==flexible word ordering==: this makes creating a CFG really hard. 

</details>

2. <details markdown=1><summary markdown="span">  What are dependency grammars? How do they help in addressing the issue mentioned previously? </summary>
    
    \
    Dependency grammars express ==lexical, semantic or syntactic relations between words==.

	These grammars have the advantage of ==being word-order free==, whereas a normal CFG would need specific rules for each position of, say, a certain verb: ![](../../../static/NLP/syn3.png)
   
</details>

3. <details markdown=1><summary markdown="span"> What is a treebank? What it is used for?  </summary>
    
    \
    A treebank is a ==corpus whose CFG parses are annotated with dependencies==. The idea is to ==use it as a black box to annotate new pieces of text==: ![](../../../static/NLP/syn4.png)

</details>

4. <details markdown=1><summary markdown="span"> Describe two common strategies for parsing dependencies. What is the main issue of both approaches? </summary>
    
    \
    Two strategies:
    - ==top down parsing==: ![](../../../static/NLP/syn5.png)
    - ==bottom up parsing==: ![](../../../static/NLP/syn6.png) ![](../../../static/NLP/syn7.png)

	The issues is that ==both strategies potentially require a considerable degree of backtracking==. 
   

</details>

5. <details markdown=1><summary markdown="span"> What is an alternative strategy to perform parsing more efficiently? Describe the CKY algorithm. </summary>
    
    \
	An alternative strategy for parsing is ==dynamic programming==, which saves ==intermediate parsing steps== in a table to avoid computing them again.

	The CKY algorithm uses DP to parse a ==sentence given a CFG in CNF==: ![](../../../static/NLP/syn8.png)

	Starting from a table like the one in the following image, ==the sentence belongs to the grammar if the cell $(0,n$ contains the starting symbol==: ![](../../../static/NLP/syn9.png)

	In the end, the parse tree can be build by ==backtracking through pointers==: ![](../../../static/NLP/syn10.png)

</details>

6. <details markdown=1><summary markdown="span">  What is the main "issue" of parsing a sentence using the CKY algorithm? </summary>
    
    \
    The main issue is that ==parsing is ambiguous==: taking different paths through the back-pointers could lead to multiple legal parses of the same sentence.

</details>