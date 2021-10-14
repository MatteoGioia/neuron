# Routing protocols 

## Recall questions
        - WIP
        
## Routing in Ad Hoc Networks and WSN

### Classification

We can classify the routing protocol depending on:
- the newtork topology: flat (our case), hieararchical..
- which data is used for..

### Flat routing protocols

Three main categories, depending on when the protocol operates:
- proactive or table driven: the tables are created before the routing is actually needed
- reactive or on demand: routes are built only when needed
- hybrid: combination of the proactive/reactive

### Proactive and DSDV

Each nodes mantains the routing table to the reachable nodes. When a new node is added, the new route is updated.

This type of protocols consumes a lot of energy, since its's always running, but allows to have the routes ready whenever needed.

DSDV () is a protocol that reduces the energy consuption

(Immagine)

DSDV is vulnerable to rooting loops, so we need to keep track of a sequence number...

### Reactive 

In this type of protocols the route is computed only when requested. This introduces a delay since most of the routes have to be computed.
- there could be a cache that slightly reduces the delay

The following reactive protocols will be examined:
- flooding
- gossiping
- dynamic source rooting


### Flooding

This tecnique does not need routes ..

Properties:
1. if there is a route, it will always be found
2. one packet will travel through the fastest route

Drawbacks:
1. superfluous traffic
2. implosion 
3. overlap
4. resource blindness
5. overall low energy efficiency

### Gossiping

Similar to flooding, but only one node, randomly choosen, receives the packet.

### Dynamic source rooting (DSR)

This protocol...

Two main mechanisms:

### Ad Hoc On Demand Vector Routing

In this case, 

### Geographic routing

Protocol type usually employed in WSN. The idea is that packets can be sent into the direction of the destination,
assuming the intermediate nodes are actually in that direction.
