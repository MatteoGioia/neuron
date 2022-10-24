# Bitcoin in depth

Also see :
- [[DS III - Bitcoin]]
- [[DS II - Reaching Consensus]]
- [[BDLT II - Bitcoin]]

### Recall questions pt.1

1. <details markdown=1><summary markdown="span"> Describe the detailed behavior of each full node receiving a transaction. </summary>
    
    \
    ![](../../static/BDT/bitd1.png)

</details>

2. <details markdown=1><summary markdown="span"> Describe bitcoin as a chain of signatures.  Explain then how a the hash inside a transaction is generated.</summary>
    
    \
    ![](../../static/BDT/bitd2.png)

	As it can be seen, a ==transaction can have multiple inputs and outputs.== This inputs are ==references to an output from previous transactions==, while the outputs are usually the ==sender and the redeemer==.

	We say it's a chain of signatures as ==each sender it's going to sign the transaction with the hash of a previous transaction and his private key== and this process is going to be repeated for each successive transaction.
    

</details>

3. <details markdown=1><summary markdown="span"> Describe bitcoin as a state transition system. How do we express transaction fees? </summary>
    
    \
	We can see the state of each node as follows:

	![](../../static/BDT/bitd3.png)

	Each node has a ==state defined by unspent transaction units. Every time a transaction is actually taking place, it replaces the existing transaction units with the new ones that were created==.

	Transaction ==fees== are expressed ==implicitly,== in the sense that they are computed as the ==difference between the value sent to the redeemer and the change sent back to the user who created the transaction==.
    

</details>


4. <details markdown=1><summary markdown="span"> Explain how the validity of a transaction is verified.  What is the next state of the state machine?</summary>
    
    \
	The transition applies if and only if all of the following apply:
	- for each input in the current state the UTXO is in the current state
	- the signature matches the owner of the UTXO
	- the sum of denominations of all input UTXOs is higher than or equal to the sum of denominations in the output

	![](../../static/BDT/bitd4.png)

</details>

5. <details markdown=1><summary markdown="span"> What about the validity of a transaction in a block?</summary>
    
    \
	We also check that ==the block timestamp is greater than the median timestamp of previous 11 blocks, and less than the network-adjusted time + 2 hours.==

</details>

6. <details markdown=1><summary markdown="span"> Explain how the PoW algorithm works. </summary>
    
    \
    The goal of the PoW of bitcoin ==is finding a hash for the current block s.t. it has a certain numbers of 0 in the prefix==. Once such hash is found, a node can the submit the block to the others (see question 1).

</details>


7. <details markdown=1><summary markdown="span"> What is the difference between a full and a light node? </summary>
    
    \
    A ==light node== only has to 
    - ==download block headers==
    - ==verify the PoW on such headers==
    - download only the ==branches with transactions relevant for them==
    
</details>

8. <details markdown=1><summary markdown="span"> What is a coinbase transaction? </summary>
    
    \
    A coinbase transaction is ==the first transaction of block, from the miner to itself==. it is a special transaction as it's signed by the miner for the miner!
    
</details>
