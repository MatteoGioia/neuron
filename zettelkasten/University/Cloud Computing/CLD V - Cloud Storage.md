# Cloud Storage

### Recall questions

1. <details markdown=1><summary markdown="span"> What is atomicity?  Explain the 2 possible types. </summary>
    
    \
    We want multi step operations that complete without any interruption. Two types are:
    - all or nothing: ex 2PC protocol (see [[DS II - Reaching Consensus]])
    - before or after: the result of every write/read is the same no matter the order.

</details>

2. <details markdown=1><summary markdown="span"> What is the storage model and what are 2 possible types? What properties should it guarantee? </summary>
    
    \
    It is  a model that describes the layout of a data structure in physical storage. Two possible types are:
    - cell storage
    - journal storage

    We also want the model to guarantee:
    - read/write coherence
    
</details>

3. <details markdown=1><summary markdown="span"> Describe how the cell storage model works (what does it reflect?). Which assumption are made? What property is guaranteed?</summary>
    
    \
    In the cell storage model, we assume that:
    - cells have the same size
    - each object fits exactly in one cell
    - read/write unit are either sectors or blocks

    The structure of the model reflects...

    The model is built to reflect...
    
</details>

4. <details markdown=1><summary markdown="span"> How does the journal storage model work? Describe how the log works. </summary>
    
    \
    In this model, we have a manager and cell storage. The idea is that the manager will interact with the cells, while the user can use an API to communicate with the manager. \
    There is also a log to mantain the state...

</details>

5. <details markdown=1><summary markdown="span"> Recap the properties guaranteed by each storage model. </summary>
    
    \
    

</details>

6. <details markdown=1><summary markdown="span"> What are possible types of file system? </summary>
    
    \
    Possible types are:
    - network file system
    - storage area network
    - parallel file system
    
</details>

7. <details markdown=1><summary markdown="span"> Describe (briefly) the network file system. </summary>
    
    \
    The nfs is characterized by:
    - client server model
    - rpc interaction
    - no scalability 
    
    ![](../../../static/CLD/clds1.png)

</details>

8. <details markdown=1><summary markdown="span"> How does the general parallel file system work? </summary>
    
    \


</details>

9. <details markdown=1><summary markdown="span"> What is the goal behind the design of the GFS? What are its characteristics </summary>
    
    \
    The google file system is built to manage petabytes of storage. Its design is based on:
    - high reliability
    - careful analysis of the file characteristics (?)
    - access model (?)
    
</details>

10. <details markdown=1><summary markdown="span"> What are the main features of the GFS? </summary>
    
    \
    

</details>

11. <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    FILES in the GFS
    

</details>

12. <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    ARCHITECTURE

</details>