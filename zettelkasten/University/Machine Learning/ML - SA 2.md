![](./static/ML/a2q1.png)

1. Overfitting is an issue derived from excessively training a model to the point that the  hypotesis fits perfectly the training data. The ML model then loses the ability to generalize, so the performance on real data is actually far worse than on training data.

---

2. Overfitting in decision trees is often associated with trees that are too "bushy", in the sense that they have many branches to address each case of the dataset thus losing the ability to generalize at the same time.
    
    There are 3 main strategies to deal with this situation, that are generally called pruning since the aim is to remove part of the branches:
    - pre pruning: the algorithm is stopped before the tree becomes too bushy, which corresponds, for example, when the prediction made by the hypotesis function has support under a certain treshold  
    - post pruning: the tree is grown fully, and the branches with low support are removed afterwards  
    
    One of the most popular post pruning techniques that also uses cross validation is Reduced Error Pruning. After the tree is fully grown and while the accuracy does not decrease:
    - one branch is picked and it's replaced with the majority class
    - the new temporary tree is tested on the test set and if the accuracy has not decreased the branch is actually replaced with the majority class

---

3. Decision trees can handle continuous features through discretization of the features.

4. Decision trees can't handle continous features as they are classifiers by definition, so the hypotesis has the form of a discrete function $c(x)$.

---

5. DT are classifiers, so they are meant to predict features with discrete values, while RT are regressors, so they are meant to predict continous values.

---

6. DT and RT both use greedy techniques to detect the optimal decision boundaries, so they make locally optimal choices. This is because finding the optimal boundaries is a NP-hard problem.

    In the case of DT, the technique used is a greedy recursive partitioning of the space, that aims at choosing the best feature to split on at each iteration of the algorithm that builds the tree. The locally optimal partition is decided through the used of a metric called Information Gain (IG), that quantifies the reduction of uncertainty on the decision when splitting on a certain feature. This translates, roughly speaking, in sets where it's easier to classify the instances based on such feature ("more pure sets").
    The IG of a feature is calculated as $IG = E(D) - \sum_{v \in V(f)} \frac{|D_v|}{|D|}E(D_v)$, where $E(D)$ is the entropy of the dataset and $E(D_v)$ is the entropy of a set where feature $f$ has value $v$.

    For the RT the technique used instead is called Recursive Binary Splitting and works through the aid of a metric called the Residual Sum of Squares (RSS)  ==FINIRE==

---

7. The support of a rule (prediction) $\frac{|D_v|}{D}$ is the set of examples in the dataset that satisfy it. The confidence shows how "accurate the rule is" and is calculated as the subset of $D_v$ correctly classified by the rule. Ideally, we want a balance of both, since rules with high support but low confidence are not really useful since they are going to be wrong most of the times, and rules with high confidence but low support can't be expected to be a good generalization.

--- 

8. Support = $\frac{1}{4}$ Confidence = $\frac{1}{5}$