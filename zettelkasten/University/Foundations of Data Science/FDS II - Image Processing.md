# Image Processing

## Recall questions
    - How does a camera work? 
    - What type of problems faces CV? 
    - What are the uses of image filtering? What are common filtering techniques?
    - What are the elements needed for a 3d convolution? What is its result? What happens if the filter is 1-D?
    - What are the properties of convolution?
    - What components make up an image? Why do we assume that an image is usually homogenous? Why it is important that noise averages to 0? Which are the 2 main methods used to reduce noise in a picture?
    - Why is the gaussian more "precise"?
    - How can we use a gaussian for patter matching? What are the useful side effects?
    - How can we use the derivatives for 1D edge detection? Why is it a good idea to combine them with a gaussian? What other tweaks can we use to reduce noise/ increase accuracy? (Hint: thr, hist)
    - Does the technique mentioned above work for 2D images? How?
    - How does the canny edge detector use gradient to detect edges?
    - How can we use 2nd derivatives to detect edges more easily? What can we do to make the process efficient? 
    - What happens when we increase/reduce the sigma of a gaussian? (Hint: thick & thin)
    - How can we use Hough transform to detect edges? What is the intuition about straight lines?
    - What are image descriptors? How can we use them for object recognition?
    - Why are histograms a good image descriptor? How can we compare them (measures)?
    - What is the basic algorithm for detection? What are the main advantages/drawbacks?
    - List the main performance metrics.
    - What are the ROC and AUROC? And the Precision-Recall curve?
    - What are log loss and brier loss?

## Basics of Image Processing

### Digital Camera Model

Image process:
- camera model (pinhole)
- digitizer
- digital image acquired with the digitizer

The result is a matrix with vectors of RGB values
- i.e. [255, 0, 0] is a red pixel

CV tries to "reverse" this process
- however items labels are necessary to know what the reversed values mean
- we also need to perceive partial objects, like obstructed ones (we'll use priors)

### Recognition Problems

Types of ==recognition problems==, i.e. in a picture/video:
- ==object identification==: identify a certain object 
- ==object classification==: identify all objects of a certain class

After recognition, we can do:
- ==segmentation==: separate pixels of foreground and background
- ==localize/detect==: the position of object and estimate its pose

The right object to represent a class can be defined in many ways, but ideally is something basic and 
easily recognizable

## Basic digital image filtering

### Image filtering

Example of some linear filtering applied to a ==3 x 3 patch==

![](../../..//FDS/ifiltering.png)

==Image filtering allows== to:
1. ==reduce noise== = smoothing
2. ==fill in missing values== = improve contrast
3. ==extract image features== = detect pattern (i.e. edges)

Images can be filtered:
- ==linearly==: each pixel is replaced with a combination of his neighbours
- ==2D convolution== (discrete)

### 2D Convolutions

2D convolution works through the use of:
- a ==discrete image $I[m,n]$==
- a ==filter kernel $g[k,l]$==

The result is a ==filtered image $f[m,n] = I \otimes g = \sum_{k,l} I[m-k,n-l] \cdot g[k,l]$==. Roughly speaking,
the filtered is flipped on the $x,y$ axis and is then "swiped" onto the image.

Notice that by convention the indexes start from the center of the patch, so $[0,0]$ will be the center, $[-1,-1]$ the top left corner and so on...
- in a 3x3 patch, $-1 \leq l,k \leq 1$ 

![](../../..//FDS/2dconv.png)

A special case is a 1-D filter applied to a 2-D image: in this situation $f[m,n] = I \otimes g = \sum_{k} I[m-k,n] \cdot g[k]$

![](../../..//FDS/1dfilter.png)


### Filters in 2D convolution

Example of a filter that does nothing

![](../../..//FDS/filex1.png)

Example of shifting:

![](../../..//FDS/filex2.png)

Example of blurring:

![](../../..//FDS/filex3.png)

==The following properties are true for the convolution==:
- ==homogeneity==: $\ T[aX] = aT[X]$
- ==additivity== $\ T[X_1 + X_2] = T[X_1] + T[X_2]$
- ==**superposition**== $\ T[aX_1 + bX_2] = aT[X_1] + bT[X_2]$ (necessary for a linear system)

![](../../..//FDS/filex4.png)

### More about noise reduction

In the following ==we'll assume images are homogenous==: big shifts in the pixels will mean that the subject of the image is chaning (i.e. from background to a human/shape)
- this means that small variations in nearby pixels are probably noise

==Image $I$ = $S$ + $N$==
- $S$ constant signal, e.g. radio wave
- $N$ noise, not depending on the signal

Furthemore, we can say that the intensity of each pixel is $I_i = s_i + n_i$, with $E(n_i) = 0$
- $s_i$ is deterministic
- $n_i, n_j$ are indipendent if $i \neq j$
- $n_i, n_j$ are indipendent and identically distributed, so a stochastic process

==The fact that the noise's average is 0 means that, roughly speaking, averagin the noise will reduce its effect==
- more formally, we can infer the original image from the noise

Two ==common ways== of doing that are:
- ==box filters==
- ==gaussian filters== (2d shown here): ==$g(x,y) = (\frac{1}{2 \pi \sigma^2})^{(-\frac{x^2 + y^2}{2 \sigma^2})}$==

The first one is really basic as it's a filter made to reduce a patch to an average of its pixels:

![](../../..//FDS/boxfilter.png)

A gaussian filter can be used to obtain a better effect:

![](../../..//FDS/gaussian2.png)

The ==gaussian filter works better as it gives "more importance" to nearby pixel rather than distant ones== when reducing noise
- this also makes sense from a probabilistic standpoint

![](../../..//FDS/gaussianvsbox.png)

### Efficient implementation

Both the gaussian and box filter can be implemented efficiently by convolving the rows first and then the columns: $(f_x \otimes f_y) \otimes I = f_x \otimes (f_y \otimes I)$.

For example, a box filter can be efficiently implemented by doing:

![](../../..//FDS/boxeff.png)

And a general $n$-dimensional gaussian can be seen as a 1-d gaussian applied $n$ times on the dimensions:
- 2D gaussian = $g(x,y) = (\frac{1}{2\pi \sigma^2})^{(-\frac{x^2 * y^2}{2 \sigma^2})}$
- 1D gaussian on $g(y) = (\frac{1}{\sqrt{2\pi} \sigma})^{(-\frac{y^2}{2 \sigma^2})}$

## Other uses of convolution

### Pattern matching

One way of doing ==pattern matching== is to ==scale the filter to match according to the size of the searched item==. However, another common use of convolution is pattern matching in images of different sizes, so with ==multi-scale representation==. The ==patter to match has always the same dimension, but the image is scaled each time==. 

Before ==downsampling== though it is ==necessary to apply a Gaussian to avoid aliasing==

![](../../..//FDS/multiscale.png)

Two questions of interest are:
- which information is preserved over scales
- which one is lost

In such cases, a ==gaussian works best because the information in the center of the image, which probabilistically is the most important one, is retained when blurring as a gaussian gives the "central" pixels more importance==. 

Another important consideration is that ==when smoothing with a gaussian, the high frequencies contained in the image signal get reduced, so we both reduce noise and can fit the image information in a smaller size==:

![](../../..//FDS/fourierwave.png)

### Edge detection with derivatives

One common method of find edges:
1. filter image to find brightness changes
2. fit lines to the raw measurements
3. project model into the image and "match" to lines
 
Another common approach is to stylize the object to a set of lines that indicate the edges and then use them for detection
- but how can we tell when what we are looking at is an actual edge 

Ideally, we want to:
- detected only edges and not noise
- detected correctly where the edge is
- give one single response per edge

![](../../..//FDS/edgedet1.png)

### 1D edge detection

In the following, the ==focus is edge detection on 1D images==, altough is possible to convert 2D images to a signal and then make the edge detection on the 1D 

One easy way of ==detecting edges is using derivatives==. In the following image, a steep change in the function means that the we are passing across an edge:

![](../../..//FDS/edgedet2.png)

So, what we can do is ==smooth the image with a gaussian to eliminate most of the noise and then apply a filter which is an approximation of the derivative==:

![](../../..//FDS/edgedet3.png)

To make it easier, ==since the filter and the gaussian are both linear we can apply the derivative first and then do the convolution $\frac{d}{dx}(g \otimes f) = (\frac{d}{dx}g) \otimes f$==:

![](../../..//FDS/edgedet4.png)

Another common technique is to ==set a treshold, either an hyper-parameter or a parameter that gets tuned during iteration, to distinguish noise from actual edges==.

==Hysteresis can also be used, so instead of one threshold 2 are used==. Makes more sense in 2D.

### 2D edge detection 

Using ==partial derivatives on the x and y axis the same edge detection technique can be applied to a 2D image:==
- we first apply a 2D gaussian
- then we do the derivative of the image

The partial derivatives can be approximated to this filters:
- x direction: $\frac{d}{dx} I(x,y) = I_x \approx I \otimes D_x$
- y direction: $\frac{d}{dy} I(x,y) = I_y \approx I \otimes D_y$

Where $D_x$, $D_y$ are approximated with these filters:

![](../../..//FDS/filters2d.png)

==On a 2D image, the x-axis derivative emphasizes the edges on the y (since it removes noise on the x axis) and viceversa.==

Following the same reasoning as before, since Gaussian filters are linear, the derivative can again be combined with the gaussian: $D_x \otimes (G \otimes I) = (D_x \otimes G) \otimes I$

### Using gradient to detect edges 

Another ==useful technique used to detect edges is checking the gradient of the image. In an image, the gradient direction is perpendicular to edges and the magnitude measures the edge strength==.

![](../../..//FDS/gradient1.png)

The process goes as follow:
1. ==calculate the gradient==
2. ==calculate the magnitude of the gradient==
3. ==calculate the direction of the gradient==

### Canny edge detector 

Canny edge detector:
1. ==computed magnitude of gradient on the whole image==
2. ==consider only the edges above a certain treshold==
3. ==thinning (non maximum suppression, a computer vision method that selects a single entity out of many overlapping entities) to reduce thick edges==

![](../../..//FDS/cannyedge.png)

### Using gradient to detect edges pt.2

Using ==partial derivatives on the x and y axis the same edge detection technique can be applied to a 2D image==:
- we first apply a ==2D gaussian==
- then we do the ==derivative of the image==

The partial derivatives can be approximated to this filters:
- x direction: $\frac{d}{dx} I(x,y) = I_x \approx I \otimes D_x$
- y direction: $\frac{d}{dy} I(x,y) = I_y \approx I \otimes D_y$

Where $D_x$, $D_y$ are approximated with these filters:

![](../../..//FDS/filters2d.png)

On a 2D image, the x-axis derivative emphasizes the edges on the y (since it removes noise on the x axis) and viceversa.

Following the same reasoning as before, since Gaussian filters are linear, the derivative can again be combined with the gaussian: $D_x \otimes (G \otimes I) = (D_x \otimes G) \otimes I$
an: $D_x \otimes (G \otimes I) = (D_x \otimes G) \otimes I$

### Laplacian for edge detection (scaling up) 

The canny edge detector is quite complex: ==using the 2nd derivative we can make our life easier==
- ==no treshold to check== (we look at 0 crossings instead)
- also we don't have to apply many gaussian and derivatives with different sigmas

![](../../..//FDS/dog.png)

The ==laplacian (difference of 2 gaussians) approximates nicely the 2nd derivative mixed with a gaussian==
- the way to ==do this efficiently is through the use of a gaussian pyramid==

![](../../..//FDS/piramidl.png)

As stated before, a ==smaller $\sigma$ will help with detection of finer edges, while a bigger one will help with bigger edges.==

### Detection of contours with Hough Transform 

==Detecting objects becomes much easier when we know what to detect==. Using the Hough Transform, we can extrapolate the contours
of images and make edge detection easier.

We can ==use the intuition that edges are made up of points, which are probably on the same straight line==
- ==this means all these points will have an increasing gradient magnitude.==

==Using the transform, we can look at the parameter space and search points where many straight lines intersect. The points associated with such straight lines will correspond to an edge==

![](../../..//FDS/hough.png)

Basically, when multiple points in the parameter space intersect, they "vote" for a line. Many votes will indicate an edge. 

## Object identification

### Challenges in obj. id.

In the following, we will go through the basic of object identification
- classification requires identification first!

Challenges when detecting objects:
- viewpoint changes
- illumination
- clutter
- occlusion
- noise

In the past, most paradigm made these basic assumptions:
- objects can be represented by a collection of images or ==appearances==
- we only need to compare 2D images
- we don't need a 3D model

### Global representation

We ==represent each view of an object with a global descriptor and recognize object that match with the global descriptors==.

![](../../..//FDS/objid1.png)

Some ==modes of variation are also easy to deal with by supplying the ML model with enough data==.
==Others can be built into the descriptors==, i.e. we can build descriptors invariant to them through normalisation (see later examples for clarification). 

### Color histograms

In 3d RGB histograms, even removing or rotating the object yields almost no significant difference 
in the resulting graph. This means we could use the histogram as a robust global descriptor that is invariant
to occlusion and rotation.

![](../../..//FDS/colorhist.png)

We can also flatten RGB histograms in joint color histograms and use them (refer to assigment 1).

### Color tone

Color tone is another way of recognizing object. This can be done by normalizing each color by the intensity,
so even if a line is shone on an object the descriptor is not influenced. This could be, again, a good descriptor invariant to 
illumination.

![](../../..//FDS/normint.png)

### EXTRA: Using only 2 colors to represent an object (WIP)

If we normalise an histogram by its intensity, we can also represent an image only using 2 colors.
In fact, $r + g + b = 1$

### Comparison measures 

There are ==multiple ways of measuring the distance of 2 histograms.==

==Intersection $\cup (Q,V) = \sum_i min(q_i, v_i)$:==
- range [0,1] after normalisation

==Euclidean distance $d(Q,V) = \sum_i (q_i - v_i)^2$==
- range $[0, \infty]$ 
- does wheigh cells equally
- ==not very discriminant==

==Chi Square $\chi^2 (Q,V) = \sum_i \frac{(q_i - v_i)^2}{q_i + v_i}$==
- range $[0, \infty]$ 
- does not wheigh cells equally
- is ==more discriminant==

Normalising is also useful to "separate" the image from the size of the representation
- the same histogram for 2 images of different size

### Basic recognition algorithm

==Algorithm steps==:
1. Build a set of histogram $H = {M_1, \ldots, M_n}$ for each know view of an object
2. Build an histogram $T$ for the test image
3. Compare the test image $T$ to each $M_k \in H$
4. Select the best match 

This algorithm, that uses a nearest neighbour strategy, has the following advantages:
- ==invariant to object translations, rotations==, etc.. (given the dataset to train it is enough)
- ==no perfect segmentation needed==

But has drawbacks too:
- ==can't identify some objects==
- ==pixel colors change with the illumination, so the same object could have different color depending on the lightning==

## Performance evaluation

### Score based evaluation

The recognition algorithm identifies (classifies) the query object as matching the 
training image if their similarity is above a treshold $t$.

A confusion matrix is a suitable way of showing the choices of our model:

![](../../..//FDS/confusion.png)

In this image, a good score is linked to:
- ==high true positives (TP) and true negatives (TN)==
- ==low false positives (FP) and false negatives (FN) a.k.a. Type 1 and 2 errors==

==Overall accuracy: $\frac{TP+TN}{N}$ where $N$ is the total.==

==Precision: $\frac{TP}{TP + FP}$==

==Positive recall: $\frac{TP}{TP + FN}$==
- a.k.a sensitivity or true positive rate

==Negative recall: $\frac{TN}{TN + FP}$==
- a.k.a specifity or true negative rate

==$F_1$-score: $(\frac{2}{recall^{-1} + precision^{-1}}) = 2 \frac {precision \cdot recall}{precision + recall}$==

A quick recap:

![](../../..//FDS/recap.png)

### ROC and AUROC

The ==receiver operator curve (ROC) is a good way to visualise the performance of our model:==

![](../../..//FDS/roc.png)

The ==best model is the one that fits the application==
- high false positives could be very expensive so we might want a low FPR
- or they could not really matter, and we maybe care about a high TPR

We ==can also consider the area under this curve (AUROC), to see, roughly speaking, the proportion of correct guesses 
if we take a random positive and a random negative==

If we have an ==AUROC of:==
- ==1, we are guessing perfectly==
- ==0.5, we are guessing randomly==

### Precision-Recall curve

When ==doing Object identification True Negatives are not really defined, so the Precision-recall curve is preferred==
- i.e. infinite true negatives could be defined on a image 

![](../../..//FDS/prc.png)

### Log loss and brier score

Two other useful measures:
- ==log loss $\frac{1}{N} \sum_{i=1}^{N} -y_i log \hat{y}_i - (1 - y_i) log (1 - \hat{y}_i)$==
- ==brier score $\frac{1}{N} \sum_{i=1}^{N} (\hat{y}_i - y_i)^2$==

Log loss heavily penalizes confident wrong answers and rewards confident correct answers.
