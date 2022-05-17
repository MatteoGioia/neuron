# Generative Adversarial Networks

### Recall questions

1. <details markdown=1><summary markdown="span"> What is the basic idea behind GANs?</summary>

    \
	The basic idea is that we train ==2 models==: 
	- a ==generator== (e.g. decoding portion of a VAE)
	- a ==discriminator==

	We then train the ==discriminator== to distinguish between ==real life data and the generated one==. The ==generator==, instead, ==is trained to make data a realist as possible== in order to "fool" the discriminator.
	![](../../../static/DEEP/adv1.png)

</details>

2. <details markdown=1><summary markdown="span"> Can you describe the idea of GANs as a minmax problem?</summary>

    \
	![](../../../static/DEEP/adv2.png)

</details>

3. <details markdown=1><summary markdown="span"> Explain the steps to follow in order to find the best generator and discriminator. What is the result of this process?</summary>

    \
	The notes for this part are from slide xx to xx.

</details>

4. <details markdown=1><summary markdown="span"> What are adversarial attacks? Why are they useful?</summary>

    \
	The idea behind adversarial attacks is to ==perturb the data in order to trick the model==. Note that ==we can optimize the perturbation== in order to reach this goal.
	![](../../../static/DEEP/adv3.png)

</details>

5. <details markdown=1><summary markdown="span"> What types of adversarial attacks are possible?</summary>

    \
	3 types of attack:
	- ==black box==: can only query the target model
	- ==gray box==: access to partial information (only the features, architecture, etc.)
	- ==white box==: complete access to the network (architecture, parameters, etc.)

</details>

6. <details markdown=1><summary markdown="span"> What is the idea behind targeted attacks? </summary>

    \
	The idea behind target attacks is ==tricking the model into classifying data as if it were an instance of the target class==.
	![](../../../static/DEEP/adv4.png)

</details>

7. <details markdown=1><summary markdown="span"> How can we formulate targeted attacks w.r.t. to a perturbation?</summary>

    \
	![](../../../static/DEEP/adv5.png)

</details>

8. <details markdown=1><summary markdown="span"> What is the idea behind untargeted attacks ? What is the reason behind then formula? Hint: [[FDS IV - Classification]]</summary>

    \
	In the case of untargeted attacks, we have no requirements on the class that must be returned.
	![](../../../static/DEEP/adv6.png)

</details>

9. <details markdown=1><summary markdown="span"> Can we also conduct adv. attacks on other types of data, e.g. euclidean?</summary>

    \
	Yes, and we can even look for ==universal filters== that apply to multiple instances of data in the same domain.

</details>