# Training neural networks

Also see:
- [[DLAI VIII - Regularization]]

### Recall questions 


1. <details markdown=1><summary markdown="span"> What are the 3 main "problems" of the sigmoid as activation function? Does the ReLU fix all of them? </summary>
    
    \
    3 main problems:
    - ==saturated neurons kill the gradient==
    - ==not zero centred==
    - ==exp() is a computationally expensive== operation

	Furthermore, the fact that ==the gradients w.r.t. to the weights all either all positives or all negatives induces a zig-zag path== that might not be optimal for grad descent.

	![](tnn1.png)

	Luckily the ==relu fixes most of those issues (pt.1 and 3)==, although it still suffers from:
	- ==killing the grad in the <0 region==
	- ==not being 0 centred==

</details>


2. <details markdown=1><summary markdown="span"> List some common variants of the ReLU. What is the difference with the standard relu? </summary>
    
    \
	Some common variants:
	- ==leaky relu==: ==does not kill grad when <0== ![](tnn2.png)
	- ==parametric rectifier==: ==tunable leaky relu==  ![](tnn3.png)
	- ==exponential linear units==: has some ==robustness in the <0 region== but is more computationally expensive ![](tnn4.png)
	- ==scaled exponential linear units==: is ==self normalising==, no need for batchnorm ![](tnn5.png)

</details>


3. <details markdown=1><summary markdown="span"> What is a common step of preprocessing? Why? </summary>
    
    \
    ==Normalising is a standard step in most pipelines==. It is useful because it ensures that there are no outliers in the data that could compromise learning.

	More about this in [[../Deep Learning and AI/DLAI VIII - Regularization]]

</details>


4. <details markdown=1><summary markdown="span">What are we looking for when choosing a weight initialisation technique and why? What is the best way to initialise weight then? What fix is necessary to make it work with relu? </summary>
    
    \
    We are mainly looking for an ==even activation of the neurons in each layer==. This ==ensures that we have actual learning, contrary to what would happen if we, say, initialised weights with random small values==. In the following image, we can see what happens to the gradients of the weights:

	![](tnn6.png)

	A good way to set weights is ==Xavier initialisation==: in fact, this initialisation ==ensures that activations are spread evenly.== This works well since it actually ==preserve the original variance among layers==.

	![](tnn7.png)

	In order to make it work with relu, the dividing factor must be $\frac{2}{D_{in}}$ instead of $\frac{1}{D_{in}}$
	

</details>


5. <details markdown=1><summary markdown="span"> Describe some "less known" regularisation techniques. </summary>
    
    \
    Some less known reg. techniques:
    - ==dropconnect==: ==like dropout but with edges connecting to a node== ![](tnn8.png)
    - ==fractional max pooling==: use ==randomized pooling region at training time== and ==average predictions at test time==
    - ==stochastic depth==
    - ==cutout==: set some regions of the image to zero ![](tnn9.png)
    - ==mixup==: use ==blends of images== ![](tnn10.png)

</details>


---

### Recall questions on transfer learning

6. <details markdown=1><summary markdown="span"> How can we decide whether it's appropriate to apply TL and which layers to tune?  </summary>
    
    \
    We can take a decision based on ==the amount of data== and ==on how different this data is== from the one that was used to train the original network.

	![](tnn11.png)

</details>