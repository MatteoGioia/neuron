# Introduzione a DS

## Useful Info

- 

## Recall questions
    - What is a distributed system (in a nutshell)?
    - What type of channel we assume to work with in DS? Why?
    - What is an async system? Why most real life are async?
    - What is the "happened before" binary relation? What properties does it have?
    - What are the local and global history? What is a distributed computation (formally)? 
    - What is a system's run?
    - What is a cut? Why is it important for it to be consistent?
    - Why we can't use another process as a monitor? 
    - What is a logical clock? Why it is not enough to monitor the other processes?

## Basic notions

### Distributed System

==System with $n$ processes that are distributed on a network and all processes==
cooperate to complete a single task.
- processes are also called nodes

Processes communicate with a communication channel
- channels can also be a process

==We won't make assumptions about each processes' running time==

### Communication channels

Channels:
- reliable, i.e. TCP
- unreliable, i.e. UDP

Reliable:
- can receive messages out of order
- can also be FIFO

==We'll assume channels are reliable==
- doing otherwise would cause problems (i.e. 2 generals infinite loop)

### Types of DS

Async: no bound on messages' travelling time
- most real life systems are async but are modelled as sync
- async systems can be made syncronous (opposite is not true)

Sync: assumption about time elapsed for each message to travel

==We'll assume our systems are asyncronous.==

### DS representation

![](./static/DS/discomp.png)

==Event $(e_{p}^{i})$: the i-th meaningful instruction for the process p==
- i.e. something that changes the state of the process
- i.e. ==sending or receiving a message== 

If two events happen at the same time they are concurrent.

There is also a ==binary relation== to define the concept of =="an event happened before another"==:
1. $e_{i}^{k}, e_{i}^{l} \in h_i$ with $k < l$, then $e_{i}^{k} \to e_{i}^{l}$ (reads)
2. if $e_i$ = send(m) and $e_j$ = receiving(m), $e_i \to e_j$
3. if $e' \to e''$ and $e' \to e'''$ then $e' \to e'''$ 

$\to$ is the smallest relation with properties 1,2,3

Notice that ==only in the case of sent/received messages there is the certainty that 2 events interacted with each other==
- otherwise $\to$ merely implies that one happened before another

### Distributed computation

==Local history of a process $h_{i}^{k}$ = $e_{i}^{1} \ldots e_{i}^{k}$==
- $h_{i}^{0}$ denotes an empty sequence
- ==global history $H = h_1 \cup \ldots h_n$==

Formally, a ==distributed computation is a partially ordered set defined by the pair ($H, \to$)==

## Consistency in DS

### Process' state

We denote the state of the process $p_i$ after executing event $e_{i}^{k}$ as $\sigma_{i}^{k}$.
- $\sigma_0$ is the initial state

The ==globabl state is a tuple of local states $\Sigma = (\sigma_1, \ldots, \sigma_n)$==

### System run

==System's RUN: possible order of events in the system==
- if a run $R$ can't happen is called inconsistent

### Run Cuts

![](./static/DS/dscut.png)

A cut $C$ is a portion of a system run $R$
- formally a cut is specified trough a set of n. number $C = (c_1, \ldots, c_n)$ where each number indicates the last event included for each process
- $C$ is consistent $\iff e \to e' \land e' \in C \implies e \in C$ 

A ==consistent cut is associated with a consistent global state==
- this is important for detecting deadlocks

An easy way to check for consistency is to check for received messages that were not sent
- visually a message outside of the cut "goes" inside 

### Deadlocks

System can be engineered to either be deadlock avoidant or to have a deadlock removal mechanism
- the second is ususally easier

In DS, there is a process monitor that checks for deadlocks 
- but a simple snapshot of the system could lead to ghost deadlocks: the monitor itself is part of the DS and could be examining an inconsistent cut
- there is the need for ad hoc protocols

==Lattice==: set of all global states of a computation with a ==leads to== relation
- a state $\Sigma_{i-1}$ leads to $\Sigma_{i}$ if the latter is obtained by the first when the process executes a certain event $e_i$
- a state $\Sigma^{'}$ is reachable from another state $\Sigma$ in a run $R$ $\iff$ $\Sigma \rightsquigarrow_{R} \Sigma^{'}$ (transitive closure)

![](./static/DS/dsmanystates.png)

### Monitors in DS

Real Global clock: ideal perfect clock used by all processes 
- cannot exists

Network Time Protocol (NTP): protocol to keep clocks aligned in real impl.

DR1: The monitor now is passive and only receives a message by the other processes for each event 
- with each event, the process also sends a timestamp $TS$ used to reconstruct a run (otherwise the event could be arranged in inconsistent runs/cuts)
- each timestamp is a natural number 

![](./static/DS/dslogicalclock.png)

This type of clock is also called Lamport's clock

We want to ensure for a ==clock condition==: $e \to e' \to LC(e) < LC(e')$
- if the property it's true, it means that if $e$ comes before $e'$, there is no way $e'$ timestamp is bigger
- but what happens if a message with a small timestamp than the current one gets delivered with a huge delay?

A message $m$ is stable if no future message with timestamp smaller than $TS(m)$ can be received.
- a vector keeps track of the last event delivered for every process and its lamport clock

(Immagine)

DR2: We now put messages in a buffer and deliver all messages that are stable in timestamp order
- this works but the issue about gaps remains

To solve the issue we need a ==strong clock condition==: $TS(e) < TS(e') \iff e \to e'$
-  but how can we know when 2 events are actually related

We can use the ==causal history== of an event $e_i$: $\Theta(e_i) = \{e : e \to e_i\} \cup \{e_i\}$
- we now know that $e_$...
- we can use the causal history as a timestamp

(Immagine)

DR3: Deliver message $m$ from $p_j$ as soon as $D[j] = TS(m)[j]-1$ and $D[k] \geq TS(m)[k] \forall k \neq j$
- the Lamport clock is now replaced with a causal vector D that is updated in the same way as DR2
- the gap issue is also solved




