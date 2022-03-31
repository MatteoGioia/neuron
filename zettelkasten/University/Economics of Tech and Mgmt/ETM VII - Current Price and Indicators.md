# Current Price, Indicators

### Recall questions

Also see:
- formula for compound interest
- present value formula 

1. <details markdown=1><summary markdown="span"> What is discounting?</summary>

    \
    Process of ==computing the present value (unknown) given the future value==.

</details>

2. <details markdown=1><summary markdown="span"> What is an annuity?</summary>

    \
    ==Investment that involves an identical series of cash flows at the end of each year==.

</details>

3. <details markdown=1><summary markdown="span"> What is the formula for net present value? What happens if NPV is 0, > 0 or < 0? </summary>

    \
    Formula for NPV $= \sum_{t=0}^N \frac{F_t}{(1+r)^t}$ \
    We begin the project only if NPV is $\geq 0$.

</details>

4. <details markdown=1><summary markdown="span"> How do we compute the NPV(A+B), e.g. 2 projects?</summary>
    
    \
    It is simply the sum of the 2 NPVs.

</details>

5. <details markdown=1><summary markdown="span">  What is payback time? When do we accept a project?</summary>
    
    \
    Another ==indicator==. We accept a project if $PBT > 0$. \
    $PBT$ is computed as $\sum_{t=0}^{PBT} F_t$

</details>

6. <details markdown=1><summary markdown="span"> What is discounted PBT? What is the difference with PBT? When is a project accepted?</summary>
    
    \
    Formula for DPBT $= \sum_{t=0}^{DPBT} \frac{F_t}{(1+r)^t}$, accept only if $DPBT <$ ==cutoff== period. \
    It is better because ==it takes into account the opportunity cost, however it still does not consider the lifetime of the project==. 

</details>

7. <details markdown=1><summary markdown="span">  What is internal rate of return? Why is it different from cost opportunity of capital?</summary>
    
    \
    Formula is DPBT $= \sum_{t=0}^{DPBT} \frac{F_t}{(1+IRR)^t}$
    If $IRR >$ cost opportunity of capital we accept the project. \
    Note that ==$IRR$ is a profitability measure, while opportunity cost of capital is a profitability standard==.

</details>

8. <details markdown=1><summary markdown="span"> What are possible issues of IRR? Can we fix some of them?</summary>
    
    \
    Issues:
    - ==debt or investement== (sign of flows)
    - ==multiple values== 
    - ==dimension of investment==: to fix, use the IRR associated to the difference of 2 projects (incremental flow)
    - what is the discount rate to compare with $IRR$?

</details>

9. <details markdown=1><summary markdown="span"> What is profitability index? Can we always use it?</summary>
    
    \
    Computed as $\frac{NPV}{Initial investment}$, we accept the project is $PI > 0$.
    ==If we have more than one resource that is rationed (e.g. money to invest on multiple projects), we must compute a weighted average==.


</details>