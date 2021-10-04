# RFID

## Recall questions

## Radio Frequency Identification

### What is an RFID system

2 main components:
- RFID labels that store a unique ID with the tag inside them (96 bits)
- RFID reader that qureries tags to get their ID

The most common use of RFID is object identification:
- access control object tracking
- domotics and assisted living

### Types of communication

Reader to tag or tag to reader
- tag to tag doesn't work 

The tags work with back-scattering: when they receive the signal from the reader
they use its energy to send a response

The topology of this network is a star.

### RFID channel

The RFID channel is:
- wireless
- shared
- low datarate 
- simultaneous, so collision is possible

Transimission range is usually 0-10m depedning on obstructions.

### Collision avoidance

Collision detection (CD) / Carrier sense (CSMA) is pretty much impossible since tags can't communicate spountaneously with each other.
This means that the reader must decide how tags access the channel.

Proposed protocols to solve the issue:
- sequential: make tags transmit one at the time
- concurrent: detect collision with signal processing

## Sequential protocols

### Binary splitting

In this protocol, the queries is done multiple times until only node responds.
The principle is called binary splitting cause the splitting is based on the random generation of a binary number.

Binary splitting:
1. each tag initially has a counter set to 0
2. reader sends a query
3. all tags reply and there is collision, then they generate a ...

(inserire immagine)

### Query tree

In this protocol, the tags split based on their ID. The reader sends a string and only the tags with such string in the ID
answer to the query.

(Immagine)

### Performance of tree protocols

System efficiency : $SE = \frac{n}{q}$
- where $n$ is the number of successful queries (and of tags)
- and $q$ is the number of queries

Only the ideal optimal protocol has $n=q$. We can estimate the efficiency of tree looking at the average
with a binomial distribution:

(Immagine qui)

For Binary Splitting $SE = 0.38$, and for $QS = 0.38$ 
- so the efficiency is pretty low

### Framed Slotted Aloha 

In aloha a ...

Performance of FSA is $SE = 0.37$

### Standard protocol

The protocol used in RFID is EPC GEN 2 class 1, and is based upon FSA. The following is a simplied version of the protocol.
The EPC GEN 2 adapats the size of the frame depending on the number of collisions.

Idle slots are less expensive than collision one, so we can enlarge the idle slots.

(Immagine)

Ideally, knowing how many tags are in the environment leads to higher performance. Overestimating is also 
more efficent than underestimating.
- but identifying the number of tags is not a trivial problem

### Tree slotted aloha

## Estimating the number of tags

### ..

### Binary Splitting Tree Slotted Aloha
