Also see [[DS I - Intro]]

# More on atomicity

### Recall questions on atomicity

1. <details markdown=1><summary markdown="span">  What is a history/trace? </summary>
    
    \
    A history or trace is a ==pair $\hat{H} = (H, <_H)$ where $H$ is a set of events and $<_H$ is a total order on them==.
    

</details>

2. <details markdown=1><summary markdown="span"> What is a sequential history? And a complete one? </summary>
    
    \
    A history is:
    - sequential, it is of the ==form of $inv$, $res$, where every $res$ is the return operation of the immediately preceding $inv$==
    - complete, if ==every $inv$ is eventually followed by a corresponding $res$, partial otherwise.==
    

</details>

3. <details markdown=1><summary markdown="span">  What is a linearisable history? </summary>
    
    \
    A ==complete history $\hat{H}$ is== linearisable if $\exists \hat{S}$  s.t.:
    - $\forall X \ \hat{S}|_X \in$ the semantics of $X$ (==it respects the semantics==)
    - $\forall p \ \hat{H}|_p = \hat{S}|_p$ (==same operations in the 2 "versions"==)
    - if $res[op] <_H inv[op'] \to res[op] <_S inv[op']$ - this can be rewritten as ![](../../../static/CS/ato1.png)

	An example:
	![](../../../static/CS/ato2.png)


</details>

4. <details markdown=1><summary markdown="span">  Explain whether the following examples are linearisable or not. </summary>
    
    \
    ![](../../../static/CS/ato3.png)

</details>

5. <details markdown=1><summary markdown="span">  Prove the compositionality of linearisability.  Why does it matter? </summary>
    
    \
    Makes ==linearising much easier, as we can now compose multiple smaller object that we know are linearisable.==

	--aggiungere immagine--

</details>

6. <details markdown=1><summary markdown="span">  What is sequential consistency? </summary>
    
    \
	Define  ==$op \to_{proc} op’$ to hold whenever there exists a process $p$ that issues both invocations  with $res[op]$ happening before $inv[op’]$==.

    A complete history $\hat{H}$ is sequentially consistent if $\exists \hat{S}$ :
    - same ==1 and 2 of linearisability==
    - ==$\to_{proc} \subseteq \to_S$==

	It is laxer notion compared to linearisability. Example: ![](../../../static/CS/ato4.png)

</details>

7. <details markdown=1><summary markdown="span">  What do we lose requiring "only" sequential consistency? </summary>
    
    \
    ![](../../../static/CS/ato5.png)

</details>

8. <details markdown=1><summary markdown="span"> What is a serialisable history? Does this one have compositionality? </summary>
    
    \

	![](../../../static/CS/ato6.png)

    A complete history $\hat{H}$ is sequentially serialisable if $\exists \hat{S}$ :
    - same ==1 of linearisability==
    - ==$S = \{e \in H | e \in t \in CT(\hat{H})\}$== where $CT$ means ==committed transactions==
    - ==$\to_{trans} \subseteq \to_S$== where $\to_{trans}$ is defined like $\to_{proc}$ in sequential consistency

    This is also ==not compositional.==

</details>