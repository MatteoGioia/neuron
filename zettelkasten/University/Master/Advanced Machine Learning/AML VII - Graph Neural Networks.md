# GNNs

Also see:
- [[../Deep Learning and AI/DLAI IX - Geometric]]

Setup:

![](gnn1.png)

### Recall questions

1. <details markdown=1><summary markdown="span"> What additional information is included in GNNs? How can we aggregate it?  </summary>
    
    \
    In GNNs, we leverage ==the neighbourhood== of each nod: ==the computational graph is determined by each node's neighbours. Each neighbour will send a message containing their features==.

	![](gnn2.png)

	To ==generate the embeddings==, each node ==aggregates the received message==. One common choice, for example, is a ff neural network.

	![](gnn3.png)

</details>


2. <details markdown=1><summary markdown="span"> What happens as we increase the layers of a GNN? </summary>
    
    \
    After ==k-layers==, each node receives ==information about nodes at k-hops from itself!==.

</details>


3. <details markdown=1><summary markdown="span">What is the most basic approach to aggregating features? </summary>
    
    \
    The most basic approach consists of ==averaging neighbours' messages, and then applying the nn==.

	![](gnn4.png)

</details>


4. <details markdown=1><summary markdown="span"> What is the compact matrix form the basic approach? Why do we use it? </summary>
    
    \
    We use this matrix in order to ==perform aggregations efficiently==. Note that ==this representation does not work with all the aggregations functions!==.

	![](gnn5.png)

	We end up with:

	![](gnn6.png)
	
</details>


5. <details markdown=1><summary markdown="span"> What are two possible ways to train GNNs?</summary>
    
    \
    Two settings:
    - supervised, ==with labels==
    - ==unsupervised, with no labels and the graph structure as supervision==.
    

</details>


6. <details markdown=1><summary markdown="span"> What is the idea behind attention applied to graphs? What is the object of the attention of each node? </summary>
    
    \
    The idea is that we specify ==arbitrary importance for the messages of different neighbouring nodes==, following ==an attention strategy==.

</details>


7. <details markdown=1><summary markdown="span"> Describe the 2 steps of applying attention to graphs.  </summary>
    
    \
    ==Computation of $e_{uv}$, aka the attention coefficients==:
    ![](gnn7.png)
    ==Computation of ^$\alpha_{ab}$, aka the normalised attention weights to use in the final weighted sum==:
    ![](gnn8.png)
    

</details>


8. <details markdown=1><summary markdown="span"> What is a simple way of applying attention to nodes? Is it possible to extend it to multi-head attention? </summary>
    
    \
    The ==original approach proposed for nodes was applying a linear layer to the concatenation of the 2 messages from each node==.

	![](gnn9.png)

	For multihead, the same process is repeated multiple times with different coefficients and then the outputs are aggregated.

</details>


9. <details markdown=1><summary markdown="span"> What is the standard way of constructing GNNs and stacking their layers?  </summary>
    
    \
    The easiest way is to ==stack multiple GNNs layers==:

	![](gnn10.png)

</details>


10. <details markdown=1><summary markdown="span"> What is the over-smoothing  problem?</summary>
    
    \
    Over-smoothing in GNNs means that ==all the nodes' embeddings converge to the same value!==. This is bad because we want to use embeddings to differentiate nodes.

</details>


11. <details markdown=1><summary markdown="span">  How do we determine the receptive field of a GNN? How can it help in explaining over-smoothing? </summary>
    
    \
    In GNNs with $k$ layers, a ==node has a receptive field of $k$-hops==. 
    
	![](gnn11.png)

    In deeper GNNs networks, this means ==that nodes will end up having similar receptive fields and, in the end, similar embeddings==.

</details>


12. <details markdown=1><summary markdown="span"> What is a good way of choosing the right number of layers then? </summary>
    
    \
    One good "rule of thumb" is: ==analyse the needed receptive field (e.g. diameter of the graph), then set number of layers to that number + a small increment (e.g. 2/3==).

</details>


13. <details markdown=1><summary markdown="span"> What are 2 techniques we can use to increase the expressive power of shallow GNNs?</summary>
    
    \
    First strategy: ==make aggregation technique a deep NN== instead. This way, the receptive field stays the same but the network can be more "expressive".
    
	![](gnn12.png)

	Second strategy: ==add layers that do not pass messages==, i.e. ==pre/post processing layers==.

</details>


14. <details markdown=1><summary markdown="span"> What is the idea behind using skip connections to solve over-smoothing? What is a possible explanation on why it works?</summary>
    
    \
     We can use the ==embeddings in earlier layers that sometimes differentiate the nodes better and add them to other layers (by adding shortcuts)==.

	This works really well as we can explore ==a mixture of models==:
	![](gnn13.png)

</details>