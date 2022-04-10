# Clustering algorithms

We focus on partitioning based clustering. Also see #[[BD IV - Clustering]]

### Recall questions

1. <details markdown=1><summary markdown="span"> What is hard clustering (formally)? What is the main issue with finding the optimum? </summary>

    \
    **Input**: set of $N$ data points, a number $K$ s.t. $K < N$\
    **Output**: partition of the $N$ data points into $K$ clusters \
    **Goal**: find the partition that optimizes a certain criterion \
    ==Finding the optimum is NP-Hard== as there are $O(N^k)$ apprx. partition to examine (==Stirling partition number==).

</details>

2. <details markdown=1><summary markdown="span"> Describe the flat hard clustering framework. </summary>

    \
    ![](../../../BIG/cl1.png)

</details>

3. <details markdown=1><summary markdown="span"> What is the objective function for the hard clustering framework? What particular property does it have? </summary>

    \
    ![](../../../BIG/cl2.png) \
    Furthermore, since we have a discrete assigment matrix $A$, our ==function is non-convex, so it allows for multiple local minima==.

</details>

4. <details markdown=1><summary markdown="span"> What is the structure of the iterative solution? </summary>

    \
    Steps:
    1. Assignment step
    2. Update step 


    Note that ==this function does might get stuck on a local minima==.

</details>

5. <details markdown=1><summary markdown="span"> How does the assignment step work? </summary>

    \
    ![](../../../BIG/cl3.png)

</details>

6. <details markdown=1><summary markdown="span"> How does the update step work? </summary>

    \
    ![](../../../BIG/cl4.png) \
    Also see slide 30-40 for detailed steps.  

</details>

7. <details markdown=1><summary markdown="span"> What is the cluster representative in k-means? What is the goal of k-means? </summary>

    \
    ==Centroids==, i.e. ==center of mass==. The goal is ==constructing clusters s.t. the total within cluster $SDD$ or **Sum of Squared Distances** is minimized==.

</details>

8. <details markdown=1><summary markdown="span"> What is the setup of k-means? And the objective function? What is the SDD? </summary>

    \
    ![](../../../BIG/cl5.png)
    ![](../../../BIG/cl6.png)

</details>

9. <details markdown=1><summary markdown="span"> Describe the assignment and update steps in k-means (formally)? Can you describe intuitively what is going to be the output of the update?</summary>

    \
    See slides 45-57. ==As expected, the new output (that minimizes the distances w.r.t. to nodes in the cluster) is nothing more than the new centroid for all the points in the cluster==.
   
</details>

10. <details markdown=1><summary markdown="span"> Describe the steps of k-means. What are possible stopping criteria? </summary>

    \
    ![](../../../BIG/cl7.png) 
    Possible stopping criterions are:
    - ==fixed number of iterations==
    - ==cluster assignment stops changing==
    - ==centroids don't change== (by some threshold)
   
</details>

11. <details markdown=1><summary markdown="span"> Why is k-means guaranteed to converge? </summary>

    \
    Because ==both the assignment step and update step monotonically decrease (resp.) the $SSD$ and the $SSD_k$==. \
    As a matter of fact, what we examined is an instance of $EM$ or ==Expectation Maximization==.

</details>

12. <details markdown=1><summary markdown="span"> What is k-means computational complexity? Why?</summary>

    \
    The complexity is ==$O(RKNd)$== if we have $R$ steps:
    - computing distance between 2 d-dimensional points take $O(d)$
    - reassigning cluster takes $O(KN) \times O(d)$ operation
    - computing centroids $O(Nd)$ in the worst case 
   
</details>

13. <details markdown=1><summary markdown="span"> What are 2 possible ways of choosing the first centroids? What issue does this solution have and how can we mitigate it?</summary>

    \
    Two methods:
    - ==forgy== method: ==random $K$ data points==
    - ==random partition== method: randomly assigns a cluster to each observation

    This solution could lead to ==sub-optimal clusters==, so ==multiple runs with different seeds== are used.
   
</details>


14. <details markdown=1><summary markdown="span"> What is the intuition behind k-means++ ? </summary>

    \
    Idea: ==spread the centroids== to avoid sub-optimal clusters.
    ![](../../../BIG/cl8.png)

</details>

15. <details markdown=1><summary markdown="span"> How much better are the clusters computed by K-mean++ ? </summary>

    \
    ==Clusters initialised in k-means++ are at most $O(log K)$ worse== than optimal partitioning.

   
</details>

16. <details markdown=1><summary markdown="span"> What is the issue when choosing the number of clusters?  </summary>

    \
    There is a ==tradeoff between total benefit and total cost==.

</details>

17. <details markdown=1><summary markdown="span"> What are benefit and total benefit?? </summary>

    \
    The ==benefit $b_i$ of a point $x_i$ is the similarity to the centroid of its cluster==. The total benefit is the ==sum of all the benefits==.

</details>

18. <details markdown=1><summary markdown="span"> How is the total cost defined? </summary>

    \
    We assign a ==cost $p$ to each cluster, thus the total cost is $Kp$==.

</details>

19. <details markdown=1><summary markdown="span"> How is the value of a clustering defined? </summary>

    \
    We want to get the cluster for which the ==Value $V = B - P$== is maximised. \
    Note that ==$B$ could increase with larger values of $K$, but the presence of $P$ does not allow it==.
    
</details>

20. <details markdown=1><summary markdown="span"> What is the elbow method? </summary>

    \
    ==Empirical method== to figure out the right number of $K$, ==looking at the $SSD$==.
    
</details>

21. <details markdown=1><summary markdown="span"> Does the chosen minimizer work with all types of distances? If not, can you make an example? </summary>

    \
    It ==works with cosine and correlation== (can be transformed into euclidean distance with a linear transformation), but ==does not work with manhattan== distance where ==median== is the minimizer.
    
</details>

22. <details markdown=1><summary markdown="span"> What is k-medoids? How does it work and what are the pros/cons? </summary>

    \
    ==Chooses input data points as centers: a medoid is the closest object to any other point in the cluster==. \
    It ==works with any type of distance, is robust to outliers== but ==computationally expensive== $O(K(N-K)^2)$. 

</details>

23. <details markdown=1><summary markdown="span"> What is BFR K means? What is it suited for and what are the assumptions made? </summary>

    \
    Variant of k-means for ==large datasets, works better in high dimensional euclidean space== and makes ==strong assumption on the shape of clusters==:
    - normally distributed around the centroid
    - independence between data dimensions

</details>

24. <details markdown=1><summary markdown="span"> What are 2 possible measures of quality for clusters? What do they depend on?</summary>

    \
    Clustering quality:
    - ==interal== evaluation
    - ==external== evaluation

    Note that ==these measures depend on data representation and similarity measure== adopted.
    
</details>

25. <details markdown=1><summary markdown="span"> What are 3 possible internal evaluation techniques? </summary>

    \
    Measures:
    - davies bouldin index $DB = \frac{1}{K} \sum_{i=1}^K max_{j \neq i} (\frac{\sigma_i + \sigma_j}{\delta(\mu_i, \mu_j)})$
    - dunn index $D = \frac{min_{1 \leq i \leq j \leq K} \delta(C_im C_k)}{max_{1 \leq k \leq K} \delta'(C_k)}$
    - silhouette coefficient
    
</details>

26. <details markdown=1><summary markdown="span"> How does external evaluation work? What is the main issue with this type of metric?  </summary>

    \
    External evaluation is ==based on gold standard data, which has been pre-classified==. It measures the ability to discover all the hidden patterns in our data. \
    ==The main issue with this type of data is that most often clustering algorithms are applied on data that is not labelled==.
    
</details>

27. <details markdown=1><summary markdown="span"> What are 2 possible external evaluation measures? </summary>

    \
    Measures:
    - purity (biased)
    - rand index (accuracy)
    - precision, recall, etc ...

</details>
