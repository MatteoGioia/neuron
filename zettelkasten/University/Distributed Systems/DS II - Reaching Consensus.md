# Consensus in DS 

## Recall questions
    - What are the characteristics of transactions in a DS? What type of fault exist in a DS? 
    - What is the FLP theorem and what does it state? What are the 2 desirable characteristics of a DS that FLP says we have to compromise on?
    - What are the properties of the Atomic Commit Protocol?
    - What is an uncertainty period? Why is it dangerous?
    - Describe the 2PC protocol. What are the voting and decision phase? Does it respect the properties of ACP?
    - What is the Cooperative Termination Protocol? Explain how an uncertain process p can decide if the transaction has concluded. Why this protocol can "always" work?
    - How does the recovery protocol work? Describe how the DTlog is used to safely recover from a node failing and restarting.
    - What's Paxos? What does it guarantee? Describe the protocol and prove its safety. Why can't we make Paxos live, but we can still guarantee progress?
    - How can we "optimise Paxos"? How can we make it faster?
    - What's the idea behind fast Paxos? Why do we need a bigger quorum? Describe the protocol and show its safety. What is the new rule for acceptance?

## Consensus on transaction

<small> process = partecipant </small>

### Why reaching consensus is important

Reaching consensus is an important topic in DS.
- i.e. modern blockchains
- i.e. distributed databases

### The issue with DS

In a DS, ==transaction must:==
- ==be committed by every node==
- ==be committed only when every node reaches an agreement (or be aborted instead)==

But in real DS system, we have faults:
- ==site failures==: a node fails and has to restart
- ==crash failures==: a node fails and **can't restart**
- ==bizantine failures==: a node operates with malicious intent to sabotage the DS
- ==communication failures==: since we assume our channels are reliable, the communication failures are only due to a node failing (previous cases)

We'll also assume ==all sites are fail-stop: they either work correctly or they stop to prevent incorrect behaviour.==

### FLP theorem

The issue is that in DS, ==even 1 failure (site or crash) makes reaching consensus impossible==.
- this was proved in the ==FLP theorem== (Fischer, Lynch, Paterson), where the idea is ==that it is impossible to distinguish a crash from a process just being slow==

>In an asynchronous network where messages may be delayed but not lost, there is no consensus algorithm that is guaranteed to terminate in every execution for all starting conditions, if at least one node may fail-stop.

Another desirable characteristic of DS is that they ensure:
- ==safety==: the DS always does correct operation
- ==liveness==

But in such a system, FLP also states that we can't reach consensus if we have both safety and liveness 

## The ACP

### Atomic commits

An ==ACP is a protocol to reach a decision such that==:
- AC1: all processes that reach a decision ==reach the same one==
- AC2: processes ==cannot reverse== their decision
- AC3: the ==commit== decision can ==only== be reached ==if all processes voted yes==
- AC4: if there are ==no failures==, and ==all processes voted yes==, decision must be ==commit== 

There is also an extra condition for termination, ==AC5==: consider any execution containing only failures that the algorithm is designed to tolerate. At any point
in this execution, ==if all existing failures are repaired and no new failures occur for sufficently long, then all processes will eventually reach a decision.==

AC4 is also useful to avoid trivial protocols like "always abort". AC4 is in fact a weak converse of AC3, while the converse of AC3 is not generally required:
- i.e failures could cause an all Yes decision to be aborted 

### Uncertainty and blocking

The ==period where a process has not taken any decision yet is called uncertain==. The issue with ==uncertain processes== is that they ==can block the entire computation==. They also affects all ACP protocols, as the only way of avoding this would be having instantaneous communication between all processes. 
- see also Prop. 7.1 and Prop. 7.2 

### 2-Phase commit

Components (simplification for pedagogical convenience):
- ==coordinator==: overview the partecipants and decides if transaction must be commmited or aborted
- ==partecipants==: decide to agree/abort a transaction and wait for coordinator's instructions

There is also a DS transaction log where coordinators and partecipants can keep track of the distributed transactions.

2PC phases (C coordinator, Ps partecipants):
1. C sends VOTE-REQ to all Ps
2. P sends answer to coordinator, if answer is NO it aborts and stops, otherwise it waits
3. C collects all messages, if they are all YES it sends a COMMIT message to Ps, otherwise, even if there is only one NO, it sends an ABORT message to all the Ps. C then stops.
4 Ps that voted YES wait for the answer from C and act accordingly.

1 and 2 are called ==voting phase==, while 3 and 4 ==decision phase==.

This procotol works but ==it does not comply (yet) with AC5 because of the uncertainty of processes that failed after voting==. We must adddress:
- termination
- recovery through the DS transaction log

### Timeouts handling

2CP uses a ==cooperative termination protocol==: the coordinator attaches a list of all partecipants to the messages so they know each other and can communicate. When a partecipant $p$ times out while in his uncertainty period, it can send a ==DECISION-REQ== to another partecipant $q$.
- $p$ is called ==initiator==, $q$ the ==responder==

Before continuing, we must also state that the ==coordinator is never uncertain==, as it is design to always know all decisions. This will be important later.

3 cases:
- ==$q$ already decided==, so it ==forwards its decision to $p$ that commits or aborts depending on that==
- ==$q$ has not voted yet, and can decide to abort==; it also ==sends abort to $p$==, that follows its decision
- ==$q$ voted yes but has not reached a decision, so it can't help $p$==

So ==this protocol works if just one process can communicate with $p$ and is in either the first or second case==
- ==since the coordinator can also act as a responder this protocol works==
- otherwise if all processes (including the coordinator) where uncertain this could never work

### Recovery protocol 

The easiest case for recovery is a partecipant $p$ that:
- failed before deciding YES, so can abort freely
- failed after received a COMMIT or ABORT and doing so, or deciding to ABORT 

What happens ==when there is a fail during the uncertainty period==
- recall that we don't have indipendent recovery, so we need external help/info

==Logging on DT (unless specified, the log can be written either after or before the action):==
1. When ==C sends VOTE-REQ write Start2PC in the DTlog (this log contains the identities of the partecipants)==
2. If a ==P votes YES, write YES in the DTlog **before** sending YES to the coordinator; if P votes NO, write NO in the log (before or after)==
3. If ==C decides commit, write Commit in the DTlog before sending the decision to the partecipants; if C decides abort, write ABORT in the DTlog (before or after)==
4. ==After receving the decision, the partecipants write it in the DTlog==, so if they crash they can always use the cooperative termination protocol.

## Paxos protocol

### History of the protocol

Paxos is a protocol ==created by Lamport for distributed consensus== in a DS that is:
- ==asyncrhonous==
- ==allows crash failure==

Since it allows for crash failures, we make a ==compromise on liveness but not on safety.==

The paper describes the ==part time parliament==, a metaphor for the tecnique adopted to achieve distributed consensus.
There is also another version called "Paxos made easy" and notes on the algorithm called "A simpler proof for Paxos and Fast Paxos" by Marzullo.

### The protocol

<small><b>Given the high difficulty of this protocol, it's highly suggested to read the following papers (in the order shown) below instead of referring to these notes. They literally had to dumb it down TWICE because of how hard it is, so I would not trust a random internet stranger (me) to explain it correctly:
<ol><li> The part time parliament</li><li> Paxos made simple</li><li> A simpler proof for paxos and fast paxos</li></ol>
I also probably butchered the proofs so..
</b></small>

We have $n$ processes and we can tolerate $f$ failures, where $f = \lfloor \frac{n-1}{2} \rfloor$.

==Nodes have 3 roles==, although in real system each node actually has all 3 roles:
- ==proposers $\geq 1$: can propose a value for consensus==
- ==acceptors $n$: can accept a value among the proposed ones==
- ==learners $\geq 1$: learn the chosen value==

In the following, the failures will be intended as failures in between the acceptors.

The ==protocol works in round==; ==each round is associated to a single proposer statically==.
- i.e. ==the rounds are assigned before the decision==
- also ==the rounds must be assigned so that each proposer has infinite rounds==

The protocol goes as follows:
1. A ==proposer can send a $PREPARE(i)$ message to all the acceptors, where $i$ is a round.==
2. The ==acceptors see the message, and they prepare to reply to the proposer with a $PROMISE(i, lastround, lastvoted)$, where they promise to be part of the $i$-th round==. The PROMISE also specifies that the acceptors wont partecipate in rounds smaller than $i$. The values of lastround and lastvoted are respectively the last round in which the acceptor has voted and the value that has been voted
3. If ==enough PROMISES has been received (quorum), the proposer sends an $ACCEPT(i, v)$, where $i$ is the round and $v$ is the value proposed by the proposer itself, if no acceptor **in the quorum** has ever voted, otherwise it's the value in the promise associated with the highest round==
4. ==If the acceptors receive the ACCEPT message and they have not promised otherwise, the send vote for the value and then send a message $LEARN(i,v)$ to the learners==. Acceptors vote once for each round.
5. If ==learners receive the quorum of votes for the **same round and same value** they learn (choose) the value.==

![](./static/DS/paxos1.png)

![](./static/DS/paxos2.png)

### Paxos Safety

To prove ==Paxos is safe, we are going to prove that==:
- ==CS1: Only a proposed value may be chosen==
- ==CS2: Only a single value is chosen==
- ==CS3: Only a chosen value may be learned by the correct learner==

CS1 and CS3 are trivially true: only proposers can propose values, and only the quorum that voted for a value can also accept that value.
So ==we only need to prove CS2==, but we'll prove this stronger property that also holds:

>If acceptor $\alpha$ voted value $v$ in round $i$, then no value $v \neq v'$ could get the majority in any of the previous rounds

[$i$ = round 1] : This is trivially true, as no previous round exists

[round $i$]: Since $\alpha$ received enough promises from the quorum, this quorum $Q$ promised not to partake in any previous round. 
This means no acceptor in $Q$ voted before the max last round indicated in the promise:

![](./static/DS/safetyproof1.png)

It is also possible that there would have been a majority in round $lastround$, but the value would have had to be $v$.
Using again the hypotesis, no acceptor could have voted in rounds before, up till round 1.

![](./static/DS/safetyproof2.png)

Note that this safety is not dependent on the number of failures. If there are more failures that the expected number, Paxos simply won't decide.

<small> Please refer to Paxos for Dummies for the formal proof </small>

### Making Paxos (as) Live (as we can)

As stated before, we make a compromise on safety in Paxos. This happens because ==even though safety is guaranteed, progress is not==. Take for instance the following sequence of events: PROPOSE, PROMISE, ACCEPT, PROPOSE. If the round of the second propose is bigger than the round in the first one, the loop could potentially go on forever. There is no fix to liveness: otherwise we would prove FLP theorem to be wrong!

==What we can do, is to make Paxos progress, relying on a ==coordinator== that must be only one at each time and can be the only one that starts the rounds==. But choosing a coordinator (leader election) is also a consensus problem!

Still, ==we don't need to safely choose a coordinator.==
- ==even if there are 2 coordinators, the protocol is still safe although it does not progress==

An unsafe leader election protocol is the following: each node sends a heartbeat signal during each time interval, then a node that is alive
is picked to be the coordinator.

### Making Paxos faster

==In real DS the number of Paxos instances that are being run are many more than just 1==, and they all happen concurrently.

We can make some efficiency tweaks then:
1. ==one $PREPARE$ message can start multiple instances, like $PREPARE(1-1000,v)$==
2. ==one message can also be used for the PROMISE, like $PROMISE(1-1000,v,-1,-1)$==

==To complete each of these instances (that we can number so they don't get shuffled), a proposer $p$ sends the value he wants to propose to the coordinator $c$. The coordinator then completes the instance by sending the proper $ACCEPT$ message to the learners. ==

![](./static/DS/fastpaxos1.png)

==The idea behind fast paxos is that we can reduce the delay by 1 message by allowing the proposer to send its value directly to the acceptors.==
To do so, the ==coordinator starts a fast round where any value can be accepted==, so he does not have to approve each of them manually. The result is that ==all proposers send the proposed value to the acceptors that send the learn message to the learners.==

![](./static/DS/fastpaxos2.png)

### Fast Paxos protocol

Before explaining how fast paxos works, ==we show that at least $\frac{2}{3}$ of the acceptors must be the quorum==
- ==this means we can tolerate $\lfloor \frac{n-1}{3} \rfloor$ failures==

An easy example, if $n=7$ and $f=3$ (if $f = \lfloor \frac{n-1}{2} \rfloor$):
- in round $i$, a proposer is able to form a quorum of 4
- in this quorum, there are 2 different types of promises: $PROMISE(i,j,1)$, PROMISE(i,j,2), both for $j-th$ round (possible in fast paxos since there are fast-rounds)
- the coordinator does not yet know the value voted by the last 3 acceptors: depending on what they do, the quorum could either be for 1 or 2
- the proposer $i$ can't do anything as he can't make any safe choice!

Now that this requirement was explained, let's explain how fast paxos works. We need to change the rule for acceptance as we have shown that it is not true that all the acceptors in the round have "last voted" for the same value.

==New Rule==:
1. if $j = -1$ start a fast round;
2. if $j \geq 0$ and there exists $v$ such that $|Q_j [v'] \geq n - 2f'$ then select $v$, since there can only be such a value;
3. if $j \geq 0$ and for all $v$ the condition in 2 is not true, then select any value that has been last voted in round $j$.

### Fast Paxos safety

The proof is similar to the one for Paxos. We need to prove that:

>If acceptor $\alpha$ voted value $v$ in round $i$, then no value $v \neq v'$ could get the majority in any of the previous rounds

<small> Refer to paper for the full proof </small>

---

<small> Virgin apple ceo: my outfit must be minimal / the CHAD lamport: literally discusses his paper in an indiana jones <a href="https://lamport.azurewebsites.net/pubs/pubs.html"> costume <a> </small>

