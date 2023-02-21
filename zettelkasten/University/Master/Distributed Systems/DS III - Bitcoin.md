# Bitcoin and the blockchain

## Recall questions
    - What is the purpose of bitcoin?
    - How is a btc/transaction structured? 
    - What is a block? What is the blockchain?
    - What is the proof of work? How does it avoid double spending?
    - How is forking addressed?
    - Is bitcoin live/safe? Is it anonymous?

## Bitcoin

Bitcoin was meant as a ==form of electronic cash that is, decentralized, so no central authority, and anonymous, although not completely==. By design, ==there are only 21mln bitcoins==.

In this ecosystem, there are 3 types of users:
- people
- authorities
- miners (mine blocks and approve transaction)

### Handful notions

Hash function $h : A \to B$
- easy to compute
- $A$ is infinite, $B$ is not
- $h^{-1}$ is hard to compute
- given $x$ and $h(x)$, a $y$ such that $h(x) = h(y)$ is hard to find

Hash functions are mainly used for fingerprinting. Famous ones are for example MD5, SHA-1, etc $\ldots$

Private and public key mechanism. Usually utilised in conjuction with hashes to produce signatures for messages.

### Blockchain: distributed consensus with no central authority

==Structure of a transaction: each owner transfers the coin to the next by digitally signing a hash of the previous transaction and the public key of the next owner and adding these to the end of the coin.==

![](../../../DS/btcblock.png)

This type of transaction is subject to ==double spending, i.e. sending the same bitcoin to 2 different new oweners.==

To avoid this, ==there must be a common knowledge of all the transactions and all of the ones that have been approved. To do so, bitcoin makes use of a blockchain.==
- protocols like Paxos or PBTF do not work 

==Every node has a copy of the blockchain, and new blocks containing new transactions can be approved.== To approve a block to add to the blockchain, there must be distributed consesuns on the transactions inside it.

![](../../../DS/bchain.png)

==Only the block with the last $k$ bits set to 0 is approved, so the miners have to try many nonces before the hash results in what they want.==
- the average "work" required is exponential in the number of zero bits required
- this makes it so that ==a block can be replaced only if a new nonce with $k$ bits is found, meaning that an attacker would need a lot of power to change it==

When a block is solved, the miners get bitcoins as a reward. In the past, the reward used to be 50 btc, but it was progressively halved each 4 years. Right now is 6.25 btc.

A new block is usually generated every 10 minutes.

### Forking

What happens if 2 miners solve a block at the same time? This process is called ==forking: now the blockchain is split over 2 branches, with nodes working on either one.==

![](../../../DS/fork.png)

When ==one of successive blocks is solved, the branch left behind gets scrapped==. To avoid transactions being scrapped because they belong in forked blocks, there's a waiting time for approval, namely 6 blocks, before the transaction is actually approved.  

==Miners will prosecute the longer chain, because the short one will probably be scrapped.==

The procotol is also ==safe with high probability, since thanks to randomizing it's highly unlikely, as the chain grows longer, that the forking goes on. This is also true for liveliness, as the risk of forking diminishes with time.==

### Safety and liveness

The blockchain protocol has some issues. A known one is that ==if someone manages to have 50%+ of the computational power, he could control the blockchain.==

Another one is that ==bitcoin is commonly mined in pools==. How then is it possible that each node in the pool does his own amount of work? Since there is ==need to find $k$ zeros, if a node finds a nonce that produces $k-1$ zeros we could say he did 50% of the work and so on..==

### Anonimity of bitcoin

==Anonimity of bitcoin is not absolute. As long as the wallet owner remains anonymous, it is impossible to track him.== If the identity of the owner is linked to the wallet, then it is possible to reveal it.

Using a new key pair for each transaction can improve privacy.


