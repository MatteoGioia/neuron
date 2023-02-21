# MAC in WSN

## Recall questions
        - What are the main sources of energy waste in WSN?
        - How do contention based protocols work? How are contentions managed?
        - What are the possible choices for IFS length?
        - How can we solve the hidden and exposed terminal protocols? 
        - What is virtual carrier sensing? How can it be used to optimise energy consumption?
        - What is S-MAC and how does it work? How is synchronization achieved? 
        - How can we manage the sleep of big clusters?
        - Describe how the efficiency of the S-MAC varies depending on the load.

## Managing collisions in WSN

### Energy waste

Energy effiency is on the key points in WSN. However, ==energy waste== can happen for a variety of reasons:
- ==collision==: colliding packets have to be retransmitted
- ==overhearing==: the sensor receives packet meant for others
- ==idle listening==: listening to an idle channel in order to catch incoming packets
- ==Control Packet Overhead==: more control packets require more processing power (and thus energy)
- ==overemitting==: nodes transmit a message when the others are not ready, so they have to transmit again

### Communication patterns

Broadcast: used to send queries to nodes, program updates and control packets

Convergecast: used by nodes to answer to the queries

### Contention based protocol

In this protocol, the channel is contented by all the nodes. So we have to avoid collisions, since in WSN collision detection is impossible.

![](../../../AN/wsnca.png)

The ==protocol works as described by the image==:
1. if the channel is idle, the sensor waits for the IFS and then sees if the channel it's idle again and goes to step 2; if the channel wasn't idle in the first place the sensor just waits and then goes back to step 1 instead;
2. if the channel is idle the node trasnmits and then waits an exponential backoff, monitoring the channel ready to restart (step 1);if a collision is detected the node goes into an random backoff and then tries again (step 3);
3. if the channel is now free, the node can transmit, otherwise it increases his backoff time.

The ==backoff time is randomly chosen between 0 and a Contention Window CW value==, that gets doubled with each collision. The first node that ends his backoff time then transmits, while the other freeze their clock and start counting again after the transmission ended.

### Choosing an appropriate IFS

==Different lengths of IFS are used for different applications==:
- ==SIFS or Short IFS==: immediate response
- ==PIFS or Point Coordination Function IFS==: used for centralized controller in PCF scheme when using polls
- ==DIFS or Distributed Coordination IFS==: minimum delay of asynchronous frames contending for access.

### Dealing with the hidden and exposed terminal problem

In both cases, ==we can use the RTS/CTS mechanism, to communicate when the channel is free==.

![](../../../AN/hiddensolve.png)

In this case of the hidden terminal (C hid from A), the collision is prevented because C overhears the CTS and inhibits its own transmitter.

![](../../../AN/exposedsolve.png)

In this case of the exposed terminal problem (C exposed to B), C can transmit because although it has overheard the RTS from B, it didn't hear any CTS, so it assumes the node that B tries to communicate with is out of range (or down).

==Collisions between RTS packets can be managed with a backoff==
- RTS packets are generally really small so the collision issue if far more unlikely

## Making MAC more efficient

### Network allocation vector

On top of the techniques mentioned earlier, more optimisations can be done to achieve higher energy efficiency.

==For instance, all other nodes could stop listening to the channel if they know it's being used(overhearing). This is achieved through Virtual Carrier Sensing and the use of a Network Allocation vector.==

==When a node sends a frame it also contains information on how long it is going to use the channel, so the other nodes can stop listening==. When there is a RTS by a node, and a CTS in response, the other nodes turn the NAV signal on. When the communication ends (ACK), the NAV signal is turned off.

### S-MAC 

To reduce the time spent in idle listening ==the sensor can alternate periods of listening and sleeping==
- this increases radio efficiency but greatly increases latency

==Each node goes into sleep mode periodically==.

This method requires periodic synchronization between nodes. To reduce sleep overhead, neighbour nodes have a common schedule, so they listen and sleep at the same time.
- even though each node can choose its own schedule

To achieve synchronization, each node has a ==table with the schedule of the neighbours==.

Sync packets are exchanged periodically to share the schedule of each node.

![](../../../AN/sleepWSN.png)

The ==node that proposes the schedule is called a Synchronized, the others that adopt the schedule are called Follower==.

### Coordinating sleep in large networks

==To coordinate sleeping among large clusters, we use border nodes that keep the schedule of both clusters.==
These nodes work a bit more because they might have to send packets twice, i.e. for the 2 schedules they are following.

### Putting everything together

The end result is a mix of CSMA/CA to avoid collisions, NAV to improve efficency and with sleep cycles to increase energy efficiency.

### Performance of S-MAC

Comparing S-MAC with periodic sleep with other protocols shows that the ==improvement in energy consumption is significant
even if the traffic load is ligther==. ==When the traffic is higher, S-MAC without sleep performs similarly to S-MAC with sleep==.

Average energy consumption:

![](../../../AN/averageenergy.png)