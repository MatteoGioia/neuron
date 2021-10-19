# Battery free IoT

## Recall questions
        - What is IoT? What is the end use and what are the challenges?
        - What is a smart object? What makes it different from a simple network device?
        - What are the required features of smart objects?
        - Can we make smart objects without battery? How? What are the drawbacks?
        - RFID + sensors (explain)

## Iot basics

### Internet of Things

The term is used to ==refer to==:
1. the ==global network== resulting from the ==interconnection of smart devices==
2. ==set of supporting technologies necessary to support the IoT vision==
3. ==the mix of applications and services leveraging smart devices==

==Challenges of IoT:==
- ==scalability==
- ==self-management of smart devices==

The ==end goal is to create a standar representation of smart objects even if they are heterogenous and to integrate
this devices in apps/services to enrich them.==

For the end user, ==this translates in having smart devices/object able to help== him ==in the daily life== with adequate response times.

### Smart objects 

A ==smart object is an entity that:==
- has a ==physical embodiment==
- has a ==minimal set of communication functionalities==
- is ==associated with a name and an address==
- has ==basic computing capabilities==
- is ==able to sense physical phenomena, this is also what makes it different from a simple network device==

A ==smart object must be:==
1. ==identifiable==
2. ==able to communicate==
3. ==able to interact==, with other smart devices or the end user

We consider smart devices also RFID, WSN sensors and sensors/actors networks (SANET)

### Required features for IoT devices

==Required features:==
- ==heterogeneity support== (multiple devices of different types must be able to communicate with each other)
- ==scalability==
- ==ubiquitous data exchange so also semantic interoperability==
- ==energy optimisation==
- ==localisation and tracking capabilities==
- ==self organisation capabilities==
- ==privacy and security==

## Battery free IoT

In the following we will see low power networks that use the LLN (low power lossy network) protocol built by the IETF.

### Smart objects with no battery

==IoT with battery free devices is achieved through the use of backscattering.== There exist low power devices
that are able to ==use radio frequencies to power themselves.==

The ==backscattering used in this case is ambient backscattering: the signal emitted by other devices in the environment
is exploited to draw power and to operate.==

### Characteristics of ambient backscattering

Ambient backscattering is:
- ==low datarate==
- ==not always available (e.g. if no devices that emits radio waves is around)==
-==weak (range is an important drawback)==

### Sensor augmented RFID tags

We can build ==RFID tags with sensors embedded==
- see the SapJoy example for reference
- they achieve ==low latency when used alone, but protocols for efficient use of multiple devices needs to be studied==
