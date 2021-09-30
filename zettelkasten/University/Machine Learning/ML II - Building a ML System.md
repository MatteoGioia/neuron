# Building a ML system

## Recall questions
   - WIP

## Phases of the build

### Design cycle of a ML system

(Immagine)

### Data preparation

In this step we identify:
- the correct type of data to collect
- where to collect it
- if the data is ready for analysis

### The importance of data

When choosing the data for a ML system:
- the type matters (i.e. images for DNL)
- the quantity, quality and how we represent it is important too (i.e. DNL work with pixels, other ML algorithms may need some preprocessing on the image)

Data is also commonly heterogenous and will probably need to be reorganized by
- transformations: cleaning errors and reduce redundancy
- preprocessing: renaming, rescaling, etc...


### Feature Engineering

Feature engineering is about finding the best descriptors
- sometimes the features are just too many
- or they can be converted to "higher level" features

One way of doing this is by using dimensionality reduction

### Model Generation

When choosing the right model we can decide the ...

The choice is among:
- supervised learning: training data with correct examples
- unsupervised learning: no data with correct examples
- semi-surpervised learning
- reinforcement learning: rewards based on correctness of chosen strategy

(Immagine learning)

Another importance difference is the one among:
- classifiers: discrete function to find boundaries
- regressors: continous function to best-fit curve

Some examples:

(Immagine tempo-umidità)

In the classification the line is used to tell to which category the new object belong, in the regression
is used to predict the next value given the input. The output line can also be non linear (e.g. the function is a polynomial)

(Immagine caratteri)

### Hyper parameter tuning

...

## An overview on learning models

### Supervised learning

(Immagine workflow)

Given examples ($x_i,y_i$) of an unknown function $y = f(x)$ learn $f(x)$ to predict its values (labels)
for unseen examples of $x$.

If $f(x)$ is:
- discrete: classification
- algebraic (continous): regression
- probability: probability estimation (still similar to regression)

In the course...

### Unsupervised learning

(Immagine workflow)

### Reinforcement learning