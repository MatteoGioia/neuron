# Data, features and more

### Recall questions


1. <details markdown=1><summary markdown="span"> What is prior knowledge? </summary>
    
    \
    Prior knowledge describes what we already know about the data (e.g. probability distribution). We are interested in ==studying prior-based data==.

</details>


2. <details markdown=1><summary markdown="span">What do we assume when examining our data? </summary>
    
    \
    We assume our ==data has an underlying structure==. Our goal then is discovering a ==map from input to output==.

</details>

3. <details markdown=1><summary markdown="span"> What is the curse of dimensionality? How can we fix it? Use the 1mpx image example to justify the answer.</summary>

    \
    ==nr. features >> nr. observations== \
    We need an ==exponential number of observations w.r.t. to the dimensions we have to discover a pattern==. 
    For example, ==$n^1$ for one dimension, $n^d$ for $d$ dimensions==.\
    Think of the space of 1mpx images: it is very sparse, and we would need millions of images to find a pattern between them! \
    There are 2 main ways of addressing this issue:
    1. increasing the nr. of observations
    2. reducing the possible dimensions

</details>

4. <details markdown=1><summary markdown="span"> <b>EX </b> Assuming we have 2 pts in a space, how likely it is that they are going to be similar? Give a mathematical explanation.</summary>

    \
    Assuming the distr. is uniform, the ==2 points are going to be orthogonal==, especially if the space we are examining is very sparse.

</details>


5. <details markdown=1><summary markdown="span">Why can we say instances are the result of a synthesis process?</summary>
    
    \
    We assume that ==each data point $x \in D \subset \mathbb{R}^n$ is a result of a synthesis process which takes a set of features $F$ and composes them to form $x$==.\
    $\sigma : F \to x$\
    Note that ==sigma acts non linearly most of the time==.

</details>

6. <details markdown=1>
    <summary markdown="span"> What is the "proper" name of the output of the function sigma? Is it unique?</summary>

    \
    The result of sigma is called an ==embedding of a data point. Many embeddings are possible for one data point==.

</details>


7. <details markdown=1>
    <summary markdown="span"> What are invariances (give an informal definition for now)? You can use the paper sheet example. </summary>

    \
    Invariances are t==he features of the data points that do not change even if the embedding is changed==. \
    Think of a paper sheet: the distance among the points on the surface is always the same, both if we make a paper plane or a simple ball.

</details>

8. <details markdown=1><summary markdown="span"> What are latent features?</summary>
 
    \
    Latent ==features are not necessarily localized in space==, and ==not necessarily evident in the embedding space==.

</details>

9. <details markdown=1><summary markdown="span"> What is the manifold hypotesis? </summary>
   
    \
    In deep learning, it is assumed that ==the input data lives on some underlying non-Euclidean structure==, called a ==manifold==.

</details>

10. <details markdown=1><summary markdown="span"> Why do we say that feature choice is task driven? </summary>
    
    \
    ==Specific problem require different features.==

</details>

11. <details markdown=1><summary markdown="span"> Give (one of) the definition(s) of deep learning.  </summary>

    \
    ==Task driven pardigm to extract patterns and latent features from given observations==.

</details>