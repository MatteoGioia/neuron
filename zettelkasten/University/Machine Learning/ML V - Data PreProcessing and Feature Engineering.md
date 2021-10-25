# Data Preprocessing and Feature Engineering

## Recall questions
     - What are the steps for processing text? Why are embeddings so interesting?
     - What are common ways of processing images?
     - How can we process geospatial data? What does it mean that we can "enrich" it?
     - What type of processing is done on time series? How can we encode dates?
     - What is normalisation? What are the common utilisations?

## The workflow

![](./static/ML/workfloweng.png)

## Data and Features identification

Where to find data:
- legacy data from companies 
- open source data
- data repositories online

But most of this data is not ready to use. The harsh reality:

![](./static/ML/harsh.png)

## Feature extraction

This step consists in the transformation of raw data into features suitable for processing.

### Processing text

==Processing text==:
1. ==tokenization==
2. ==stemming (considering only the root)== or ==lemmatization== to normalise data
3. ==text encoding==, i.e. with ==bag of words or hot encoding, or embeddings== (modern approach)

<!-- This actually is one hot encoding -->
![](./static/ML/bagofwords.png)

==In embeddings, each word is represented as a value (real or binary) in a sparse document vector with $|V|$ dimensions. Each dimension is linked to some attribute that is used to group together similar words==, however we don't know how this dimnesions work internally.

![](./static/ML/wordemb.png)

The following is an intuitive representation of how words are grouped. ==This approach is not only used for text data but to any vectorial representation of data==, since it captures the "latent" similarities in data.

![](./static/ML/wordemb2.png)

### Processing images

Processing images: ==images can be represented at a pixel level and then, for example, fed to a Convolutional NN==.
There are simpler ways of processing, like ==histograms==.

### Processing geospatial data

Processing ==geospatial data, that usually is in the form of coordinates==: 
1. ==geocoding: recovering a point of interest from an address==
2. ==reverse geocoding: recovering an address from a point==

Geospatial data ==also usually contains typos, has bad accuracy/noise, conflicting position;== (i.e. WiFi says location is different from GPS).

==Geospatial data can also be enriched considering the surroinding infrastructures==.

### Processing time series and date/time

Processing ==time series, like stock market data: elimination of trends, average over selected time spans, normalize==

![](./static/ML/timedata.png)

Processing ==date and time==, that can be linked to other relevant info:
- can ==be easily represented with hot-encoding or binary features== (i.e. is_weekend)

## Feature transformation

In this step ==data is transformed to improve the accuracy of the algorithms.==

### Normalisation

==Changing distribution: many algorithms require a specific format for data==
- some algorithms require ==categorical data==
- some algorithms suffer for ==unbalanced ranges== (e.g. feature a with range [0,1] and feature b with range [0,1000])

Normalisation can be used to put data all on the same "level":
- ==centering: substracting to each sample the mean of all values==
- ==scaling: dividing all the values by the sample standard deviation $SDD = \sqrt{\frac{1}{N-1}\sum_{i}^{N} (x_i - \overline{x}_i)^2}$==

Normalisation for ==skewed data: sometimes there is an asimmetry in the distribution, compared for example to a standard gaussian. If data is skewed, the tail could act as an outlier and influence the results.==
One way of reducing such skewness is log transformation.

![](./static/ML/skeweddata.png)

==Normalisation into categorical values==: sometimes is necessary to turn data, that is not necessarily associated to a numerical value, into categorical numbers.
- ==one hot encoding: default for small datasets (introduces bias in bigger datasets)==
- ==label binarization==

### Handling missing data

Two main choices:
- removal: depending on the amount of missing data, the instance or the entire feature can be removed, although this method is not preferred as it creates a loss of data
- replacing missing values

The missing value can be replaced with basic methods, like mean for numerical values, most probable class for categorical ones. This approaches are risky as they alter the real distribution of the data, so there are better methods.

Regression imputation: the missing data is estimated with a linear combination of the other features. Correlation matrices can be used to design this regression model.

Imputation with K-Nearest Neighbours: we consider the $K$ instances where the j-th feature is not missing, and then we impute the missing value with the most frequent value (mode) amongs the j-th features of these K instances.

### Data augmentation

Enrichment of instances adding new features, that can be inferred from the other features or created manipulating the existing ones.

For instance, in the case of images this means adding rotations of the images. In othere datasets, i.e. one about football matches, the time between current match and the last victorious match. Calling circles, used by telco industries, are also a good example.

### Imbalanced categories

This particolar issue applies to classifiers and is due both to the distribution of the data and how we choose it. In some cases we are in fact interested in predicting the minority class (e.g. risk of heart disease).

One basic fix is either oversampling the minority class or undersampling the majority one, although this means altering the original distribution.

A tecnique like Synthetic Minority Oversampling Tecnique a.k.a. SMOTE works better since it creates new instances using a convex combination of the minority class instances. 

![](./static/ML/SMOTE.png)

Another tecnique that does not revolve around compensating with new instances is 
Anomaly Detection: istances that deviate too much from our sample data is treated as an outlier. This outlier can be either removed or we can reframe the classification problem into an anomaly detection problem (so the goal is to detect anomalies from the rest of the instances).

The last tecnique is Cost Sensitive Learning: instead of treating each misclassification as the same. A function $C(p,t)$ now expresses the cost of misclassifying an instance of $t$ as an instance of $p$. 

![](./static/ML/costsensitive.png)

The ML attempt will thus try to minimize the erorr and pay more attention to the minority class.

## Feature selection

In this step, we decide which features are necessary for training our model. However, it is not easy to decide if we have to add more or remove some, so we use automatic tools for feature selection.

### Filter methods

Select features based on a perfomance measure 

### Wrapper methods

### Embedded and hybtrid methods