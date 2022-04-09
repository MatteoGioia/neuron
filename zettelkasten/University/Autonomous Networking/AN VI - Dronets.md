# Dronets

## Recall questions
        - What are the main uses of dronets?
        - Which routing protocols can be employed in dronets?

## Drones (UAV)

A drone, also called Unmanned Aerial Vehicle, is an aircraft without a human pilot aboard.
There are multiple types of drones, depending on weight, speed, fuel used.

Most commercial drones can fly 30' and have multiple shapes, like helicopters or airplanes depending on the usecase.
They are also usually employed as a single unit.

Our study regards instead the utilization of multiple drones in a DRONET a.k.a. network of drones.
In most cases, the data that needs to be delivered is quite large so drones must rely on the
neighbours to send packets to the depot (sink).

### Using DRONETS to provide connectivity

==DRONETs can be used to provide connectivity in disaster areas.== Using their own wifi, for instance, they
can create a network for a user to connect to. Since the range of wifi is limited though each drone needs to
rely on the others for routing data.

DRONETs can be also equipped with:
- cellular data
- LoRa or Low Power Wide Area Network 

During a mission, though, we can't assume that all drones are connected. Some of them will be disconnected 
from the rest of the drones. 

### Routing in DRONETs

DRONETs:
- are highly mobile, since they need to be used for example for in disaster area
- have a mesh topology, but it's jeopardized
- have no infrastracture, so no fixed point except for the sink
- are battery powered

As expected, ==conventional routing protocols do not work optimally in the context of routing==.

![](../../..//AN/dronets1.png)

==Because of this, the routing protocols of choiche for DRONETs are geographic protocol==, although reactive routing protocols could work if mobility is not too high.

Since the protocol does not use routing tables, the only information required and kept is about the neighbour drones.
Each drone signals its presence to the neighbours with a beacon signal and the drone that allows to get the closest to the destination is chosen.

### Actual implementation of Geographical Routing

1. ==Store-carry and forward==: the drone stores the packet and eventually sends it to drones it meets along the way, if one is present. Otherwise, the drone itself goes to the destination.

2. ==Greedy forwarding==: the drone closest to the destination is always chosen to forward.
- this protocol does not work well as the receiver could be going in the opposite direction of the destination 

3. ==Prediction==: the drone sends the packets based on prediction of the other drones position's 



