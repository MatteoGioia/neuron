# Data Preprocessing and Feature Engineering

## Recall questions
     - WIP

## The workflow

![](./static/ML/workfloweng.png)

## Data and Features identification

### Finding a good data source

Where to find data:
- legacy data from companies 
- open source data
- data repositories online

But most of this data is not ready to use. The harsh reality:

(immagine)

### Feature extraction

This step consists in extracting data from many sources.

Processing text:
1. tokenization
2. stemming (considering only the root) or lemmatization to normalise data
3. text encoding, i.e. with bag of words or hot encoding, or embeddings (modern approach)

(immagine di confronto bag of words and hot encoding)

(immagine embeddings)

Processing images: images can be represented at a pixel level and then, for example, fed to a Convolutional NN.
There are simpler ways of processing, like histograms.

Processing geospatial data, that usually is in the form of coordinates: 
1. geocoding: recovering a point of interest from an address
2. reverse geocoding: recovering an address from a point

Geospatial data also usually contains typos, has bad accuracy/noise, conflicting position (i.e. WiFi says location is different from GPS).

Geospatial data can also be enriched considering the surroinding infrastructures.

Processing time series, like stock market data:
- elimination of trends, average over selected time spans, normalize

(Immagine)

Processing date and time, that can be linked to other relevant info:
- can be easily represented with hot-encoding or binary features (i.e. is_weekend)

### Feature transformation

In this step data is transformed to improve the accuracy of the algorithms. 

(THIS SECTION NEEDS TO BE DIVIDED)

Normalisation: many algorithms require a specific format for data
- some algorithms require categorical data
- some algorithms suffer for unbalanced ranges (e.g. feature a with range [0,1] and feature b with range [0,1000])

Normalisation is achieved through multiple ways:
- centering: substracting to each sample the mean of all values 
- scaling: dividing all the values

Normalisation for skewed data

Normalisation for categorical values
- one hot encoding
- label encoding


### Feature selection

## Preprocessing data