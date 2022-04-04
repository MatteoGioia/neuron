# Autonomic computing

### Recall questions

1. <details markdown=1><summary markdown="span"> What is autonomic computing? </summary>
    
    \
    ==Systems capable of managing themselves given high level objectives from the administrators.==

</details>

2. <details markdown=1><summary markdown="span"> What is an autonomic manager and what does it do? </summary>
    
    \
    Process (?) with the task of:
    1. ==monitoring the system==
    2. ==verify that the system is in the desired state==
    3. ==plan an action to keep/change the state and execute it==

</details>

3. <details markdown=1><summary markdown="span"> What does  MAPE-k stand for? </summary>
    
    \
    ![](./static/CLD/aco1.png)

</details>

4. <details markdown=1><summary markdown="span"> What are the 4 self-* properties of autonomic computing? Explain the meaning of each one. </summary>
    
    \
    Properties:
    - self ==configuration==: ??
    - self ==healing==: e.g. guarantee a certain number of VMs are always running;
    - self ==protection==: e.g. keep intruders out and mitigate successful attacks;
    - self ==optimization==: e.g. determine optimal amount of VMs to guarantee SLA and minimize cost.

</details>

5. <details markdown=1><summary markdown="span"> What does scalability measure? </summary>
    
    \
    ==It measures the trend of performance with increasing load==. In other words, a system is scalable if it's ==capable of mantaining performance under increased load by adding more resources==.
    ![](./static/CLD/aco2.png)

</details>

6. <details markdown=1><summary markdown="span"> Which components are needed in order to perform efficient scaling of a system? </summary>
    
    \
    Components needed in order to perform:
    - ==resource usage monitor==
    - ==scaling mechanism==
    - ==load balancer==

</details>

7. <details markdown=1><summary markdown="span"> What are 2 possible autoscaling mechanisms? (hint: grain) </summary>
    
    \
    2 possible mechanisms:
    - ==coarse grain==: replication of an ==entire application==
    - ==fine grain==: replication of an ==application component== (micro-services)

</details>

8. <details markdown=1><summary markdown="span"> What is an automated scaling listener? </summary>
    
    \
    It's the ==core component of the Dynamic Scaling Architecture==, and it decides how to perform scaling based on requests from outside.
    ![](./static/CLD/aco3.png)

</details>

9. <details markdown=1><summary markdown="span"> What are possible types of scaling? </summary>
    
    \
    Possible scaling techniques are:
    - ==out/in (vertical)==
    - ==up/down (horizontal)==
    - ==migration==

</details>

10. <details markdown=1><summary markdown="span"> What are possible autoscaling algorithms? Explain each of them. </summary>
    
    \
    Possible autoscaling algorithms:
    - ==threshold based (reactive)==
    - ==model based (reactive)==: based on ==mathematical modelling of the system==
    - ==threshold + model (proactive)==: uses ==model to predict values in the next $x$ minutes and scales if threshold is surpassed==.

</details>

11. <details markdown=1><summary markdown="span"> Explain simple scaling, step scaling and target tracking scaling. </summary>
    
    \
    ==Simple and step scaling==: defines ==how many instances to remove and which events triggers it (threshold/other)==. In the case of ==step scaling there is no cool down period==. \
    ==Target tracking scaling==: defines a ==desired value for a performance/workload metric to mantain==.

</details>

12. <details markdown=1><summary markdown="span"> What are possible scaling policies/adjustements? Make a few examples.</summary>
    
    \
    ==Change in capacity==: add vms \
    ==Exact capacity==: specify exact number of vms for each scaling action \
    ==Percent capacity==: performs scaling based on a percentage of the current nr. of vms

</details>

13. <details markdown=1><summary markdown="span"> What are aggregated metrics? </summary>
    
    \
    ==Metrics that represent the average values across the VMs==.

</details>

14. <details markdown=1><summary markdown="span"> What is a warm-up period? Why is it relevant in the context of autoscaling?</summary>
    
    \
    Period in which ==the machine is still not a full capacity==. While ==in warm up, the VM is not included by the scaling listener==.


</details>