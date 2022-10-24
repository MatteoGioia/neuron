# Sequential

Also see:
- [[DLAI X - Transformers]]
- [[ML XI - RNN]]

### Recall questions

1. <details markdown=1><summary markdown="span"> What is the idea behind temporal CNNs? In which case do they work well? </summary>
    
    \
    The idea is to use ==CNNs to model sequences==.
    ![](../../static/AML/seq1.png)

	Temporal CNNs have been shown to ==work great with small datasets==.

</details>

2. <details markdown=1><summary markdown="span"> What are the main issues when using CNNs to deal withs sequential data?</summary>
    
    \
    Main issues:
    - ==fixed kernel size==, e.g. number of input frames used ![](../../static/AML/seq2.png)
    - can ==only choose one output from a single list of options==  ![](../../static/AML/seq3.png)

</details>


3. <details markdown=1><summary markdown="span"> What is dilation? How does it help in decreasing the depth of a temporal CNN?</summary>
    
    \
    The idea behind dilation is somewhat ==similar to the use of stride==. To make the receptive field of the network bigger, a number of output at each subsequent layer is skipped, ==assuming neighbouring outputs already contain the needed information==.
    This makes the ==depth of the network logarithmic==.
    ![](../../static/AML/seq4.png)

</details>

4. <details markdown=1><summary markdown="span"> What is the idea behind a "vanilla" RNN? </summary>
    
    \
    The "basic" RNN can be represented by the following formula:

	![](../../static/AML/seq5.png)

</details>

5. <details markdown=1><summary markdown="span"> Explain the meaning of the following computational graphs. </summary>
    
    \
    What happens to the loss here?
	![](../../static/AML/seq6.png)

	And here?
	![](../../static/AML/seq7.png)

	What are two possible choices for output we do not have yet?
	![](../../static/AML/seq8.png)

	Either 0 or next prediction in an ==autoregressive model==.

	What if we want to ==understand the context== before making a prediction?
	![](../../static/AML/seq9.png)

</details>

