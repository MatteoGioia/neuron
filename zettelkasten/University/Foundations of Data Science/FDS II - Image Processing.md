# Image Processing

## Recall questions
    - How does a camera work? 
    - What type of problems faces CV? 
    - What are the uses of image filtering? What are common filtering techniques?
    - What are the elements needed for a 3d convolution? What is its result? What happens if the filter is 1-D?
    - What are the properties of convolution?
    - What components make up an image? Why do we assume that an image is usually homogenous? Why it is important that noise averages to 0? Which are the 2 main methods used to reduce noise in a picture?
    - Why is the gaussian more "precise"?

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

![](./static/FDS/ifiltering.png)

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

![](./static/FDS/2dconv.png)

A special case is a 1-D filter applied to a 2-D image: in this situation $f[m,n] = I \otimes g = \sum_{k} I[m-k,n] \cdot g[k]$

![](./static/FDS/1dfilter.png)



### Filters in 2D convolution

Example of a filter that does nothing

![](./static/FDS/filex1.png)

Example of shifting:

![](./static/FDS/filex2.png)

Example of blurring:

![](./static/FDS/filex3.png)

==The following properties are true for the convolution==:
- ==homogeneity==: $\ T[aX] = aT[X]$
- ==additivity== $\ T[X_1 + X_2] = T[X_1] + T[X_2]$
- ==**superposition**== $\ T[aX_1 + bX_2] = aT[X_1] + bT[X_2]$ (necessary for a linear system)

![](./static/FDS/filex4.png)

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

![](./static/FDS/boxfilter.png)

A gaussian filter can be used to obtain a better effect:

![](./static/FDS/gaussian2.png)

The ==gaussian filter works better as it gives "more importance" to nearby pixel rather than distant ones== when reducing noise
- this also makes sense from a probabilistic standpoint

![](./static/FDS/gaussianvsbox.png)
