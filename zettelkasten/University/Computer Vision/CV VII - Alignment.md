# Alignment

### Recall questions

1. <details markdown=1><summary markdown="span"> What are the 2 most common alignment techniques? </summary>
    
    \
	Two broad approaches:
	- direct ==pixel based alignment==
	- ==feature based== alignment: align where ==feature descriptors agree==

</details>


2. <details markdown=1><summary markdown="span"> What are the most basic 2d transformations? </summary>
    
    \
    Most common:
    - similarity: ==translation, scale, rotation==
    - ==affine==
    - ==projective (homography)==
    
    
</details>


3. <details markdown=1><summary markdown="span"> How do we compare 2 patches that could be aligned? Which feature descriptors can we use? </summary>
    
    \
    Possible techniques:
    - ==compare vectors of raw intensity values==
    - ==compare histogram==, for example using ==SIFT== ![](../../static/CV/ali1.png)
    
</details>


4. <details markdown=1><summary markdown="span"> What are the 2 main strategies for feature matching? What do we have to deal with? </summary>
    
    \
    To carry on with the alignment, we want to generate ==putative matches==, which are ==patches in the other image which could match the original based on the appearance==. \
    In doing so, we can adopt 2 strategies:
    - ==exhaustive search==
    - ==fast approximate nearest neighbor search==

	In both cases, however, we might have ==many outliers that we have to deal with==.
	

</details>


5. <details markdown=1><summary markdown="span"> How can we use RANSAC to find inliers in putative matches? </summary>
    
    \
	![](../../static/CV/ali2.png)

</details>


6. <details markdown=1><summary markdown="span"> What about incremental alignment ?</summary>
    
    \
	![](../../static/CV/ali3.png)

</details>


7. <details markdown=1><summary markdown="span"> Is it possible to also use Hough transforms? </summary>
    
    \
	![](../../static/CV/ali4.png)

</details>


8. <details markdown=1><summary markdown="span"> And hashing? How is it used for finding inliers? </summary>
    
    \
	![](../../static/CV/ali5.png)

</details>