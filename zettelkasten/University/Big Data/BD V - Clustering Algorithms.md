# Clustering algorithms

We focus on partitioning based clustering.

### Recall questions

1. <details markdown=1><summary markdown="span"> What is hard clustering (formally)? What is the main issue with finding the optimum? </summary>

    \
    **Input**: set of $N$ data points, a number $K$ s.t. $K < N$\
    **Output**: partition of the $N$ data points into $K$ clusters \
    **Goal**: find the partition that optimizes a certain criterion \
    ==Finding the optimum is NP-Hard== as there are $O(N^k)$ apprx. partition to examine (Stirling partition number).

</details>

2. <details markdown=1><summary markdown="span"> Describe the flat hard clustering framework? </summary>

    \
    ![](./static/BIG/cl1.png)

</details>

3. <details markdown=1><summary markdown="span"> What is the objective function for the hard clustering framework? What particular property does it have? </summary>

    \
    ![](./static/BIG/cl2.png) \
    Furthermore, since we have a discrete assigment matrix $A$, our ==function is non-convex, so it allows for multiple local minima==.

</details>

4. <details markdown=1><summary markdown="span"> What is the structure of the iterative solution? </summary>

    \
    Steps:
    1. Assignment step
    2. Update step
    Note that ==this function does might get stuck on a local minima==.

</details>

5. <details markdown=1><summary markdown="span"> How does the sassignment step work? </summary>

    \
    ![](./static/BIG/cl3.png)

</details>

6. <details markdown=1><summary markdown="span"> How does the update step work? </summary>

    \
    ![](./static/BIG/cl4.png) \
    Also see slide 30-40 for detailed steps.  

</details>

7. <details markdown=1><summary markdown="span"> What is the cluster representative in k-means? What is the goal of k-means? </summary>

    \
    Centroids, i.e. center of mass. The goal is constructing clusters s.t. the total within cluster $SDD$ or **Sum of Squared Distances** is minimized.

</details>

8. <details markdown=1><summary markdown="span"> What is the setup of k-means? And the objective function? </summary>

    \
    ![](./static/BIG/cl5.png)
    ![](./static/BIG/cl6.png)

</details>

9. <details markdown=1><summary markdown="span"> Describe the assignment and update steps in k-means (formally)? Can you describe intuitively what is going to be the output of the update?</summary>

    \
    See slides 45-57. As expected, the new output (that minimizes the distances w.r.t. to nodes in the cluster) is nothing more than a new centroid, so the mean!
   
</details>

10. <details markdown=1><summary markdown="span"> Describe the steps of k-means. What are possible stopping criteria? </summary>

    \
    ![](./static/BIG/cl7.png) \ 
    Possible stopping criterions are:
    - ==fixed number of iterations==
    - ==cluster assignment stops changing==
    - ==centroids don't change== (by some threshold)
    
   
</details>