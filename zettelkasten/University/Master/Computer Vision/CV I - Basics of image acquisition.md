# Image acquisition

### Recall questions

1. <details markdown=1><summary markdown="span">  Explain the meaning of the following formula. Use the hints if necessary. </summary>
    
    \
	![](acq1.png)

	Notation for ==reflected light==:
	- $\lambda$ is the ==wavelength of the light source==
	- $E$ ==incident light on a point==
	- $r$ ==reflectivity function==

</details>

2. <details markdown=1><summary markdown="span"> Why is the formula for the projection missing z? What are the main projection types? </summary>
    
    \
    ![](acq2.png)

	Two types:
	- ==perspective==: natural but mathematically complex
	- ==orthographic==:  object size independent of the distance from the  capturing device

</details>

3. <details markdown=1><summary markdown="span"> What is the sensitivity of a capturing device? How do we know how much light is captured for a certain coordinate? </summary>
    
    \
    ![](acq3.png)

	Function of $(x,y)$ to know ==amount of reflected light captured==:
	![](acq4.png)

</details>

4. <details markdown=1><summary markdown="span">  What is the final formulation when considering RGB colors? </summary>
    
    \
    ![](acq5.png)

	Where the sensitivity function is for both R,G and B.
    

</details>

5. <details markdown=1><summary markdown="span">  Explain the conventional format in which images are represented. </summary>
    
    \
    ![](acq6.png)

	This convention is mostly in place because old CRTs used to ==refresh images from top left to bottom right==.

</details>

6. <details markdown=1><summary markdown="span"> What is sampling? What is image quantisation? </summary>
    
    \
    To store images in a computer we have to ==sample and quantise (digitise)== the image function. Sampling refers to ==considering the image only at a finite number of points==. And ==quantisation refers to the representation of the grey level value at the sampling point using finite number of bits==.

	Also see:
	- https://en.wikipedia.org/wiki/Quantization_(signal_processing)
	- https://en.wikipedia.org/wiki/Sampling_(signal_processing)

	![](acq7.png)

</details>

7. <details markdown=1><summary markdown="span">  What is a pixel? And the spatial resolution?</summary>
    
    \
    A pixel ==corresponds to the smallest treatable area==. The spatial resolution is instead ==number of pixels utilised in construction of the image==.
    

</details>

8. <details markdown=1><summary markdown="span"> What is connectivity? How is it linked to adjacency?  </summary>
    
    \
	Hint: ==neighbourhood==
	![](acq8.png)
	![](acq9.png)

	Also see: ==paths== (pixels must be adjacent)

</details>