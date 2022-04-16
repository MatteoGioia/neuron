# Cloud Storage

### Recall questions

1. <details markdown=1><summary markdown="span"> What is atomicity?  Explain the 2 possible types. </summary>
    
    \
    We want ==multi step operations that complete without any interruption==. Two types are:
    - ==all or nothing==: ex 2PC protocol (see #[[DS II - Reaching Consensus]])
    - ==before or after==: the result of every write/read is the same no matter the order.

</details>

2. <details markdown=1><summary markdown="span"> What is the storage model and what are 2 possible types? What properties should it guarantee? </summary>
    
    \
    It is  a model that ==describes the layout of a data structure in physical storage==. Two possible types are:
    - ==cell storage==
    - ==journal storage==

    We also want the model to guarantee ==read/write coherence== and the previously mentioned forms of ==atomicity==.
    
</details>

3. <details markdown=1><summary markdown="span"> Describe how the cell storage model works (what does it reflect?). Which assumption are made? What properties are guaranteed?</summary>
    
    \
    In the cell storage model, we assume that:
    - ==cells have the same size==
    - each ==object fits exactly in one cell==
    - ==read/write unit are either sectors or blocks==

    The structure of the model ==reflects the physical organization of common storage media==. \
    It guarantees ==read/write coherence==, ==before or after atomicity==.
    
</details>

4. <details markdown=1><summary markdown="span"> How does the journal storage model work? Describe how the log works. What properties are guaranteed? </summary>
    
    \
    In this model, we have a ==manager and cell storage==. The idea is that ==the manager will interact with the cells, while the user can use an API to communicate with the manager==. 
    There is also a ==log to mantain the history of each cell==. \
    It guarantees ==all-or-nothing atomicity==.

</details>

5. <details markdown=1><summary markdown="span"> What are possible types of file system? </summary>
    
    \
    Possible types are:
    - ==network file system== (HP)
    - ==storage area network==
    - ==parallel file system== (HP)

    In the following we'll focus on high performance file systems.
    
</details>

6. <details markdown=1><summary markdown="span"> Describe (briefly) the network file system. </summary>
    
    \
    The nfs is characterized by:
    - ==client server model==
    - ==rpc interaction==
    - ==no scalability==
    
    ![](../../../static/CLD/clds1.png)

</details>

7. <details markdown=1><summary markdown="span"> How does the general parallel file system work? </summary>
    
    \
    The idea behind the PFS is to ==allow multiple clients to read and write concurrently from the same file==. It uses ==RAID== and is also able to recover from failure through the use of ==logs==.

</details>

8. <details markdown=1><summary markdown="span"> What is the goal behind the design of the GFS? What are its characteristics? </summary>
    
    \
    The google file system is ==built to manage petabytes of storage==. Its design is based on:
    - ==high reliability==
    - careful analysis of the file characteristics (?)
    - access model (?)
    
</details>

9. <details markdown=1><summary markdown="span"> What are the main features of the GFS? </summary>
    
    \
    Main features:
    - ==focus on appends== rather than random writes
    - ==sequential reads==
    - ==relaxed consistency==

</details>

10. <details markdown=1><summary markdown="span"> How are files in the GFS structured? Why? </summary>
    
    \
    Files in the GFS consist of ==multiple chunks==, to allow for ==better performance when dealing with large files== and ==reduce disk fragmentation==. 
    

</details>

11. <details markdown=1><summary markdown="span"> What is the architecture of a GFS cluster? </summary>
    
    \
    ![](../../../static/CLD/clds2.png) \
    While not shown in the picture, an operation log is mantained in order to recover from potential failures.

</details>

12.  <details markdown=1><summary markdown="span"> How does file access and creation work in the GFS? </summary>
    
    \
    In case of an access, the ==master guarantees a lease on a certain chunk==. In case of creation, ==the master is directly responsible==. (?)
    

</details>

13.  <details markdown=1><summary markdown="span"> And file write ? </summary>
    
    \
    ![](../../../static/CLD/clds3.png)

</details>

1.   <details markdown=1><summary markdown="span"> ? </summary>
    
    \
    

</details>