# Distributed computing

### Recall questions

Structure of the lecture:
![](./static/CLD/cds2.png) 
 
Read this for more info on SOA vs Microservices: https://www.ibm.com/cloud/blog/soa-vs-microservices


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

11. <details markdown=1><summary markdown="span"> What is the goal of IPC? What are possible solutions? </summary>
    
    \
    IPC ==connects the SW components and allows them to share data in form of messages==. \
    Solutions:
    - ==RPC== : procedural style
    - ==DO/DOF== : OO style
    - ==SOA==: service oriented

</details>

12. <details markdown=1><summary markdown="span"> What is RPC and how is it implemented? What is the expected underlying architectural model? What is the content of the messages? </summary>
    
    \
    Remote procedure call ==allows to execute procedures (functions) on other machines==. It is implemented as ==RPC Library== and ==RPC Service==. The underlying architectural model is a ==C/S model==. \
    The ==messages are automatically created and contain all the value necessary to compute the final result==. Note that messages must be ==marshalled== to be able to be sent between nodes.

</details>

13. <details markdown=1><summary markdown="span">  What is the Distributed Object style? Same questions as above.</summary>
    
    \
    Like ==RPC for OO==, but the ==methods are exposed by objects through interfaces==. The underlying arch. model is C/S.  

</details>

14. <details markdown=1><summary markdown="span"> What are the "problems" introduced by DO?  How is this addressed (how is the lifetime of the objects responsible for exposing such interfaces managed)? What are possible ways of marshaling in the OO case and the advantages/drawbacks?</summary>
    
    \
    RPC is stateless, but DO must take into account the state of the objects and their lifetime.  \
    For what regards the objects exposing the interfaces, it depends on the model:
    - ==server based==: object has its own life
    - ==client based==: object creating only to execute the remote procedure

    For what regards marshaling, it can either be done by ==value==, duplicating the object, or ==by reference, through an object proxy and an object skeleton== - the latter being more consistent but also more complex.

</details>

15. <details markdown=1><summary markdown="span"> How is service oriented architecture implemented? </summary>
    
    \
    A ==software component== with the following characteristics is ==incapsulated in a service==:
    - ==explicit boundaries==
    - ==autonomous services==: indipently deployable, failure tolerant, etc...;
    - ==shared schema and contracts==: contracts expose the structure of services/messages;
    - ==compatibility based on policies==

</details>

16. <details markdown=1><summary markdown="span"> What are the 2 main roles in SOA? </summary>
    
    \
    We have 2 major roles:
    - service ==provider==
    - service ==consumer==
    
    And 3 components:
    - service consumer and provider
    - service ==registry==: it contains ==metadata on available services== and the server in which they are ==located==

</details>

17. <details markdown=1><summary markdown="span"> How can services be coordinated and managed? </summary>
    
    \
    We have 2 ways of managing services:
    - ==orchestration: the orchestrator coordinates the services==
    - ==choreography==: no orchestrator

</details>

18. <details markdown=1><summary markdown="span">  What are enterprise features of SOA?</summary>
    
    \
    Features:
    - ==Standardized service contract==: to facilitate interoperability
    - ==Loose coupling== 
    - ==Abstraction==: to hide technical implementation details
    - ==Autonomy==: services control themselves
    - ==Lack of state==:  stateless to foster reuse and multiple customers support
    - ==Discoverability==: description documents other then schema and contract
    - ==Composability==: by means of orchestration/choreography

</details>

19. <details markdown=1><summary markdown="span"> How do web services leverage SOA? </summary>
    
    \
    ![](./static/CLD/cds3.png)

</details>

20. <details markdown=1><summary markdown="span">  What is REST? What was its predecessor? What does it allow?</summary>
    
    \
    Created as an alternative to SOAP, ==REST stands for Representational State Transfer== and allows to ==use HTTP methods to implement operations requested by Web Services==.

</details>

21. <details markdown=1><summary markdown="span"> What are the 4 characteristics of REST services? </summary>
    
    \
    REST services follow 4 basic design principles:
    - be ==stateless==
    - use ==HTTP methods explicitely==
    - transfer ==XML,JSON== or both
    - ==expose directory structure like URIs==

</details>

22. <details markdown=1><summary markdown="span"> How are CRUD actions mapped to REST operations? </summary>
    
    \
    Mappings:
    - create $\to$ POST
    - retrieve $\to$ GET
    - update/change state $\to$ PUT
    - remove/delete $\to$ DELETE

</details>

23. <details markdown=1><summary markdown="span"> What are the main differences between SOA and Microservices? Discuss w.r.t. to communication, data and size of the services. </summary>
    
    \
    SOA:
    - communication: ==slow, complex, uses SOAP==
    - data: ==global data model + shared server==
    - size: ==few large services==

    Microservices:
    - communication: ==REST + message broker==
    - data: ==each microservice has its own server==
    - size: ==many small services==

</details>