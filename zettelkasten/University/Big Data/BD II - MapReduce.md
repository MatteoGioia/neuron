# MapReduce

1. <details>
    <summary> What is MapReduce? What are the 3 main characteristics?</summary>
    Programming model for processing big data sets with paralllel, distributed agorithms on a cluster.
    It ensures redundancy, minimal data transfer and a simple computational model to hide complexity.
</details>

2. <details>
    <summary> What does the distributed file system ensure? What is the common usage pattern?</summary>
    Global file namespace and availability across nodes in a cluster. Used for large files, #reads >> #updates.
</details>

3. <details>
    <summary> What are the 3 main components of a standard implementation?</summary>
    Chunk servers, Master Nodes, Client API
</details>

4. <details>
    <summary>What is a chunk? And a chunk server? Is the chunk unique?</summary>
    Chunk = part of a file (e.g. 64MB), Chunk server  = one of the nodes where the chunk is. Each chunk server computes operations related to its chunks .
    <br> One chunk is replicated across multiple nodes/racks.
</details>

5. <details>
    <summary> What is a master node? What does it do? Is it unique? </summary>
    Stores metadata about the chunks and their location. It's replicated. 
</details>

6. <details>
    <summary> What is the client API? Is it necessary to interact with the master node each time?</summary>
    Client uses API to query the master node for a specific file location.
    Note that subsequent communications don't have to go through the master node again.
</details>

7. <details>
    <summary> Suppose we have to count how many times each word appears in a hugeee document. What are 2 possible scenarios? </summary>
    1. Results fit into memory 2. Results do not fit into memory.
</details>

8. <details>
    <summary> Assume we use a hashmap with key/value pairs to solve the problem. Does this solution still works in the 2nd scenario?</summary>
    No lol.
</details>

9. <details>
    <summary> What are the steps of Map Reduce? What functions must be implemented?</summary>
    Input and Output = (key, value) pair.
    <br> Map, Reduce. The shuffle function is provided by the framework.
</details>

10. <details>
    <summary> What does the map function do?</summary>
    <div>
    
    $map(k_i, v_i) \to \{(k_i', v_i')\}^*$ 
    
    </div>

    Function that starts from a key/value pair and returns a set of >= 0 key/value pairs.
    <br> In our case, the starting key/value could be the chunk ID and its contents.
</details>

11. <details>
    <summary>What does the reduce function do? </summary>
    <div>

    $reduce(k_i',\{v_i'\}^*) \to \{(k_i',v_i'')\}^*$

    </div>

    Function that reduces to one entry all the values with the same key.
</details>

12. <details>
    <summary> Describe each step of the map-reduce process.</summary>
    Map = generation of the pairs + tables.
    <br> Shuffle = aggregation of values with same key.
    <br> Reduce step = sum all values of pairs with the same keys.
</details>

13. <details>
    <summary> What are the pros/cons of MapReduce?</summary>
    Pros: good 4 sequential data access, large batch jobs.
    <br> Cons: random access, graph, interdependent data.
</details>

14. <details>
    <summary> What data is stored on the DFS?</summary>
    Input and output. The intermediate steps are not persisted.
</details>

15. <details>
    <summary> What we have seen so far is how MapReduce would operate if it were on a single chunk. What issue must be addressed during the shuffling phase if we are working with a cluster?</summary>
    When dealing with multiple nodes, the entries obtained after the map phase must be regrouped into proper sets with the same key/value pairs that are then fed to the reducers.
</details>

16. <details>
    <summary> What are the possible states of worker nodes? How does the master node know their state?</summary>
    Idle, in progress, completed.
    <br> Each node will send a notification when the task it's working on it's completed. The master node also periodically pings the other nodes.
</details>

17. <details>
    <summary>What happens when a map node fails? What if a reducer node fails? What if the master fails?</summary>
    If a map worker node fails, it's reset to idle and all its task are reset and re-scheduled (both in progress and finished).
    <br> In case of the reducer, only in progress tasks are re-scheduled.
    <br> If the MN fails, all the map reduce process is restared.
</details>

18. <details>
    <summary> What is a good rule of thumb to decide the number of map/reduce tasks? Why are these proportions good? </summary>
    Ideally, we want M >> N and R < M. The first ensures fast recovery, the second allows for the output to be spread over a limited number of nodes.
</details>

19. <details>
    <summary> Describe how a MapReduce implementation handles a natural join (on 2 tables). How is this used when MapReduce is implemented on a DFS? </summary>
    Using an hash function, one can create an intermediate representation and send all the key/value pairs with the same hash value to the same reducer. See slide 98 for the complete explanation.
</details>

20. <details>
    <summary> What is the downside of this implementation when it comes to reduction? How can we fix it? </summary>
    We have to send several values with the same key not aggregated. We can use combiners to pre-aggregate the values at the mapper's end.
</details>

21. <details>
    <summary> What is the downside of combiners?</summary>
    They can only be used if the operation is commutative and associative. E.g. addition/multiplication is ok, average is not.
    Note that the average can be still computed by decoupling in pairs (sum, count).
</details>

22. <details>
    <summary> What is a partition function? What is a simple implementation? </summary>
    The partition function decides how the key/value pairs will be split among the reducers.
    <br> Assuming R reducers, it is a simple as 
    <div>

    $hash(key) \mod R$

    </div>
</details>

23. <details>
    <summary> What are the 2 main criticisms of MapReduce?</summary>
    1) Not all problems nicely translate to a MapReduce formulation.
    <br> 2) I/O communication bottlenecks will cause performance issues.
</details>