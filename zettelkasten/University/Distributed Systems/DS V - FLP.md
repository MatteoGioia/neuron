# Practical Bizantine Fault Tolerance

## Recall questions
        - WIP

## FLP 

<small> This lecture was held (?) by Professor Lorenzo Alvisi of Cornell University. </small>

The key behind the proof is that there is an incompatibility between the definition of consensus and the possibility of consensus in a distributed system like the one we define.

>Consensus definition:
>- validity 
>- agreement
>- integrity
>- termination

### A model for proving FLP

(Immagine modello)

The buffer has infinite space and each process $p$ can find:
- messages destined to him
- null messages, called $\lambda$, that contain nothing

The $\lambda$ are a way to model asynchronous systems, where processes could take a long time before receiving a message.

Assumptions to costraint the model:
- liveness 
- one time assumption
- binary consensus: the problem of binary consensus where ... is equivalent to the one of consensus


### Notation

(Notation)

Configuration

Step and applicable step

A step involves fishing, computing some value and eventually putting some messasge back in the buffer, although doing so is not compulsory.

Schedule

Run


(The except one could be a process that crashed)

### The proof

Classifying configuration

The existence of 0-valent and 1-valent is trivial, however we need to prove that bivalent configurations exist.

>Lemma 1:

>Lemma 2:

>Lemma 3:

### Getting around FLP




