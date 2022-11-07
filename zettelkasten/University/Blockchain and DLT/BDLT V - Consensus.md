# Consensus

### Recall questions

1. <details markdown=1><summary markdown="span"> Why can't we just "save" hashes that start with a certain number of zeros? What is an actually better strategy? </summary>
    
    \
    No! In fact, either ==the block header== or the ==position of the nonce (hence the name hasharound)== is going to change depending on the block. \
    A much better strategy for achieving faster solving times is to ==split computation among different nodes, having each machine working on different partitions of possible nonces==. Note however that only the winning node is going to get the reward...
    ![](../../static/BDT/cons1.png)

</details>


2. <details markdown=1><summary markdown="span"> What is the "re-target" operation in bitcoin?  </summary>
    
    \
    It's the operation by which ==the bitcoin protocol ensures a constant difficulty, namely 2016 blocks every 2 weeks==. The name comes from the fact in the PoW algorithm, we look for a block digest ==less or equal to a given target==.

</details>


4. <details markdown=1><summary markdown="span"> Who gets the reward if 2 nodes solve the same block in Bitcoin? And in ethereum? What is the reward then? Does everybody get it? </summary>
    
    \
    Sadly for bitcoin miners, only the ==winning node==! In ethereum, however, things work a bit differently:  we have ==ommers (a.k.a uncles)==, which are ==blocks for which the PoW has been solved but not "in time"== (i.e. the chain continued after another block.)
    
    ![](../../static/BDT/cons2.png)

	Interestingly, ==for every uncle U in block B, the miner of B gets an additional 3.125%== of reward.

</details>


5. <details markdown=1><summary markdown="span"> What is ethash and how does it prevent hardware optimization for solving PoW?  </summary>
    
    \
    Ethash is ethereum's way of ==defending against hardware optimised computation==. One common example in the bitcoin blockchain are ASICs. \
    What ethash does is ==relying on a DAG weighing in at 1GB, changing every 125 hours==.  This makes it harder... why?
    
</details>


6. <details markdown=1><summary markdown="span"> What changed in the ethereum blockchain with the London upgrade?  Hint: transaction fees.</summary>
    
    \
   
    
</details>


7. <details markdown=1><summary markdown="span"> Explain how the fees are regulated after the London upgrade.  </summary>
    
    \
   
    
</details>


8. <details markdown=1><summary markdown="span"> What is the proof of stake algorithm proposed for ethereum? What should it enforce in order to work?  Hint: slashing </summary>
    
    \
   
    
</details>


8. <details markdown=1><summary markdown="span"> What is the beacon? What is its main purpose? </summary>
    
    \
	Make things faster: delegate smart contracts executions to shards
    
</details>


9. <details markdown=1><summary markdown="span"> What is Gasper? Explain the joint use of Casper TFFG + LDM GHOST. </summary>
    
    \
   
    
</details>

