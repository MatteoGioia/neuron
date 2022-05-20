# Recommender Systems

### Recall questions

1. <details markdown=1><summary markdown="span"> Define the formalism for recommender systems. </summary>

    \
	![](../../../static/BIG/rs1.png)

</details>

2. <details markdown=1><summary markdown="span"> What are the 3 main challenges that a recommender system has to tackle? </summary>

    \
	3 key challenges:
	- ==data collection==: collect known ratings to fill the utility matrix
	- ==rating prediction==: predict new ratings
	- ==recommendation evaluation==: measure the performance of the system (both offline and online)

</details>

3. <details markdown=1><summary markdown="span"> What are 2 possible ways to collect data? </summary>

    \
	2 ways to collect data:
	- ==explicit==: ask people for ratings
	- ==implicit==: learn from ==user interaction==

</details>

4. <details markdown=1><summary markdown="span"> What are 2 issues with doing rating prediction? </summary>

    \
	2 main issues:
	- the ==utility matrix $R$ is sparse==
	- ==cold start==: new users have no history
	
</details>

5. <details markdown=1><summary markdown="span"> What are 4 possible techniques to perform evaluation ? </summary>

    \
	4 techniques:
	- RMSE
	- Mean Average Precision
	- Personalization
	- Serendipity
	
</details>

6. <details markdown=1><summary markdown="span"> What are the 3 main recommendation strategies? </summary>

    \
	3 strategies:
	- ==content based filtering==: filter items based on their representation
	- ==collaborative filtering==: ==neighborhood based==, ==latent factor based==, ==hybrid==
	- ==hybrid==

</details>

#### ==Content based filtering==

7. <details markdown=1><summary markdown="span"> Describe the core idea behind content based filtering and the steps of such process. </summary>

    \
	In content based filtering, the idea is ==recommending to user $u$ items similar to the ones already highly rated==. 
	The ==steps== are:
	1. Build ==item profiles==
	2. Build ==user profiles based on item profiles==
	3. Match users with items they could like

</details>

8. <details markdown=1><summary markdown="span"> What is an item profile? Can you make an example of one is built? </summary>

    \
	Item profile: ==set of features that characterizes the item==.
	One example could be building the profile of books based on the word inside them. (see slides for complete example)
	

</details>

9. <details markdown=1><summary markdown="span"> What about the user profiles? How can we build one? </summary>

    \
	We can create a user profile ==summing up the values of each ranked item and computing the average==. It is also a good idea to ==subtract the mean ranking to each value== and ==compute the averages separately==. (this ensures that each entry is weighted by the ranking)

</details>

10. <details markdown=1><summary markdown="span"> How do we build predictions for unseen items then? </summary>

    \
	We can ==compute the cosine similarity between our user profile and unseen item==, picking the ==best ones== at each iteraction.
	![](../../../static/BIG/sr2.png)

</details>

11. <details markdown=1><summary markdown="span"> What are the pros and cons of content based filtering? </summary>

    \
	Pros:
	- ==no need for data on users==, only their ratings
	- ==no **item cold start** problem==
	- explainable

	Cons:
	- ==overspecialized==
	- ==need to choose features==
	- ==cold start for **new users**==
	- ==unable to exploit similar users ratings==
	- ==updating users' profiles might be tricky== (need to keep a moving average?)

</details>

#### ==Collaborative filtering NB==

12. <details markdown=1><summary markdown="span"> What is the core idea of collaborative filtering? How is it different from content filtering? </summary>

    \
	The core idea of CF is ==leveraging preferences of users similar to the target==. Note that ==no profile is built during these procedures==.

</details>

13. <details markdown=1><summary markdown="span"> What are 2 possible similarities that can be considered? </summary>

    \
	Two techniques:
	- ==user based==: evaluate preferences based on ratings of similar users
	- ==item based==: evaluate preferences based on neighboring items by the same user

</details>

14. <details markdown=1><summary markdown="span"> How does user based neighborhood work? </summary>

    \
	We can define a sequence of step:
	- ==identify similar users==
	- ==restricts recommendations== to product already rated by similar users
	- compute similarity

</details>

12. <details markdown=1><summary markdown="span"> How do we define similarity among users? </summary>

    \
	We define similarity between users as ==users giving similar ratings to the same items==.
	

</details>

13. <details markdown=1><summary markdown="span"> What measure do we use for computing user similarity? Why? </summary>

    \
	We use ==Pearsonn correlation==, which is basically a Cosine similarity that makes it so ==missing values are considered as average instead of a negative value==.  
	![](../../../static/BIG/sr3.png)

</details>

14. <details markdown=1><summary markdown="span"> Finally, what are 2 ways to aggregate the obtained ratings? </summary>

    \
	We can either compute an ==average==, or ==weight it by user similarity==.
	![](../../../static/BIG/sr5.png)

</details>

15. <details markdown=1><summary markdown="span">  What are 3 issues with user based collaborative filtering? </summary>

    \
	3 drawbacks:
	- ==sparsity==: system does not work well with ==many items but few ratings== 
	- ==efficiency==: need to compute Pearsonn correlation many times
	- ==aging==: need to ==recompute user profiles constantly==

</details>

16. <details markdown=1><summary markdown="span">  What is the main difference between user and item based cf?  </summary>

    \
	The main idea is to use ==items' ratings, which are more stable over time==. Furthermore, the number of items is often  bigger than the number of users. 

</details>

17. <details markdown=1><summary markdown="span"> What is the main idea behind item based CF? Why is the same matrix as before involved? </summary>

    \
	This time, instead of looking for similar users we look for ==similar items==. However, we express the similarity ==in terms of the ratings expressed by the users==.
	![](../../../static/BIG/sr6.png)

</details>

18. <details markdown=1><summary markdown="span">  How do we compute the rating for an item ? </summary>

    \
	Given $k$ neighboring items (similar), we can either compute ==a plain average or a weighted average==.

</details>

19. <details markdown=1><summary markdown="span">  What was noticed (empirically) about item based cf? </summary>

    \
	That in general, ==item based CF works better than user based CF==.

</details>

#### ==Collaborative filtering MB==

20. <details markdown=1><summary markdown="span">  What is model based CF? What is the issue that it tries to fix? </summary>

    \
	The main idea of model based is to ==express items and users in the form of latent vectors==. This is useful in countering the ==curse of dimensionality==, especially when we deal with computing the most similar users. 

</details>

21. <details markdown=1><summary markdown="span">  Explain the idea behind latent based and how matrix factorization works. </summary>

    \
	As said before, the idea is to ==map both users and items to a **joint** latent factor d-dimensional space==.  This works because ==user rankings can be expressed as the correlation between the factors that characterize users and items==,  so computed as a dot product in the latent space. \
	==Note that this vectors are learned a posteriori, through Matrix Factorization=.
	
	![](../../../static/BIG/sr7.png)
	![](../../../static/BIG/sr8.png)
	
</details>

22. <details markdown=1><summary markdown="span">  What is the chosen loss function? What are the 2 possible ways of minimizing it? </summary>

    \
	![](../../../static/BIG/sr9.png) \
	To optimize it, we can either use ==SGD== or ==Alternative Least Squares==. 

</details>

23. <details markdown=1><summary markdown="span">  Explain how the first method works. What is its "main drawback"? </summary>

    \
	We are simply applying ==SGD==, considering one of the variables as fixed each time. (For detailed steps see slides)
	The issue with it is that ==we have $d(m+n)$ parameters to optimize, a number that becomes big really quickly in high dimensions==.

</details>

24. <details markdown=1><summary markdown="span">  Explain the idea behind ALS. What is the effective result of this procedure? </summary>

    \
	The main idea is ==to fix one of the matrices each time, in order to make the problem quadratic==. This allows to solve it as if we were dealing with standard "regression", i.e. by effectively computing a ==closed form solution like the normal equation==.

</details>

25. <details markdown=1><summary markdown="span"> Why do we have to take bias into account in collaborative filtering? How can we measure it?</summary>

    \
	Many of the ==observed ratings may be influenced by a bias==. This bias is quantifiable as:
	![](../../../static/BIG/sr10.png)

</details>

26. <details markdown=1><summary markdown="span">  What are the 3 main drawbacks of CF? </summary>

    \
	Even with model based, CF still suffers from 3 main issues:
	- ==cold start== for ==both items and users==
	- ==scalability==, as seen before a lot of computational power may be required
	- ==sparsity==, because many items are not rated by users

</details>

#### ==Evaluation metrics==

26. <details markdown=1><summary markdown="span"> What is personalization? Why is it useful?  </summary>

    \
	Ideally, we ==want our system to not recommend the same items to the users==. We can compute the ==grade of personalization as dissimilarity between users' lists of recommendations==.
	![](../../../static/BIG/sr11.png)

</details>