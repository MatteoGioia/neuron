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