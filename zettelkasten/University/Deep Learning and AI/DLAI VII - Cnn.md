# Convolutional Neural Network

### Recall questions

1. <details markdown=1><summary markdown="span"> What is a way to deal with the instrisic complexity of DNN?  </summary>
    
    \
    We can look for ==universal priors== that ==are task indipendent==.

</details>

2. <details markdown=1><summary markdown="span"> Which universal priors are we referring to? What do they mean?</summary>
    
    \
    Universal priors:
    - ==structural priors==: i.e. the structure of a protein;
    - ==self similiarity== across the domain: i.e. two halves of an object;
    - ==translation invariance==: invariance w.r.t to the position in the image.

</details>

3. <details markdown=1><summary markdown="span"> What does the translation operation do? Why is it tricky? Is it still linear? </summary>
    
    \
    The operator is defined as $T_v \ f(x) = f(x-v)$. We say it's "tricky" because ==the operator does not really moves the point: it just returns the location of the point in the original location==. \
    As a matter of fact, it is ==applied to the function itself and its linear w.r.t. to the function==.
    

</details>

4. <details markdown=1><summary markdown="span"> What is translational invariance? Why is it desirable? </summary>
    
    \
    We define it as: $C(T_v \ f) = C(f) \ \forall f,T_v$. In other words, ==we say that the classification for an object is the same wether it's translated from its original position or not==. \
    Note that ==this is not the only type of invariance==.


</details>

5. <details markdown=1><summary markdown="span"> How do we express translation invariance across multiple scales? Again, why is this desirable? </summary>
    
    \
    We define it as $z(T_v \ p) = z(p) \ \forall p, T_v$. \
    This is desirable ==because data is often composed of hierarchical, local, shift-invariant patterns== and ==CNNs exploit this fact as a prior==.

</details>


6. <details markdown=1><summary markdown="span"> What is the formal definition of convolution? Is it commutative? </summary>
    
    \
    ![](../../../static/DEEP/cnn1.png) \
    Yes, we can prove the convolution is commutative:
    ![](../../../static/DEEP/cnn2.png)
    

</details>

7. <details markdown=1><summary markdown="span"> What does it mean that convolution is shift equivariant? Why is this property so important? </summary>
    
    \
    A convolution is ==shift equivariant if $f(x-x_0) \star g(x) = (f \star g) (x - x_0)$==. \
    It is really important because ==equivariance is a defining property of convolutions, and any linear operator that is shift equivariant is a convolution==.

</details>

8. <details markdown=1><summary markdown="span"> Prove the linearity of the convolution. </summary>
    
    \
    ![](../../../static/DEEP/cnn3.png)
    

</details>

9. <details markdown=1><summary markdown="span"> How is convolution expressed in the linear setting? </summary>
    
    \
    We can express it as $(f \star g)[n] = \sum_{k = - \infty}^{\infty} f[k]g[n-k]$. Note that since we are in the discrete setting, we have a summation and no longer an integral.

</details>

10. <details markdown=1><summary markdown="span"> What is padding and why is it necessary? </summary>
    
    \
    In order for all the shift of the convolution to be well defined.

</details>

11. <details markdown=1><summary markdown="span"> How is 2-d convolution expressed? </summary>
    
    \
    We can express it as $(f \star g)[m,n] = \sum_k \sum_l f[k,l]g[m-k, n-l]$
    

</details>

13. <details markdown=1><summary markdown="span"> What are possible choices for padding/stride? </summary>
    
    \
    While there can be multiple choices, we can for instance do:
    - no padding
    - full zero padding 
    - arbitrary zero padding and stride
    - and so on...
    

</details>

14. <details markdown=1><summary markdown="span"> What is the efficiency gained when using small filters? What is weight sharing and what notion does it implement? </summary>
    
    \
    We now have ==only $O(1)$ parameters per filter==, which is a huge gain compared to MLP. This filter weights are applied across the whole image (weight sharing), and this ==implments the notions of self-similarity and shift-equivariance==.


</details>

15. <details markdown=1><summary markdown="span"> What is pooling?  Why is it applied?</summary>
    
    \
    Pooling ==allows to caputer complicated non local interaction==.
    In simpler terms, given the fact that we know that images have a hierarchical structure, we can progressively "abstract" the local details in favour of the global ones.

</details>

