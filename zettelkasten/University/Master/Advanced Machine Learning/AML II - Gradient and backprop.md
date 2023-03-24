# Gradient and backprop

Also see [[DLAI VI - Multi Layer Perceptron]]

### Recall questions on computational graphs

1. <details markdown=1><summary markdown="span">Explain the concept of backpropagation. Use the following image as help.</summary>

    \
    ![](grd1.png)
	

</details>

2. <details markdown=1><summary markdown="span"> Express the computational graph in terms of gates. List the most common ones. What does each of them do?</summary>

    \
    Most common:
	![](grd2.png)

	Effective implementation:
	![](grd3.png)

</details>

3. <details markdown=1><summary markdown="span"> Why is backpropagation with vectors and matrices computationally expensive? What can be done about it? </summary>

    \
    Because we would have to compute =="huge" Jacobian matrices== that take up  a lot of memory. 

	![](grd5.png)
    
    By reflecting on which elements influence the final result we can optimise computation by multiplying only the elements that actually affect the gradient.

	![](grd4.png)
   
</details>