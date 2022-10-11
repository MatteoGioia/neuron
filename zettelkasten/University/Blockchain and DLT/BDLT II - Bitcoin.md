# Bitcoin

Also see :
- [[DS III - Bitcoin]]
- [[DS II - Reaching Consensus]]

### Recall questions

1. <details markdown=1><summary markdown="span"> Why do we say the blockchain is a pr...? </summary>
    
    \
    ![](../../static/BDT/bit1.png)

	The blockchain is ==not a software, neither a computer== and so on.

</details>

2. <details markdown=1><summary markdown="span"> What is the concept of min(t)ing?  </summary>
    
    \
    The idea for a currency based on computing a (really hard)  ==one way function== that must be ==tunable== and thus comes with a ==specific cost==.

</details>


3. <details markdown=1><summary markdown="span"> Explain how transactions are prepared in order to be added to a block. Hint: pool!  </summary>
    
    \
	The overall process goes like this:
	- a node ==makes a transaction== and propagates it to the network;
	- a ==mining node receives the message== and puts the transaction in a ==pool==,  ready to add it to a block;
	- a mining node that solved the PoW function then requests the block to be added to the blockchain.

</details>


4. <details markdown=1><summary markdown="span"> Explain why the CAP theorem    matters for blockchains. What does the blockchain "give up", although not entirely? </summary>
    
    \
	When dealing with distributed systems,  propagation in the network will almost (always) end up in ==conflicts==.

	![](../../static/BDT/bit3.png)

	The ==CAP theorem== is relevant as it applies to ==distributed data storages==:

	[](../../static/BDT/bit2.png)

    The blockchain gives up ==consistency==. in the sense that it ==reaches eventual consistency.==

</details>


5. <details markdown=1><summary markdown="span">  Why hashing matters in the bitcoin blockchain and how is it used? Why is it a ==good fit== for our PoW function?</summary>
    
    \
    ![](../../static/BDT/bit4.png)

	This works well as event ==smallest change of input will result in a completely different output digest==. This ensures that not only the PoW function (==SHA3==) cannot be computed backwards but also that ==rewriting history== gets ==increasingly more expensive== (thus limiting malicious attacks).

</details>


6. <details markdown=1><summary markdown="span">  What is the incentive to solve a block? Why?</summary>
    
    \
    

</details>


7. <details markdown=1><summary markdown="span"> Block time smth smth  </summary>
    
    \
    

</details>

7. <details markdown=1><summary markdown="span">  </summary>
    
    \
    

</details>