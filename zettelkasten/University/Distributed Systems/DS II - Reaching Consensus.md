# Consensus in DS 

## Recall questions
    - WIP

## Consensus on transaction

<small> process = partecipant </small>

### Why reaching consensus is important

Reaching consensus is an important topic in DS.
- i.e. modern blockchains
- i.e. distributed databases

### The issue with DS

In a DS, transaction must:
- be committed by every node
- be committed only when every node reaches an agreement (or be aborted instead)

But in real DS system, we have faults:
- site failures: a node fails and has to restart
- crash failures: a node fails and **can't restart**
- bizantine failures: a node operates with malicious intent to sabotage the DS
- communication failures: since we assume our channels are reliable, the communication failures are only due to a node failing (previous cases)

We'll also assume all sites are ==fail-stop==: they either work correctly or they stop to prevent incorrect behaviour.

### FLP theorem

The issue is that in DS, even 1 failure (site or crash) makes reaching consensus impossible.
- this was proved in the FLP theorem (Fischer, Lynch, Paterson), where the idea is that it is impossible to distinguish a crash from a process just being slow

>In an asynchronous network where messages may be delayed but not lost, there is no consensus algorithm that is guaranteed to terminate in every execution for all starting conditions, if at least one node may fail-stop.

Another desirable characteristic of DS is that they ensure:
- safety: the DS always does correct operation
- liveness

But in such a system, FLP also states that we can't reach consensus if we have both safety and liveness 

## The ACP

### Atomic commits

An ACP is a protocol to reach a decision such that:
- AC1: all processes that reach a decision ==reach the same one==
- AC2: processes ==cannot reverse== their decision
- AC3: the ==commit== decision can ==only== be reached ==if all processes voted yes==
- AC4: if there are ==no failures==, and ==all processes voted yes==, decision must be ==commit== 

There is also an extra condition for termination, ==AC5==: consider any execution containing only failures that the algorithm is designed to tolerate. At any point
in this execution, if all existing failures are repaired and no new failures occur for sufficently long, then all processes will eventually reach a decision.

AC4 is also useful to avoid trivial protocols like "always abort". AC4 is in fact a weak converse of AC3, while the converse of AC3 is not generally required:
- i.e failures could cause an all Yes decision to be aborted 

### Uncertainty and blocking

The period where a process has not taken any decision yet is called uncertain. The issue with uncertain processes is that they can block the entire computation. Thi also affects all ACP protocols, as the only way of avoding this would be having instantaneous communication between all processes. 
- see also Prop. 7.1 and Prop. 7.2 

### 2-Phase commit

Components (simplification for pedagogical convenience):
- coordinator: overview the partecipants and decides if transaction must be commmited or aborted
- partecipants: decide to agree/abort a transaction and wait for coordinator's instructions

There is also a DS transaction log where coordinators and partecipants can keep track of the distributed transactions.

2PC phases (C coordinator, Ps partecipants):
1. C sends VOTE-REQ to all Ps
2. P sends answer to coordinator, if answer is NO it aborts and stops, otherwise it waits
3. C collects all messages, if they are all YES it sends a COMMIT message to Ps, otherwise, even if there is only one NO, it sends an ABORT message to all the Ps. C then stops.
4 Ps that voted YES wait for the answer from C and act accordingly.

1 and 2 are called voting phase, while 3 and 4 decision phase.

(Immagine)

This procotol works but ==it does not comply (yet) with AC5 because of the uncertainty of processes that failed after voting==. We must adddress:
- termination
- recovery through the DS transaction log

### Timeouts handling

2CP uses a ==cooperative termination protocol==: the coordinator attaches a list of all partecipants to the messages so they know each other and can communicate. When a partecipant $p$ times out while in his uncertainty period, it can send a ==DECISION-REQ== to another partecipant $q$.
- $p$ is called ==initiator==, $q$ the ==responder==

Before continuing, we must also state that the coordinator is never uncertain, as it is design to always know all decisions. This will be important later.

3 cases:
- $q$ already decided, so it forwards its decision to $p$ that commits or aborts depending on that
- $q$ has not voted yet, and can decide to abort; it also sends abort to $p$, that follows its decision
- $q$ voted yes but has not reached a decision, so it can't help $p$

So this protocol works if just one process can communicate with $p$ and is in either the first or second case
- since the coordinator can also act as a responder this protocol works
- otherwise if all processes (including the coordinator) where uncertain this could never work

### Recovery protocol (To correct)

The easiest case for recovery is a partecipant $p$ that:
- failed before deciding YES, so can abort freely
- failed after received a COMMIT or ABORT and doing so, or deciding to ABORT 

What happens when there is a fail during the uncertainty period
- recall that we don't have indipendent recovery, so we need external help/info

Logging on DT (unless specified, the log can be written either after or before the action):
1. When C sends VOTE-REQ write Start2PC in the DTlog (this log contains the identities of the partecipants)
2. If a P votes YES, write YES in the DTlog **before** sending YES to the coordinator; if P votes NO, write NO in the log (before or after)
3. If C decides commit, write Commit in the DTlog before sending the decision to the partecipants; if C decides abort, write ABORT in the DTlog (before or after)
4. After receving the decision, the partecipants write it in the DTlog

## Paxos protocol

### History of the protocol

Paxos is a protocol created by Lamport for distributed consensus in a DS that is:
- asyncrhonous
- allows crash failure

Since it allows for crash failures, we make a compromise on liveliness but not on safety.

The paper describes the ==part time parliament==, a metaphor for the tecnique adopted to achieve distributed consensus.
There is also another version called "Paxos made easy" and notes on the algorithm called "A simpler proof for Paxos and Fast Paxos" by Marzullo.

### The protocol

We have $n$ processes and we can tolerate $f$ failures, where $f = \lfloor \frac{n-1}{2} \rfloor$.

Nodes have 3 roles, although in real system each node actually has all 3 roles:
- proposers $\geq 1$
- acceptors $n$ 
- learners $\geq 1$

In the following, the failures will be intended as failures in between the acceptors.

The protocol works in round; each round is associated to a single proposer statically.
- i.e. the rounds are assigned before the decision
- also the rounds must be assigned so that each proposer has infinite rounds

A proposer can send a $PREPARE(i)$ message to all the acceptors, where $i$ is a round.

The acceptors see the message, and they prepare to reply to the proposer with a $PROMISE(i, lastround, lastvote)$, where they
promise to be part of the $i$-th round. The PROMISE also specifies that the acceptors wont partecipate in rounds smaller than $i$.

The proposer sends an $ACCEPT(i, v)$, where $i$ is the round and $v$ is the value associated with the largest round in the promises.
$v$ is calculated as the value **associated** with the maximum of the $lastround$.

A message $LEARN(i,v)$ is sent by the acceptors to the learners. When the learners get the majority of the votes in the same round they can decide.


### I forgor to commit

### Paxos Safety

### Making Paxos Live

To make Paxos live, we rely on a ==coordinator== that must be only one at each time
- but choosing a coordinator (leader election) is also a consensus problem!

Still, we don't need to safely choose a coordinator
- even if there are 2 coordinators, the protocol is still safe

An unsafe leader election protocol is the following: each node sends a heartbeat signal during each time interval, then a node that is alive
is picked to be the coordinator.

After choosing a coordinator, a node chooses a value, sends it to the coordinator that starts Paxos with that value.
Even if the coordinator fails, another one can be selected again.

### Fast Paxos

In real DS the number of Paxos instances that are being run are many more than just 1.
- and they all happen concurrently

For example, we have a tree of paxos instances $Pax_1, \ldots, Pax_n$
- each promise now also holds the paxos instance number since the instances could be completed in a different order than $1, \ldots, n$
- since instances are numbered, there is no risk of shuffling them

We can make some efficiency tweaks:
1. Multiple promises for the same value can be started by the coordinator with only one message, i.e. $PREPARE(1-1000,v)$
2. Acceptors can also make promises for $PROMISE(1-1000,v,-1,-1)$ for the same value $v$

Now let's assume the coordinator is able to send $ACCEPT-ANY(1-1000, v)$. During this type of round, any value can be learned.
- this speeds thing up because any proposer can send a $ACCEPT$ to quickly get his value accepted
- but now we have to deal with possible conflicts.

(immagine)


<small> Virgin apple ceo: my outfit must be minimal / the CHAD lamport: literally discusses his paper in an indiana jones costume </small>

