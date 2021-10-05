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

### Recovery protocol

The easiest case for recovery is a partecipant $p$ that:
- failed before deciding YES, so can abort freely
- failed after received a COMMIT or ABORT and doing so, or deciding to ABORT 

What happens when there is a fail during the uncertainty period
- recall that we don't have indipendent recovery, so we need external help/info

If you are a partecipant, you send the message and then log
- this way there is no risk of sending a message twice because you crash before logging
- this is a MUST if you are sending yes (because you can't abort after sending yes), if the answer is ABORT it is not necessary 

If you are the coordinator, you log and send the message