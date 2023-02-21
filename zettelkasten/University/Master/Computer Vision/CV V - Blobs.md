# Blobs

### Recall questions

1. <details markdown=1><summary markdown="span">  What is a blob?  </summary>
    
    \
    The ==patch of an image that differs in properties, such as brightness or colour, compared to surrounding regions.==

</details>


2. <details markdown=1><summary markdown="span">   What are characteristics of good features? </summary>
    
    \
    A good feature is:
    - ==repeatable==, in the sense that it can be ==found in several images despite potential transformations==
    - ==compact/efficient==
    - ==local==
	

</details>


3. <details markdown=1><summary markdown="span">  Summarise the basic steps of Harris corner detector.</summary>
    
    \
    ![](blob.png)

	Here is a good explanation of how the Harris corner detector works: https://docs.opencv.org/3.4/dc/d0d/tutorial_py_features_harris.html

</details>


4. <details markdown=1><summary markdown="span">  To which transformations is the Harris corner detector invariant?</summary>
    
    \
	Harris corner detector is invariant to:
	- ==rotation==
	- ==affine intensity change (partially)==

	It is ==not invariant to scaling!==

</details>

5. <details markdown=1><summary markdown="span"> How can we detect blobs in an image?  Why do we need scale normalization? </summary>
    
    \
    We can look for a =="superposition" of two ripples== when looking at the laplacian applied of the signal.

	![](blob1.png)

	To make this ==process scale invariant, we must apply scale normalisation== so that the response of the laplacian ==does not decrease as scale increases==.

	![](blob2.png)

</details>


6. <details markdown=1><summary markdown="span"> How can we make the process of detecting blobs more efficient?</summary>
    
    \
	==Combine==:
	- approximation of ==laplacian as difference of gaussians==;
	- application of ==DoG at different scales==

</details>


7. <details markdown=1><summary markdown="span"> How can make the detection process invariant to affine transformations?</summary>
    
    \
     Read this: https://en.wikipedia.org/wiki/Harris_affine_region_detector#Affine-invariant_points

</details>

