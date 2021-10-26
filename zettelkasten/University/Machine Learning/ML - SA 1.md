![](./static/ML/a1.png)

1. The main differences bewteen supervised, unsupervised and reinforcement learning lie in the way we train the model and the data that we feed to it.

    In supervised learning, the model is trained on labelled data from which it can learn a function called hypotesis, used for predicting a feature value of an instance never seen before. This value can be either continous, so the model is a classifier, or discrete, so the model is a regressor.

    In unsupervised learning, the model is trained on unlabelled data for which it tries to find some sort of classification. No ground truth is given, only costraints and the environment in which the model is trained are specified.

    In reinforcement learning, the model is trained in the environment it has to operate in, in ordine to learn the best course of action for each new situation. The model learns by taking decisions and receiving a reward or a punishment for each of them.

--- 

2. A labelled dataset is a dataset for which each instance has a list of features or attributes that represent their meaningful aspects or characteristics. For example,
a dataset on **cars** could be the following:

    | Model | Price | Color | Number of doors | Is_coupè|
    |---|---|---|---|---|
    |Ferrari | 300000.00 | Red | 3 | 1 (Yes)|
    |Ford fiesta| 25000 | Blue | 5| 0 (No) |  

    As we can see, each instance (row) has multiple features (columns) describing a different aspect. Each feature can either be a discrete value (e.g. number of doors), a real value (e.g. price) or a binary value (e.g. 4x4) used for classification.

    A supervised learning model can be trained on such datasets so that one feature of a new instance can be predicted based on the past instances examined. 

--- 

3. When making a ML model, the training phase is used to make the model learn some kind of function then used to make predictions on new data. However, the accuracy of the prediction of this model can be easily influenced by the data used to train it. For instance, a dataset which has not been normalised could easily lead to a model that makes wrong predictions because of noise in a few instances. Excessive training of the model on the training data could also lead to overfitting or, on the other hand, a prediction that is too simple could lead to underfitting. All these issue can't be detected on the training data, so the test data is used a way of seeing if any of these issue is present and to generally test the accuracy of our model.

---

4. Three common uses for supervised learning:
    - prediction of house prices 
    - prediction of risk of heart diseases in patient
    - predicition of uber prices

    In the first case, we can use the features of a house/apartment, such as sqr ft, the floor number and price, to create a model that predicts the best price for a house based on the sqr ft and the floor number. This is a good example of a regression problem, if we assume price is a real value.

    In the second case, the health statistics of patient who had an history of hearth diseases (age, weight, risks_stroke) can help to predict if a new patient is at risk, for example, for a heart attack. In this case, since the variable we are predicting is a discrete value (risks_stroke) and is either 0 or 1, the trained model is a classifier.

    The third case is actually utilised by Uber to calculate the optimal pricing for each ride, based on previous data, such as earlier rides' fares, and real time data, like weather or temperature.

---

5. CL, RG, RG (?), CL, RG, CL

---

6. Yes, classifiers can predict multiple values as long as they are discrete (e.g. the real function is not a continous function).

---

7. The hyperparameters of a ML model are characteristics of the model decided previously to its training. 
For instance, in the case of a NN, an hyperparameter could be the architecture of the network or the learning rate. Parameters are instead something that is tuned during training and are part of the optimisation problem, so for example in a NN the parameters we need to tune are the weight of the edges in order to minimise the error.

---

9. During the training phase, the model is trained to recognize new instances based on the labelled data in the dataset. To be more precise, the model learns a function $c(x)$ that outputs a discrete value used for classification. This classification is achieved, in the case of Decision Trees, through a greedy algorithm called recursive partitioning which aims at classying the instances in D. During testing, the accuracy of the outputted model is tested to see if, for example, it's overfitting or underfitting. When the model is accurate enough it can be used and go into the operational phase. 