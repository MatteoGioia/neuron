# Histograms

### Recall questions

1. <details markdown=1><summary markdown="span">  Enumerate possible histogram types </summary>
    
    \
	Histogram types:
	- ==intensity==: measures brightness
	- ==RGB==: one hist per channel
	- ==cumulative==: obtained by summing up R+G+B channels

</details>

2. <details markdown=1><summary markdown="span">  Explain what hist transformation, equalization and projection are.  What are they used for?</summary>
    
    \
    ==Transformation==: keeps the original range of values monotone increasing

	![](hist1.png)

    ==Equalisation==: transforms the intensity values so that the ==histogram of the output image approximately matches the flat (uniform) histogram==. Good for ==increasing global contrast==. Here is a solid explanation https://it.wikipedia.org/wiki/Equalizzazione_dell%27istogramma.

	![](hist2.png)

    ==Projection==: assigns ==equal display space to every occupied raw signal level==, regardless of how many pixels are at that same level.  

	![](hist3.png)

</details>

3. <details markdown=1><summary markdown="span">   What is plateau equalisation? Why is it as versatile as HP and HE?</summary>
    
    \
	![](hist4.png)
	![](hist5.png)
	

</details>

4. <details markdown=1><summary markdown="span">  What is contrast stretching? </summary>
    
    \
    We ==stretch the histogram to use the full grey level range==. Computed with ![](hist6.png)

	![](hist7.png)

</details>

5. <details markdown=1><summary markdown="span">   What is thresholding?</summary>
    
    \
	==Thresholding== allows us to ==tconvert an image to b&w==

    ![](hist8.png)

	Note that this works best when the histogram is ==bimodal== - i.e. ==values concentrated in two peaks==.

</details>