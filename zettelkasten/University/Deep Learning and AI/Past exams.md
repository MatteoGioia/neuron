### 18 Feb 2022

#### Question 1

I would try to "break down" the loss into smaller terms. Being a function $f \ : \ n \to m$ with $m >> n$. The slow training time for the loss is probably caused by the slow backpropagation through the computational graph, which now has to be done for each of the $m$ final components. Now, there is the possibility that each component of the vector contributes to more than one element of the loss. Depending on if this is the case (i.e. the components are independent or not), I would either try to parallelize the loss computation, otherwise I would use a technique similar to alternating least squares (i.e. optimize one piece of the loss at the time). \


Better solution: use forward mode!

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

Identity + batch norm?

#### Question 7 (R)

Let's first think of which operations might be causing the result to be 0. The mean cannot return a 0 except if the denominator is 0, so this means that the outputs are already 0 before mean pooling. For what regards dropout, the chance that we observed a sequence of events for which always the same weights dropped out and thus lead to 0s in the input of the pooling are quite low. A batchnorm will return 0 only if we subtract to each output its exact same value, so it's also quite unlikely. \
This only leaves the RELUs as potential culprits, and the reason we see 0s is because RELUs will compute $max(0,input)$ as their activation function.  This means that the inputs progressively become negative the more we go into the network. We could maybe counter this by adding residual layers, e.g. (assuming the original input is positive) by summing the input of the layer to its output (the output of the convolution) before computing the RELU. 

Other answer: dropout
 
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



### 10 Jun 2021

#### Question 1

$21*20 + 20*2 + 21*20 + 21*20 = 1300$

#### Question 2 (R)

This refers to the invited lecture in 2021.

#### Question 3

First of all, let's try to understand what each transformation does. Furthermore, I'll assume we are talking about linear convolution.
Transformation $a$ applies what seems to be a blur, and can be achieved by applying to a $n*n$ patch a filter in which all elements are $\frac{1}{n}$, we could say each element contributes "evenly" to the final result.  This would probably work in both cases, for instance a $2*2$ patch in which elements are half 0s and half 1s would return 0.5 (mapped to gray), while a patch in which values are half 1s and half -1s would still return 0, which corresponds to gray. \
(==This section was completed with the help of wikipedia==) Transformation $b$ is a 90 degree rotation, which is expressed by a rotation matrix (https://en.wikipedia.org/wiki/Rotation_matrix). In this case, there might be an issue when 
values are negative. \
Transformation $c$ makes only a portion of the matrix black, which corresponds to having the pixel assume min/max value (so either 0 or 1, -1 o 1) depending on the convention used. The only chance at applying a similar transformation when using a filter as big as the picture (since we cannot selectively apply convolution just on one "side").  In case the values are $[0,1]$ we could use a matrix with one or more columns 0ed (assuming 0 is black). In case the values are $[-1,1]$, we would still do the same but fill the column(s) with the negative inverse of the value in each pixel. \
Finally transformation $d$ seems to be an inversion of color. This is not possible in the case of $[-1,1]$ since we need to modify the value with the opposite of its sign (but we don't know what sign we have in input, unless we talk about filters ad hoc for an image). It is also not possible to obtain in the case of $[0,1]$, because again we would need some matrix that does something like $49 \to 51$ (think of integers as decimals).

#### Question 4 (R)

I would assume that the one trained without regularization is more vulnerable.  A $L_2$ does in fact promote smaller weights, this in turn would make the effect of the  perturbation (once it is multiplied by the weights) smaller. In the case of the not regularized model, instead, if the perturbation would have a bigger impact if some weights have a big value. Furthermore, in the case of a untargeted attack, the gradient of the loss w.r.t. to the image we input at each iteration would be smaller, thus possibly making the process to obtain the final version (that successfully attacks) harder. 

#### Question 5 (R)

This initially seemed to me like the issue presented when discussing about VAEs, specifically the one that we fix using the reparametrization trick. Such issue comes from the fact that when we backpropagate we cannot proceed any further when we encounter the node that generates a random normal distribution.
However, in this case, our probability distribution is uniform, so given we have something slightly different.
==Note: weirdly enough pytorch works without reparametrization!==

#### Question 6 

This question was addressed in 2022 exams.

#### Question 7

First of all, we should discuss of the data we have. In fact, classification accuracy in imbalanced datasets is not a good indicator (in fact it would be more interesting to see recall and precision). So a balanced dataset would be a good indicator of trustworthiness, the contrary would be a bad indicator. \
Secondly, the presence of the ruler might be an issue. In fact, depending on if the ruler appears in enough pictures with malignant nevi (or benign ones) the network could potentially associate the elements of the ruler to a positive/negative prediction. This answer also depends on if the dataset is balanced or not, i.e. if 30% of the samples are malign nevi and the ruler always appear the classifier would not be trustworthy, while the ruler appearing in roughly half of them, if the dataset is balanced, might not be an issue. \
I would also probably try to plot an attention map, to see whether or not the model is actually focusing on the ruler or not, since a big enough dataset might teach the network to be invariant to objects like the ruler.



### 08 July 2021

#### QUESTION 1

General formula: $K^2*in_ch*out_ch + out_ch$. See notebook to understand why!

#### QUESTION 2

The manifold hypothesis is the idea that high dimensional data in euclidean dimensions actually lies on a lower dimensional non euclidean manifold. Furthermore, that each item (we call them embeddings) is the product of an invertible map from a latent space, which is euclidean, to the manifold itself, which is not (the charts that constitute the manifold are a diffeomorphism as to ensure this property). \
An autoencoder is related to the manifold theory since we could say that the encoder learns the inverse map that goes from the manifold to the latent space, while the decoder learns the map that goes from latent space to the manifold.

#### QUESTION 3

To answer this questions, let's first briefly analyze what using a triangular mask implies. In short, it allows to ensure causality between layers, since we might not want to leverage future information in the data to predict the next output. \
Because of this, we could probably say that using it in weather forecasting is a good idea since we can only analyze weather with past and current data. I think it would also be fitting in 3d shapes classification, assuming we are trying to apply it to a task in which the previous and current shapes are relevant to the output, and we want to predict the next one. \
It would not be a good fit in the case of translation of ancient books or video calls: in the first case, we can leverage the next words to both understand the meaning of a sentence and leverage the grammatical structure(in latin for instance the sentences have the verb at the end),  in the second case,  we could afford a few seconds of delay to get more context from the sentence and achieve a better translation. A point could be made that if the translation had to be live with no delay and could no be corrected: in that case, a triangular map would be appropriate (although with worse performance, potentially). Using a triangular map would also not be good in the case of sentiment analysis, as we can always use more of the output to contextualize  the meaning of a word.

#### QUESTION 4

A way to achieve this could be using a technique that we saw for VAE. My idea would be to introduce a source of noise into the network. For instance, the bias could be implement as a deterministic function which takes as input a random variable from a normal distribution. This would ensure the output is different at each time while also ensuring the backpropagation mechanism is not broken. 

#### QUESTION 5 (R)

Assuming we have a 2-way function from song to spectrogram and from spectrogram to song, one possible way to achieve this would be by using a VAE. Given an input song, a modified version could be generated ensuring the loss takes into account how "far" the song is from the target genre. In other words, another element could be added into the formula to ensure that, whenever the predicted class is different from the target one we apply a penalization, e.g. $\lambda(\mathcal{C}(D(E(\mathcal{X})) \neq t)$ (where $\lambda$ is a constant to apply a penalization and $t$ is the target class). We could also add some "slack" into the reconstruction loss, to ensure that it is not too strict. In other words, it would almost be like if we were doing an adversarial attack but ensuring the final product still "makes" sense.\ 
I also wonder whether a similar approach  to CycleGAN could be used. \
For what regards parameters, it would depend on what we use as a network and what is the shape of the input. If for instance we could input the entirety of a spectrogram it would be $48000*5000$, if instead we could only input a piece it would be less (not so sure about this part.)

#### QUESTION 6 (R)

I would phrase the reconstruction loss in two pieces. The first would ensure we have the same number of nodes and edges, so something like $|\sum_{v \in G} - \sum_{v \in G'}|$ and a similar thing for counting edges . In the second piece, I would ensure the same connections are kept, because I'd want the graph to be as identical as possible to the original one, so something like $\sum_{v \in G} \sum_{u \in G} \delta \{(v,u)_{G}, (v,u)_{D(E(G))} \}$. Before I go forward, I would like to address the true elephant in the room and main weakness of this solution: it would clearly require to use some ordering of the nodes, otherwise it would not be possible to differentiate one graph from another. In fact, I believe the first constraint would work well in both cases, but the second one would be much harder to enforce...

#### QUESTION 7

Considering the above image, we see multiple "layers" necessary to really understand the image. First of all, we need to understand the object in the image, a.k.a. what is called semantic segmentation. This is possible with modern AI techniques, like CNNs or transformers. Secondly, we need to understand which elements are relevant to the context of the image (e.g. the reflection gives us no useful information), and how each object of the image interacts with each other. So, assuming our image segmentation model has some invariance w.r.t. to the background, it would still need to "understand the context". A human mind would in fact make the connection that "the foot on the scale" and "human weighing himself" are connected, and since we know that the first influences the second by altering it, give us a sense of comedy. This is again the result of multiple priors, for instance some about how physics works. I'd dare to say that a model complex enough would actually be able to correctly segment the image, "e.g. man pressing his foot on the scale while the other man weighs himself", but would need to be really complex to understand the implications of this (the weight is altered) and even more complex to understand why the image is funny (so do something like sentiment analysis for images ?). \
Interestingly enough, lately Google released a demo of an AI model able to understand puns and even explain them. Furthermore, we could argue that, in general, the perception that humans have of the world might be achieved when a model becomes complex enough (i.e. being human like arises from complexity).
### 14 September 2021 (TF)

#### question 1

If we consider bias for each of the $W_k, W_q, W_v$ matrices and do not consider a layer to aggregate the heads at the end, we have $11*10*3*7=2310$ params.

#### question 2

Assuming we are working with an optimizer like adam (so we don't take huge steps even if our predictions is way off) and the last layer is linear, I think it would mostly depend from the dimension of the weights.  Having the weights set a 0 would probably cause a really slow convergence, since at each time the prediction is skewed towards the value of the sample we are optimizing  but only slightly, since the gradients would be small. In the opposite case (values much bigger than 1), if the value were to be much bigger, we would converge even more slowly since the descent pattern behaves like a giant zigzag. Setting them to something in the middle, like 1, would cause slow convergence again but not as bad as the first 2 cases. Respectively, the first one would overfit on training and underfit on test,  the second would underfit on both and the last one would perform ok on the training and maybe slightly underfit on the test set (still better than the other 2).

#### question 3

Let's look at this from a different angle. If we have some of the weights at 0 after an iteration, it means that the descent converged to a point in which such weights have no longer to be updated, e.g. the gradient w.r.t. to the weights is 0.  Furthermore, it would mean that the network is considering only part of the weights to output its prediction because they are the relevant ones. Such a case could be caused by a mix of L2 and learning rate: a high learning rate would overshoot to a point in which, if the actual hypothesis is really simple, the other weights, already made small by L2 would quickly become 0, so we are stuck in a local minimum. Furthermore, big batches could lead to few iterations and getting stuck in a local minimum.

#### question 4

It would mostly depend on the last layer. Bigger and smaller images would both work in the context of convolution, provided the dimension of the kernel, padding and stride are compatible. The issues could be with padding, if they are not adaptive, and the last layer. If it something like a softmax is used to achieve the $k$-length vector, a bigger image would not be a problem...

#### question 5





### 19 October 2021

#### question 1

$11*20 + 20*2+21*10+11*20$

#### question 2

 We could use the more general formula shown in slide nr. 12, where the perturbation is expressed as a $\delta \in [0,1]^n$ to which we apply a Frobenius Norm. If we set the norm to be a L-1 norm, we could maybe achieve a similar result to what happens when we use a L-1 norm in optimization (i.e. sparsity of the weights), if we consider each pixel of the perturbation to be a weight itself. Furthermore, if we multiply it for a constant we could achieve a maybe even sparser result (?).
 
 #### question 3
 
Again, let's reason on what the weight sparsity means before proceeding. If we have weights equal to 0 it means that they were either 0 at the end of the training, since they progressively got smaller, or they became 0 at some point during training and stayed that way because we reached a stationary point. One possibility would be that the function has some local minima at the extremes of the parameters' space, so with a really high learning rate we quickly reach one of the "corners" in which only a certain sets of weights is not 0. Furthermore, depending on how "deep" this point is in the energy landscape it could mean that, even with a really high learning rate, we are not able to get out of this pit.

#### question 4 

Convolution is not translation invariant but is translation equivariant.

#### question 5

Something something eigevenctors of a laplacian --> locality?

#### question 6



