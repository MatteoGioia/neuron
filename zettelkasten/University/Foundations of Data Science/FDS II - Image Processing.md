# Image Processing

## Recall questions
    - WIP

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

Types of recognition problems:
- object identification
- object classification

After recognition, we can do:
- segmentation
- localize/detect

The right object to represent a class is:
- ...

## Basic digital image filtering

### Image filtering

(Image filtering image here)

Image filtering allows to:
1. reduce noise
2. fill in missing values
3. extract image features (i.e. edges/corners)

Images can be filtered:
- linearly: each pixel is replaced with a combination of his neighbours
- 2D convolution (discrete)

### Filters in 2D convolution

Uses (see later slides)

Example images and math

The following properties are true for the transformation T (convolution in our case):
- homogeneity
- additivity
- ...

### More about noise reduction

In the latter we'll assume images are homogenous: big shifts in the pixels will mean that the subject of the image is chaning (i.e. from background to a human/shape)