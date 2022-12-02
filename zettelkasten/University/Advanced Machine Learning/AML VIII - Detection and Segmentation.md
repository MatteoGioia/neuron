# Detection and segmentation

### Recall questions on segmentation

1. <details markdown=1><summary markdown="span"> How is the segmentation task defined? </summary>
    
    \

</details>


2. <details markdown=1><summary markdown="span"> What is the difference between "things" and "stuff" and why does it matter?  </summary>
    
    \
    Things are ==individual instances with separate identities, recognized by "looking" at the entirety of the object==. Stuff, instead, ==can be identified at a pixel level, for instance looking at the texture==.

</details>


3. <details markdown=1><summary markdown="span">  How can we use convolutions for segmentation? Why is it computationally expensive and what can we do about it? </summary>
    
    \

</details>


4. <details markdown=1><summary markdown="span"> What are 3 possible up-sampling techniques? (hint: pooling)  </summary>
    
    \
    Unpooling techniques:
    - Nearest Neighbor 
    - Bed of Nails
    - Max Unpooling

</details>


5. <details markdown=1><summary markdown="span"> What is learnable upsampling? How does it work? Why do we call it transpose convolution?  </summary>
    
    \

</details>


6. <details markdown=1><summary markdown="span">  What are common challenges of semantic segmentation? </summary>
    
    \

</details>

### Recall questions on object detection

1. <details markdown=1><summary markdown="span"> What is a basic implementation of single objection detection? </summary>
    
    \
    

</details>


2. <details markdown=1><summary markdown="span"> Why do we need a region proposal algorithm for multiple objects detection?  What are the ideal criteria we want to satisfy with this algorithm? </summary>
    
    \
    

</details>


3. <details markdown=1><summary markdown="span"> Briefly describe the idea behind selective search? </summary>
    
    \
    

</details>


4. <details markdown=1><summary markdown="span"> What is the R-CNN model? What is its main drawback? </summary>
    
    \
    

</details>


5. <details markdown=1><summary markdown="span"> What is fast R-CNN? Is it equivalent to applying the convolution over each crop? </summary>
    
    \
    

</details>


6. <details markdown=1><summary markdown="span"> What are 2 ways of projecting the original regions of interest  onto the feature map? </summary>
    
    \
    

</details>


6. <details markdown=1><summary markdown="span"> What is fastER R-CNN? What tweak does it use? </summary>
    
    \
    

</details>