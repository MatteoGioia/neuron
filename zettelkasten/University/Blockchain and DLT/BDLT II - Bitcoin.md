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


5. <details markdown=1><summary markdown="span">  Why hashing matters in the bitcoin blockchain and how is it used? Why is it a "good fit" for our PoW function?</summary>
    
    \
    ![](../../static/BDT/bit4.png)

	This works well as event ==smallest change of input will result in a completely different output digest==. This ensures that not only the PoW function (==SHA3==) cannot be computed backwards but also that ==rewriting history== gets ==increasingly more expensive== (thus limiting malicious attacks).

</details>


6. <details markdown=1><summary markdown="span">  What is the incentive to solve a block? Why?</summary>
    
    \
    Coins! This ensures that ==the work done to solve the PoW function is rewarded adequately.==
    Note that nodes that make transactions will also reward mining nodes with ==transaction fees==, which can be made ==higher in order to give a transaction more precedence over the others==.
    

</details>


7. <details markdown=1><summary markdown="span"> What is block time? What is the effect of a long/short block time?   </summary>
    
    \
    Block time ==refers to how often a block is published==. Having: ==short block time== makes the process faster but more error prone (e.g can get the ==order of transactions wrong==), while a ==longer block time== does the opposite effect.

</details>

7. <details markdown=1><summary markdown="span">  Use the concept of the 51% attack to explain why proof of work effectively avoids malicious transactions (e.g. double spending).</summary>
    
    \
	![](../../static/BDT/bit5.png)
    

</details>

8. <details markdown=1><summary markdown="span"> Why do we say the blockchain grants "pseudonimity"? </summary>
    
    \
    Because ==while account holders are not public, their addresses and their activities are.==
    Privacy is still granted through the use of private and public keys.

</details>