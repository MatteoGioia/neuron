# Regularization

### Recall questions

Also see:
- possible ways of normalizing

1. <details markdown=1><summary markdown="span"> What is the general idea behind regularization ?</summary>

    \
    We want to reduce the number of free parameters, in the sense of degree of freedom. \
    This is also mentioned in #[[BD VIII - Linear Regression]]

</details>

2. <details markdown=1><summary markdown="span"> What is the tradeoff induced by a regularizer? </summary>

    \
    A regularizer induces a tradeoff between data fidelity and model complexity.

</details>

3. <details markdown=1><summary markdown="span"> What are typical regularizers? What do they promote?</summary>

    \
    Typical penalties are:
    - tikhonov aka $L_2$, promotes shrinkage
    - lasso aka $L_1$, promotes sparsity (and shrinkage)
    - bounded $L_2$ norm at each layer (e.g. we have per layer normalization)

</details>

4. <details markdown=1><summary markdown="span"> Can you explain the meaning of the following graphs?</summary>

    \
    ![](../../../static/DEEP/reg1.png)

</details>

5. <details markdown=1><summary markdown="span"> What is an easy weight to counter overfitting in neural networks?</summary>

    \
    We can use early stopping: the training halts as soon as performance on validation set decreases.

</details>

6. <details markdown=1><summary markdown="span"> What is the implication of the following graphs?</summary>

    \
    ![](../../../static/DEEP/reg2.png)

</details>

7. <details markdown=1><summary markdown="span"> What is another way of looking at overfitting?</summary>

    \
    We can also look at overfitting as a localized phenomenon, in the sense that our function may be overfitting but only on certain regions.

</details>

8. <details markdown=1><summary markdown="span"> What is the double descent phenomenon?</summary>

    \
    ![](../../../static/DEEP/reg3.png)

</details>

9. <details markdown=1><summary markdown="span"> What is the smoothness heuristic (in the context of early stopping)?</summary>

    \
    The idea that representational power grows with training time. In other words, the model starts exploring simple models that progressively increase in complexity.

</details>

10. <details markdown=1><summary markdown="span"> Does increasing training time also cause double descent?</summary>

    \
    Yes, we can see the same phenomenon when we increase training time.
    ![](../../../static/DEEP/reg4.png)

</details>

11. <details markdown=1><summary markdown="span"> What is the idea behind batch normalisation? What tweak is necessary and why?</summary>

    \
    The idea behind batch normalisation is to correct the data distribution by centering and scaling at each layer. \
    It is also necessary to add weights in order for the network to be able to learn the identity function (when necessary).\
    ![](../../../static/DEEP/reg5.png)
    ATTENTION: recent talk may prove that the idea is wrong, source to check.

</details>

12. <details markdown=1><summary markdown="span"> What action is necessary at test time when applying batch norm?</summary>

    \
    Since mini batches are not used at test time, the mean and std. deviation used by the network are an average of the means and std. dev. seen during training.

</details>

13. <details markdown=1><summary markdown="span"> What advantages does batch norm offer?</summary>

    \
    Benefits:
    - the stochastic uncertainty of the batch acts as a regularizer that helps generalization
    - batchnorm leads to more stable gradients and faster training with higher learning rate

</details>

14. <details markdown=1><summary markdown="span"> Explain how dropout is used to simulate ensemble training in nn.</summary>

    \
    Dropout emulates the way ensemble work by leveraging probability. Each node of the network at training time is linked to a probability $p$ of dropping out for the following iteration (mini batch) and not contributing to the final result. Furthermore, this "temporary" network is not trained to convergence (e.g. early stop) but on a mini batch (bagging).\
    This allows to train "multiple networks" while also keeping the weights shared. The final network is trained on the whole dataset to convergence. \
    At test time the probability is no longer used, but the weight of each connection is now multiplied by the original $p$ of the originating node.

</details>

15. <details markdown=1><summary markdown="span"> What are the properties of dropout as a regularizer? Are they all "good"?</summary>

    \
    Properties:
    - reduces co-adaptation (small errors in a unit being absorbed by the others) and improves generalization
    - outputs a sparse representation (side effect)
    - performs closely to the ensemble and much better if the nn in the ensemble had no weight sharing
    
    The main downside is the increase in training time because of the greater instability, which slows convergence.

</details>