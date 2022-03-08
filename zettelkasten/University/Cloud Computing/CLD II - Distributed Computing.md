# Distributed computing

### Recall questions

Structure of the lecture:
![](./static/CLD/cds2.png)


1. <details markdown=1><summary markdown="span"> Why is cloud computing a specialized form of distributed systems? </summary>
    
    \
    CC is a ==specialized form of DS that introduces utilization models for remotely provisioning scalable and measured resources==. \
    It appears an ==one whole resources== to the users and relies on ==messages for communication==.

</details>

2. <details markdown=1><summary markdown="span"> What is the architectural style of a DS? </summary>
    
    \
    Defines the ==hardware architecture of the system and the role of each component==. The logical view is handled by the the SW architecture.

</details>

3. <details markdown=1><summary markdown="span"> What are the 5 main styles of SW? </summary>
    
    \
    5 main styles:
    - ==call and return==;
    - ==indipendent components==: multiple decoupled component;
    - datacentered;
    - data flow;
    - virtual machine.

</details>

4. <details markdown=1><summary markdown="span"> What are 2 possible types of call and return architecture? </summary>
    
    \
    Call and return:
    1. ==top down approach== to break functions into multiple ==sub-procedures (components)== executed by multiple nodes calling them (==messages = call to function==);
    2. layered approach to create ==multiple layers of abstraction, as seen for example in communication protocols==.

</details>

5. <details markdown=1><summary markdown="span"> What are 2 possible types of indipendent components architecture? </summary>
    
    \
    Indipendent components:
    1. ==event based==, in which each process can interact with each other through ==lists of events==. A process can publish his list of events and the "interested" processes can subscribe to that list.
    2. ==microservices==

</details>

6. <details markdown=1><summary markdown="span"> What are microservices more in detail? What are the main characteristics of these services? </summary>
    
    \
    Architectural style that ==structures an application as a collection of services== that are:
    - highly mantainable and testable
    - ==loosely coupled==
    - ==indipendently deployable==
    - managed by a small team

</details>

7. <details markdown=1><summary markdown="span"> What are the 3 possible scaling techniques? What is the new dimension introduced when considering microservices? </summary>
    
    \
    ![](./static/CLD/cds1.png) \
    Microservices allow for ==functional scaling==, i.e. scaling only those services that are creating a bottlebeck (impossible with duplication or data partitioning.)

</details>

8. <details markdown=1><summary markdown="span"> What are the advantages and drawbacks of microservices? </summary>
    
    \
    Advantages: besides the ones mentioned before, the are:
    - ==fault isolation==
    - possibility for ==continous delivery and deployment==
    Drawbacks:
    - deciding ==which microservices to use is not simple==;
    - a micro-services based cloud is as ==hard to manage as a distributed systems==, so all the problems of DS apply.

</details>

9. <details markdown=1><summary markdown="span"> What are the 2 main system architectural styles? </summary>
    
    \
    SA styles:
    - ==client/server (C/S)==
    - ==p2p: highly scalable and decentralized, need to handle consistency==

</details>

10. <details markdown=1><summary markdown="span"> What are 3 possible structures for the C/S model? How does each model handle the application, data storage and presentation layers?</summary>
    
    \
    Three modes:
    - ==thin client==: server handles data and application logic, client handles the presentation;
    - ==fat client==: server handles data, client handles application logic and presentation;
    - ==multi tiered==: data storage, application logic and presentation are seen as multiple tiers that can be scaled according to the needs of the users.

</details>

11. <details markdown=1><summary markdown="span"> What ? </summary>
    
    \
 

</details>