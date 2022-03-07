# Spark

1. <details markdown=1><summary markdown="span"> What are the 2 ways of generalizing the MapReduce protocol? </summary>

    \
    Generalizations:
    - ==adding more than 2 ranks==: as long as the data flow goes in one direction the recovery is possible even at intermediate ranks
    - allowing for ==more functions== than just map and reduce

</details>

2. <details markdown=1><summary markdown="span"> What does spark offer? </summary>

    \
    On top of MapReduce functions, it allows for:
    - fast data sharing
    - general execution graphs 
    - richer functions 

</details>

3. <details markdown=1><summary markdown="span"> What is the structure of Spark? </summary>

    \
    ![](./static/BIG/sp1.png) \
    Note that spark ==does not provide a storage solution==, but APIs for the most common solutions.

</details>

4. <details markdown=1><summary markdown="span">  What are Spark's main features? What is the one that makes it so fast?</summary>

    \
    Features:
    - fault tolerance
    - ==in memory chaching== (no persistence on memory)
    - can be executed locally or on a cluster 

</details>

5. <details markdown=1><summary markdown="span"> What is the driver process? What does it do? </summary>

    \
    ==Runs the entry point== for the application and acts as an "orchestrator". It is ==equivalent to the master node== in MapReduce terminology. It's ==represented by a spark context==.

</details>

6. <details markdown=1><summary markdown="span"> What are executors processes? What to they do? </summary>

    \
    These processes ==complete the task assigned by the driver and return a feedback==. It is ==analogous to the workers== in MapReduce.

</details>

7. <details markdown=1><summary markdown="span"> What is a resilient distributed dataset and what is it similar to? Can they be split? What are they suited for?</summary>

    \
    A ==RDD is an abstraction used by spark to indicate a collection of elements of the same type==. It is ==similar to the key-value pairs== of MapReduce. \
    RDDs ==can be split into partitions== and spread across multiple nodes of the cluster in chunks. \
    ==Ideal for apps that apply operations on the whole dataset.==

</details>

8. <details markdown=1><summary markdown="span"> What do partitions allow to do? </summary>

    \
    Partitioning allows to:
    - ==reuse data quicker==, since it "stays" loaded into the executors memory
    - ==parallelism==
   
</details>

9. <details markdown=1><summary markdown="span"> What are the characteristics of RDDs?</summary>

    \
    RDDs are:
    - ==immutable==
    - can be created from data stored on a DFS or using operations on an RDD
    - ==not necessarily materialized==: this allows for easy reconstruction (==a lineage of the transformations is kept instead==) and lazy materialization

</details>

10. <details markdown=1><summary markdown="span"> What operations are possible on an RDD? </summary>

    \
    Given an RDD $A$, we can perform:
    - a ==transformation==: creates RDD $B$ from $A$
    - an ==action==: launch a computation on the data in $A$, which ==returns a value== to the application
    - ==persistence==: save the RDD in main memory for later actions
   
</details>

11. <details markdown=1><summary markdown="span"> What are the 2 possible types of transformations? </summary>

    \
    Two main types:
    - ==narrow==: each partition of $A$ contributes ==at most to one== partition of $B$, requires no data transfer
    - ==wide==: each partition of $A$ contributes ==to more than one== partition of $B$, requires data transfer
   
</details>

12. <details markdown=1><summary markdown="span"> What are the possible actions?</summary>

    \
    An action is for example counting! Note that ==actions==, differently from transformations, ==require persistence in memory==.
   
</details>

13. <details markdown=1><summary markdown="span"> What are Spark dataframes?</summary>

    \
    They are ==similar to Pandas dataframes, but they are immutable==. Furthermore, ==they work leveraging the RDD architecture== previously explained, so they can be much faster than, say, a pandas dataframe.
   
</details>