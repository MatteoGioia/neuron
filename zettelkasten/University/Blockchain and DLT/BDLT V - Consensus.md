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
    What ethash does is ==relying on a DAG weighing in at 1GB, changing every 125 hours==.  This makes it harder as 1TB of RAM, especially at the time of release, was really expensive.
    
</details>


6. <details markdown=1><summary markdown="span"> What changed in the ethereum blockchain with the London upgrade?  Hint: transaction fees.</summary>
    
    \
   
    
</details>


7. <details markdown=1><summary markdown="span"> Explain how the fees are regulated after the London upgrade.  </summary>
    
    \
   
    
</details>


8. <details markdown=1><summary markdown="span"> What is the proof of stake algorithm proposed for ethereum? What should it enforce in order to work?  Hint: slashing </summary>
    
    \
    The main idea is the following: ==the more is left at stake by users, the less likely they are to subvert the blockchain==. This is effectively ensured by having ==**validators** place a bet on the blockchain they deem true==. If they are "right", they get a reward. \
    However, in order to work, ==this protocol must ensure  that one cannot simply bet on all chains in order to win==. Because of this, ==slashing is introduced==: some of the ==validator's deposit is going to be burnt with immediate logout if the slashing conditions are violated!==. 

	![](../../static/BDT/cons3.png)

	This overlay (consisting of more things than just slashing!) for the existing PoW chain is known as ==Casper, the friendly finality gadget==.
   
    
</details>

### Towards eth 2.0


9. <details markdown=1><summary markdown="span"> What is the beacon? What is its main purpose? Does it work already? </summary>
    
    \
    The beacon is ==a proof of stake chain, which will be the "next" evolution of the existing eth blockchain==. The main idea is to ==make things faster: delegate smart contracts executions to shards, while the backbone executes transactions.==
    After a while, the shards ==roll up to synch with the beacon==. \
    The beacon mechanism effectively started working on ==September 2022, with the Paris upgrade, a.k.a. the Merge==.

	![](../../static/BDT/cons4.png)
    
</details>


10. <details markdown=1><summary markdown="span"> What is the role of a validator? How does a node express his agreement? How expensive is to be one (i.e. how much is "at stake")?. </summary>
    
    \
    At the moment, being a validator is expensive!
    ![](../../static/BDT/cons5.png)

	A validator is responsible for:
	- ==checking the validity of propagated blocks==
	- ==create and propagate new blocks, if they are the proposer==

	==Agreement is expressed with attestations== for block deemed valid.

</details>


11. <details markdown=1><summary markdown="span"> What is Gasper? Explain the use of LDM GHOST to solve conflicts. Explain then how casper is used to finalize blocks (hint: checkpoints.) </summary>
    
    \
	LDM GHOST is used to ==decide agreement on the next block in a chain==. It basically ==favours the block with the most attestations, only considering the most recent messages from each validator== (hence the greediness). 

	![](../../static/BDT/cons6.png)
    
</details>


12. <details markdown=1><summary markdown="span"> What is the sync committee and its purpose? </summary>
    
    \
	Every 256 epochs (~27 hours), a sync committee is randomly assigned. It is a ==group of 512 validators that signs block headers for each new slot. A light client can take these headers to represent accurate and validated blocks==. 
    
</details>


13. <details markdown=1><summary markdown="span"> How does whistleblowing help against malicious nodes? What are possible cases of misbehaviour?  What is a particular case of misbehaviour that is not necessarily voluntary? </summary>
    
    \
	A ==whistleblowing validator sends a message to be included in the next block, in order to signal a node that is caught doing one of the following==:

	![](../../static/BDT/cons7.png)

	The offending node is going to be ==slashed and eventually removed==. Note that ==inactivity is also considered as sabotage==: after 4 failed epochs, nodes that vote against the majority are penalised.
    
</details>