# MAC in WSN

## Recall questions
        - WIP

## Managing collisions in WSN

### Energy waste

Energy effiency is on the key points in WSN. However, energy waste can happen for a variety of reasons:
- collision
- overhearing
- idle listening
- control Packet Overhead
- overemitting

### Contention based protocol

In this protocol, the channel is contented by all the nodes. So we have to avoid collisions,
since in WSN collision detection is impossible.

(Immagine Collision Avoidance)

### Dealing with the hidden and exposed terminal problem

In both cases, we can use the RTS/CTS mechanism, to communicate when the channel is free.

(Doppia immagine)

Collisions between RTS packets can be managed with a backoff
- RTS packets are generally really small so the collision issue if far more unlikely

## Making MAC more efficient

### Network allocation vector

On top of the tecniques mentioned earlier, more optimisations can be done to achieve higher energy efficiency.
For instance, a network allocation vector can be used to block all other nodes from listening to the channel (overhearing).
..

### S-MAC 

To reduce the time spent in idle listening the sensor can alternate periods of listening and sleeping
- this increases radio efficiency but greatly increases latency

This method requires periodic synchronization between nodes. To reduce sleep overhead, neighbour nodes have a common schedule, 
so they listen and sleep at the same time.

To achieve synchronization, each node has a ==table with the schedule of the neighbours==.

(Immagine)

Sync packets are exchanged periodically to share the schedule of each node.

### Coordinating sleep in large networks

To coordinate sleeping among large clusters, we use border nodes that keep the schedule of both clusters.
These nodes work a bit more because they might have to send packets twice, i.e. for the 2 schedules they are following.

### Putting everything together

The end result is a mix of CSMA/CA to avoid collisions and with sleep cycles to increase energy efficiency.

### Performance of S-MAC

Comparing S-MAC with periodic sleep with other protocols shows that the improvement in energy consumption is significant
even if the traffic load is ligther. When the traffic is higher, S-MAC without sleep performs similarly to S-MAC with sleep. 