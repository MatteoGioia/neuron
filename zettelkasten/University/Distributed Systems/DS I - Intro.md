# Introduzione a DS

## Useful Info

- 

## Recall questions
    - WIP

## Basic notions

### Distributed System

System with $n$ processes that are distributed on a network and all processes
cooperate to complete a single task.
- processes are also called nodes

Processes communicate with a communication channel
- channels can also be a process

We won't make assumptions about each processes' running time

### Communication channels

Channels:
- reliable, i.e. TCP
- unreliable, i.e. UDP

Reliable:
- can receive messages out of order
- can also be FIFO

We'll assume channels are reliable
- doing otherwise would cause problems (i.e. 2 generals infinite loop)

### Types of DS

Async: no bound on messages' travelling time
- most real life systems are async but are modelled as sync
- async systems can be made syncronous (opposite is not true)

Sync: assumption about time elapsed for each message to travel

We'll assume our systems are asyncronous.

### DS representation

(Image here)

System's RUN: possible order of events in the system
- if a run $R$ can't happen is called inconsistent

Event: any meaningful instruction for the process
- i.e. something that changes the state of the process
- i.e. sending or receiving a message (arrows)

If two events happen at the same time they are concurrent.

There is an "happen before" relation $\to$ if:
1. $e_{i}^{k}, e_{i}^{l} \in h_i$ with $k < l$, then $e_{i}^{k} \to e_{i}^{l}$ (reads)
2. if $e_i$ = send(m) and $e_j$ = receiving(m), $e_i \to e_j$
3. if $e' \to e''$ and $e' \to e'''$ then $e' \to e'''$
$\to$ is the smallest relation with properties 1,2,3

## Consistency in DS

### Run Cuts

A cut $C$ is a portion of a system run $R$
- $C$ is consistent $iff e \to e' \land e' \in C \to e \in C$ 

An easy way to check for consistency is to check for received messages that were not sent
- visually a message outside of the cut "goes" inside 

### Deadlocks

(Image with queries and answers)

System can be engineered to either be deadlock avoidant or to have a deadlock removal mechanism
- the second is ususally easier

In DS, there is a process monitor that checks for deadlocks by using a snapshot of a message graph
- each time the monitor asks a process if it is waiting for some other process to answer
- but the monitor itself has to avoid looking at inconsistent cuts that give false positives
- we need ad hoc snapshot protocols, this one does not work

### Clocks in DS

(Image)

Real Global clock: ideal perfect clock used by all processes 
- cannot exists

Network Time Protocol (NTP): protocol to keep clocks aligned in real impl.

The new monitor now receives a message for each event
- with each event, the process also sends a timestamp used to reconstruct a run 
- each timestamp is a natural number 
- the timestamp increases if the message is sending, otherwise it is the maximum + 1 between the process before and the sender process 

This type of clock is called Lamport's clock (LC)
- we want to check for clock conditions: $e \to e' \to LC(e) < LC(e')$
- this system works because our DS must work for each possible run (even if it doesn't actually happen!)

But what if there are any gaps?