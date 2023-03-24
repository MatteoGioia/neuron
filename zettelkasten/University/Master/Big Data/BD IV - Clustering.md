# Clustering 

Also see [[ML XII - Clustering]] and [[DLAI I - Data]]

### Recall questions

1. <details markdown=1><summary markdown="span"> What is clustering? Why is this a "troubling" definition?</summary>

    \
    ==Unsupervised learning technique to group a set of objects into classes of similar ones==. It is also a good method for ==data exploration==, i.e. looking for patterns. 

</details>

2. <details markdown=1><summary markdown="span"> What is the formal definition of clustering? Hint: notion of distance </summary>

    \
    Given a set of ==data points and a notion of distance== between those, ==group the data points into some number of clusters== s.t.:
    - members of a cluster are similar/close a.k.a. ==high intra cluster similarity==;
    - members of different clusters are different/distant a.ka. ==low inter cluster similarity==

</details>

3. <details markdown=1><summary markdown="span"> What are 3 main issues of clustering? </summary>

    \
    Issues:
    1. ==object representation==
    2. ==notion of similarity==
    3. ==number of output clusters==

</details>

4. <details markdown=1><summary markdown="span"> What is the main issue of clustering in high dimensional spaces? </summary>

    \
    All the ==sets of points are going to be far from each other==. (Remember the DLAI vector example?)

</details>

5. <details markdown=1><summary markdown="span"> What is distance concentration? </summary>

    \
    It is the phenomenon for which the ==distance between data points, in high dimensional spaces, becomes indistinguishable==. Both =="similar" and "dissimilar" points are going to be really distant==.
    
</details>

6. <details markdown=1><summary markdown="span"> What is the probability for a point to be in the edges of the space as the nr. of dimensions grows?? </summary>

    \
    $lim_{d \to \infty} (1-2\varepsilon)^d = 0$
   

</details>

7. <details markdown=1><summary markdown="span"> What are possible fixes to this situation? </summary>

    \
    Nothing if data were really randomly distributed..
    But! We can ==lower intrinsic dimensionality and also look for patterns in the data==. Furthermore, the original manifold on which data points lie might be low dimensional while the embedding is high dimensional.

</details>


8. <details markdown=1><summary markdown="span"> Explain the L-p norm (minkowski), Cosine similarity and jaccard coefficient/distance. </summary>

    \
    See the slides or the pinned notes.
    Slides:
    - Minkowski : 57, 65
    - Cosine: 77, 87
    - Jaccard: 89, 91

</details>