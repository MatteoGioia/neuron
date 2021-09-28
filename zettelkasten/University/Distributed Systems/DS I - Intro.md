# Introduzione a DS

## Recall questions
    - What is a distributed system (in a nutshell)?
    - What type of channel we assume to work with in DS? Why?
    - What is an async system? Why most real life are async?
    - What is the "happened before" binary relation? What properties does it have?
    - What are the local and global history? What is a distributed computation (formally)? 
    - What is a system's run?
    - What is a cut? Why is it important for it to be consistent?
    - Why we can't use another process as a monitor? 
    - What is a logical clock? What property does it guarantee? Why it is not enough to monitor the other processes? What does it lack? (hint: gap)
    - How can we use the notion of stability to create a new delivery rule better than DR1? Why does it work for some gaps but it is still not good enough?
    - What is causal delivery? And causal history? Why is it hard to track in the long run? Which useful property is true when we use causal histories as timestamp? (hint: strong)
    - What is a vector clock? How can it be used to make a DR3 that takes gaps AND causal delivery into account?
    - Why is it important to assume the system is closed (i.e. no hidden communication channels)?

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
- but ==what happens if a message with a small timestamp than the current one gets delivered with a huge delay ?==

### Monitors in DS pt.2

The previous delivery rule lacks what's called a ==gap-detection==:
- given 2 events $e$ and $e'$ along with their values $LC(e)$ and $LC(e')$, where $LC(e) < LC(e')$,  determine whether some other event $e''$ exists such that $LC(e) < LC(e'') < LC(e')$.

A ==message $m$ is stable if no future message with timestamp smaller than $TS(m)$ can be received==.
- if the message arriving has $LC$ smaller than the ones receveid from all other processes, it is stable
- this works since the $LC$ is monotone increasing for each $p_i$ and FIFO preserves the order (for the process) in which messages arrrive

![](./static/DS/dr2.png)

==DR2==: We now put messages in a buffer and deliver all messages that are stable in timestamp order
- we will have a vector that keeps tracks of $LC$ for each process
- a message becomes stable whenever its $LC$ is smaller (or equal) than all the other ones in the vector or in other words all other processes have sent a message with a bigger or equal timestamp
- this works but there is still an issue: ==this DR lacks the causality relation between events happening in different processes==! (i.e. messages)

### Casual Delivery

To fix the previous DR, we need to mantain the causality relation between events happening in different processes.  This property is called
==casual delivery==:
- $send_i(m) \to send_j(m') \implies deliver_k(m) \to deliver_k(m')$, for all messages $m,m'$, sending processes $p_i,p_j$ and destination process $p_k$

In simpler terms, this property ensures that ==the monitor knows about a messsage only when the event corresponding to the delivery of that message happens==
- so other processes that are influenced by that can't be delivered first!

### Causal history

<small> In the following $LC$ will be used interchangeably with $TS$ </small>

To ensure the causal delivery in our next DR, we want to make sure that we can somehow ==infer the order of messages between different processes using their timestamps==. We need a ==strong clock condition==: $TS(e) < TS(e') \iff e \to e'$

One approach would be using the ==causal histories== of the processes: $e_i$: $\Theta(e) = \{e' \in H : e' \to e_i\} \cup \{es\}$
- a causal history can also be seen as ==the smallest consistent cut that includes $e$

Each process mantains its causal history starting from an empty set:
- if an event $e$ from the same process arrives the causal history becomes the union of the previous causal history with $e$ 
- otherwise if $e_i$ is the receiving event in $p_i$ from $e_j$ in $p_j$, the causal history is the union of the causal history of $e_i$ and the causal history of $e_j$

![](./static/DS/causalh.png)

This ==definition satisfies the strong clock conditione because it's always true that $e \to e' \iff \theta(e) \subseteq \theta(e')$==

So this works, but ==casual histories grow in size too rapidly== to be used efficiently
- maybe just the frontier could be used?

### Vector clocks

One way to ==shrink the size of the causal histories is to use a vector of natural numbers== to represent it
- this mechanism is called ==vector clock (VC)==
- for the complete list of properties see pg.17-19 of Babaoglu-Marzullo

The entire causal history of $n$ processes can be represented by a $n$-dimensional vector that starts from all zeroes, in which:
- $VC(e)[i] = k \iff \theta_i(e) = h_{i}^{k}$  

The values in the vector increase following these rules (similar to LC):

![](./static/DS/vectorclock.png)

Working example of vector clocks:

![](./static/DS/vecex.png)

### Monitors in DS pt.3

Vector clock are the perfect fit to implement causal delivery.

==DR3==: Deliver message $m$ from $p_j$ as soon as 
- $D[j] = TS(m)[j]-1$ - ==no previous messages from the same process==
- $D[k] \geq TS(m)[k] \forall k \neq j$ed ==causal delivery and gap detection==

![](./static/DS/vectorp0.png)

One important thing in the following is that ==we'll assume the system is closed==, which means that there are no external channels used to communicate
- otherwise there could be anomalies



