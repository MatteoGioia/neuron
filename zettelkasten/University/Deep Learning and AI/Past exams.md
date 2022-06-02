### 18 Feb 2022

#### Question 1

I would try to "break down" the loss into smaller terms. Being a function $f \ : \ n \to m$ with $m >> n$. The slow training time for the loss is probably caused by the slow backpropagation through the computational graph, which now has to be done for each of the $m$ final components. Now, there is the possibility that each component of the vector contributes to more than one element of the loss. Depending on if this is the case (i.e. the components are independent or not), I would either try to parallelize the loss computation, otherwise I would use a technique similar to alternating least squares (i.e. optimize one piece of the loss at the time). \

#### Question 2

The explanation for the first part of this is in [[DLAI XI - Adversarial]] . It mostly depends on whether the attack is targeted or not. \
To enforce a distortion concentrated over very few pixels, adding a constraint that forces the distorted image to be identical to the original, except for a few pixel, may not work, as the distortion might still be very dispersed. Assuming that the distortion has the size of the original image, what we could do is apply a penalization that is proportional to the area that is distorted.  \
Computing both the $arg \ max \ (0,\delta)$ and $arg \ min \ (0, \delta)$, we could get the position of the top leftmost and bottom rightmost pixels that are distorted. We could then compute the distance between the 2 and approximate the perturbation area with a square (since we know the diagonal) or a circle,  and apply a penalization proportional to that.

#### Question 3

To answer, we should first think about the content of the one-hot representation, i.e. what the content of each input means. Let's also assume that we are working with some ordering of the nodes, which does not influence the final result (i.e. any random numerical ordering is fine). Also we add an edge from each node to itself to preserve its information. The encoding should work as follows: each vector has a 1 in place of its position if there is a edge incoming into the target node. I would then stack the vectors like a matrix (see illustration), since the sum of each vector is one (so summing the elements of the vector itself does not make much sense) and consider the maximum value for each column. This would allow me to keep information about which vector I'm considering, and I could see the final result as an integer (potentially) in base 2.

![](../../../static/DEEP/ex1.jpg)

#### Question 4

We can use multiple approaches. First of all, we could consider augmenting the data of the minority class, in order to produce more samples for our network.  I am thinking of transformations like random cropping, changing the color and similar etc.This, in conjunction with something like a contrastive learning regime, leveraging a VAE for example, could help in extrapolating the relevant features of each representation, as we now have many samples for our supervised model and potentially also the latent representation.  In this context, it might be interesting to also generate new samples with something like a GAN. \
Another approach could be instead something like cost sensitive learning, i.e. we penalize the network more when the prediction on the minority class is wrong. \
To detect bronterocs, maybe something like a discriminator could be used. In particular, we could train multiple GANs in order to recreate a number of animal species and maybe also humans. After that, we could use the discriminators in order to recognize whether a sample fits in any of the classes and, if no match is found, we could maybe say that we are looking at a bronterocs.

#### Question 5

41 x 20 + 20 x 2 (batch norm) + 21 x 10 + 11 x 3 = 1103

#### Question 6



#### Question 7 (R)

Let's first think of which operations might be causing the result to be 0. The mean cannot return a 0 except if the denominator is 0, so this means that the outputs are already 0 before mean pooling. For what regards dropout, the chance that we observed a sequence of events for which always the same weights dropped out and thus lead to 0s in the input of the pooling are quite low. A batchnorm will return 0 only if we subtract to each output its exact same value, so it's also quite unlikely. \
This only leaves the RELUs as potential culprits, and the reason we see 0s is because RELUs will compute $max(0,input)$ as their activation function.  This means that the inputs progressively become negative the more we go into the network. We could maybe counter this by adding residual layers, e.g. (assuming the original input is positive) by summing the input of the layer to its output (the output of the convolution) before computing the RELU. 


### 22 Jan 2022

#### Question 1

$11*20 + 20*2 + 21*10 + 11*30 = 800$

#### Question 2

For the first part, refer to [[DLAI XI - Adversarial]]. For what regards the second, we should first think of what perturbations means in the context of classification problems on graph. In fact, if we are referring to the classification of the entirety of the graph, a perturbation like the one we use would not work, at least without modification. In fact, we cannot simply "sum" the gradient over the original graph, as the domain is different from the ones of images, which is euclidean. To apply a similar perturbation technique, we would probably need to apply the Laplacian as we did in the case of convolution applied to graph, in order to derive a representation to which we can add the gradient of the loss. I think this would correspond to adding edges to the graph itself. 

#### Question 3 (R)

If we also desire smoothness when transitioning between one skin color and another, we need to add another constraint in the loss. Ideally, the VAE as it is right now is enforcing a Gaussian distribution over the priors which constitute the entirety of the pixels of the image. It may be instead possible to enforce priors on two different elements: one over the edges of a face, which constitute the structure, and one over the colors of the image, specifically the face, to enforce smoothness also on skin color.

#### Question 4

The manifold hypothesis is the idea that data as we see it is an embedding of a lower dimensional representation from what is called a latent space inside a non euclidean manifold, which is a subset of a bigger euclidean space, e.g. $S \subset R^3$. This means that embeddings can be expressed by representations with lower dimensionality than the one originally considered, however the way the embeddings are computed from the latent representation is often the combination of many non linear transformations (called maps). We in fact require this manifolds to be diffeomorphism, in order to be able to compute the inverse of the function that goes from a latent space to the manifold itself. \
This of course also applies to AE, which in the context of this hypothesis learn both the function that goes from the manifold to the latent space (encoder) and the one that goes from the latent space to the manifold (decoder).

#### Question 5 (R)

The first difficulty I can think about is from an architectural standpoint, and can be probably fixed by supplying the model with individual frames instead of images. \
This, however, would still not "consider" the fact that we are working with videos instead of images. In fact, when dealing with videos the model should also be able to consider causality between frames. In other words, I would probably use something like a sequential model with causal layers in order to "retain" knowledge from previous frames of the video. \
There would also be the problem of labeling objects and defining ground truths, i.e. we would have thousands of them for a very short video.

#### Question 6

Refer to [[DLAI VII - Cnn]].

#### Question 7 (R)

Let's first examine the input of the self-attention layer. Since we are taking a vector from a unit sphere, we know that the sum of its elements will be equal to 1. Furthermore, since $n << d$, we also know that there is a good chance that $\sum n < 1$, since we are considering only a small portion of its elements.
The issue probably comes from the way weigths are computed, i.e. since they are the product of vectors with really small values and we have no parameters to learn, the resulting weight is so small that it does not change the final output except some cases in which is slightly modified (e.g. because the 2 vectors are for instance colinear and sum up to a big enough quantity.)

This might be relevant? https://aclanthology.org/P19-1147.pdf