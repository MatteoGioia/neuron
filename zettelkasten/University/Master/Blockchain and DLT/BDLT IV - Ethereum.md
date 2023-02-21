# Ethereum

### Recall questions

1. <details markdown=1><summary markdown="span"> What is the difference between the transaction model in bitcoin and the balance mode in eth? </summary>
    
    \
    In eth, ==a user does not have to have previous transaction in order to create new ones==. What he can do is simply create new ones. This is possible because ==each eth account as its own balance==.

	![](eth0.png)

</details>


2. <details markdown=1><summary markdown="span"> What info is included into each eth account?  </summary>
    
    \
    Each account has ==local state info== (compared to btc in which we only have the list of transactions):
    - ==nonce=== that indicates the ==number of transactions sent, for EOAs==, or the ==number of contract creations made, for a CA (code artefacts)==
    - ==balance== counted in ==Weis==
    - a ==key/value== storage to retain data
    - ==immutable code, in the case of CA==

	![](eth1.png)

</details>


3. <details markdown=1><summary markdown="span"> What are the capabilities of contracts in ethereum (implications of eth contracts being Turing complete)? Where are they run? </summary>
    
    \
    In eth, smart contracts can:
    - ==read and write== to internal storage
    - ==send other messages==
    - ==create/call other contracts==

	Eth smart contracts are run on the ==Ethereum Virtual Machine==.
	
</details>


4. <details markdown=1><summary markdown="span"> What is the EVM, really? </summary>
    
    \
    We can model the EVM as the ==emulation of a single, global computer==. It has ==its own language, the EVM bytecode==.
	
</details> 


5. <details markdown=1><summary markdown="span"> What is gas? Why is it needed? How is the price regulated?  Why gas "it's not eth"? </summary>
    
    \
    Gas ==is the cost of every programmable computation== in Ethereum. It is also paid for ==sending data==. Each transaction ==has a gasLimit==.

	![](eth2.png)

	Note that the cost is withdrawn from the caller's account. ==The price a user pays is decided by the gasPrice== at which such user buys the gas. More importantly, ==gas is not ethereum==, since the ==price of an operation remains constant== regardless of the eth price.

</details>


6. <details markdown=1><summary markdown="span"> Why gas helps against preventing DoS attacks? Make an example. Does it also help against the halting problem?</summary>
    
    \
    Gas makes ==DoS attacks very very expensive==, as the user would have to pay the gas for each (recursive) call of a smart contract.

	![](eth3.png)

	It also ==circumvents the halting problem==: when there is no gas anymore, the code execution stops!
	
</details>

7. <details markdown=1><summary markdown="span"> Compare the contents of transactions and messages in ethereum. </summary>
    
    \
    ![](eth4.png)

	Note that there is no need for storing messages: code is run across the nodes in the eth blockchain!
	
</details>


8. <details markdown=1><summary markdown="span"> Use the following image to describe how transaction change the state of the eth blockchain.</summary>
    
    \
    ![](eth5.png)
	
</details>


9. <details markdown=1><summary markdown="span"> Describe the 5 steps of a transaction in ethereum. </summary>
    
    \
    ![](eth6.png)
	
</details>


10. <details markdown=1><summary markdown="span">  Where is the contract code run? </summary>
    
    \
    Code is run ==first on the mining nodes==, ==then on every node once the mining node publishes the block== including the transaction that invoked the code.
	
</details>


11. <details markdown=1><summary markdown="span"> Describe the process of approving a block in eth. </summary>
    
    \
    ![](eth7.png)
	
</details>


12. <details markdown=1><summary markdown="span"> What type of data is kept in the eth blockchain? </summary>
    
    \
    The ==chain data (blocks forming the chain) are always kept==, while ==state data (result of each transaction's state transition) can be pruned==.
    
	
</details>