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

### Efficient implementation

Both the gaussian and box filter can be implemented efficiently by convolving the rows first and then the columns: $(f_x \otimes f_y) \otimes I = f_x \otimes (f_y \otimes I)$.

For example, a box filter can be efficiently implemented by doing:

![](./static/FDS/boxeff.png)

And a general $n$-dimensional gaussian can be seen as a 1-d gaussian applied $n$ times on the dimensions:
- 2D gaussian = $g(x,y) = (\frac{1}{2\pi \sigma^2})^{(-\frac{x^2 * y^2}{2 \sigma^2})}$
- 1D gaussian on $g(y) = (\frac{1}{\sqrt{2\pi} \sigma})^{(-\frac{y^2}{2 \sigma^2})}$

## Other uses of convolution

### Pattern matching

One way of doing pattern matching is to scale the filter to match according to the size of the searched item. However, another common use of convolution is pattern matching in images of different sizes, so with ==multi-scale representation==. The patter to match has always the same dimension, but the image is scaled each time. 

Before ==downsampling== though it is necessary to apply a Gaussian to avoid aliasing:scre\

![](./static/FDS/multiscale.png)

Two questions of interest are:
- which information is preserved over scales
- which one is lost

In such cases, a gaussian works best because the information in the center of the image, which probabilistically is the most important one, is retained when blurring as a gaussian gives the "central" pixels more importance. 

Another important consideration is that when smoothing with a gaussian, the high frequencies contained in the image signal get reduced, so we both reduce noise and can fit the image information in a smaller size:

![](./static/FDS/fourierwave.png)

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

![](./static/FDS/edgedet1.png)

### 1D edge detection

In the following, the focus is edge detection on 1D images, altough is possible to convert 2D images to a signal and then make the edge detection on the 1D 

One easy way of detecting edges is using derivatives. In the following image, a steep change in the function means that the we are passing across an edge:

![](./static/FDS/edgedet2.png)

So, what we can do is smooth the image with a gaussian to eliminate most of the noise and then apply a filter which is an approximation of the derivative:

![](./static/FDS/edgedet3.png)

To make it easier, since the filter and the gaussian are both linear we can apply the derivative first and then do the convolution $\frac{d}{dx}(g \otimes f) = (\frac{d}{dx}g) \otimes f$:

![](./static/FDS/edgedet4.png)

Another common tecnique is to set a treshold, either an hyper-parameter or a parameter that gets tuned during iteration, to distinguish noise from actual edges.

Hysteresis can also be used, so instead of one threshold 2 are used. Makes more sense in 2D.

### 2D edge detection

Using partial derivatives on the x and y axis the same edge detection tecnique can be applied to a 2D image:
- we first apply a 2D gaussian
- then we do the derivative of the image

The partial derivatives can be approximated to this filters:
- x direction: $\frac{d}{dx} I(x,y) = I_x \approx I \otimes D_x$
- y direction: $\frac{d}{dy} I(x,y) = I_y \approx I \otimes D_y$

Where $D_x$, $D_y$ are approximated with these filters:

![](./static/FDS/filters2d.png)

On a 2D image, the x-axis derivative emphasizes the edges on the y (since it removes noise on the x axis) and viceversa.

Following the same reasoning as before, since Gaussian filters are linear, the derivative can again be combined with the gaussian: $D_x \otimes (G \otimes I) = (D_x \otimes G) \otimes I$

### Using gradient to detect edges

Another useful technique used to detect edges is checking the gradient of the image. In an image, the gradient direction is perpendicular to edges and the magnitude measures the edge strength.

![](./static/FDS/gradient1.png)

The process goes as follow:
1. calculate the gradient
2. calculate the magnitude of the gradient
3. calculate the direction of the gradient

### Canny edge detector

Canny edge detector:
1. computed magnitude of gradient on the whole image
2. consider only the edges above a certain treshold
3. thinning (non maximum suppression) to reduce thick edges 

During 3 we check if the pixel is a local maximum along gradient direction...

Smaller gaussian to detect small edges, bigger to dected big edges

### Laplacian for edge detection (scaling up)

The canny edge detector is quite complex: using the 2nd derivative we can make our life easier
- no treshold to check

First smooth with a gaussian
