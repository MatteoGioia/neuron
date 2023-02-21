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
    ![](../../../CLD/aco1.png)

</details>

4. <details markdown=1><summary markdown="span"> What are the 4 self-* properties of autonomic computing? Explain the meaning of each one. </summary>
    
    \
    Properties:
    - self ==configuration==: see ansible
    - self ==healing==: e.g. guarantee a certain number of VMs are always running;
    - self ==protection==: e.g. keep intruders out and mitigate successful attacks;
    - self ==optimization==: e.g. determine optimal amount of VMs to guarantee SLA and minimize cost.

</details>

5. <details markdown=1><summary markdown="span"> What does scalability measure? </summary>
    
    \
    ==It measures the trend of performance with increasing load==. In other words, a system is scalable if it's ==capable of mantaining performance under increased load by adding more resources==.
    ![](../../../CLD/aco2.png)

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
    ![](../../../CLD/aco3.png)

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

15. <details markdown=1><summary markdown="span"> Why are alarms needed?</summary>
    
    \
    To avoid calling for new scaling actions while other are already starting. The idea is that if ==a certain threshold is reached for an $x$ amount of time, then an alarm goes off== and a scaling action is requested.

</details>

16. <details markdown=1><summary markdown="span"> What is cloud orchestration? Make a simple example of a situtation where it's needed.</summary>
    
    \
    It is ==the process of automating the tasks needed to manage connections and operations of workloads==. In simpler terms, we might want to automatically configure remote servers (and all the parameters needed for them in order to work correctly) with minimal or no intervention.

</details>

17. <details markdown=1><summary markdown="span"> What is ANSIBLE and what is it used for?</summary>
    
    \
    ANSIBLE is ==an open source IT configuration management, orchestration and deployment tool==.

</details>

18. <details markdown=1><summary markdown="span"> What are ANSIBLE characteristics?</summary>
    
    \
    Characteristics:
    - ==agentless==: ANSIBLE does not have to be installed on the target machines
    - ==push model==: the remote management is achieved ==through pushing instructions with SSH== or ==WinRM==.

</details>

19. <details markdown=1><summary markdown="span"> What is a playbook? What language are they written in?</summary>
    
    \
    ==Prescriptive and responsive description on deployment==. Commonly ==written in YAML, they are a list of tasks which consists of ANSIBLE module calls.==

</details>

20. <details markdown=1><summary markdown="span"> What is k8s? Make a few examples of its capabilities.</summary>
    
    \
    A ==platform for managing containerised services==. With k8s is possible to:
    - do ==service discovery and load balancing==
    - ==orchestration==
    - ==automatic rollouts/rollbacks==
    - ==self healing==
    - ==automatic bin packing (clustering)==

</details>


21. <details markdown=1><summary markdown="span"> What are k8s components?</summary>
    
    \
    ![](../../../CLD/aco4.png)

</details>


22. <details markdown=1><summary markdown="span"> What are k8s objects? What can they describe? Why do we say they are a "record of intent"?</summary>
    
    \
    Persistent entities in the k8s system. They can describe:
    - ==running containerised apps==
    - ==resources available==
    - ==policies==

    Furthermore, we say they are a ==record of intent as k8s will try to keep the cluster in the state described by the objects==.


</details>


23. <details markdown=1><summary markdown="span"> What is a pod? Is it the same as a container?</summary>
    
    \
    Pods are the ==smallest deploayble units of computing, and consist of 1 or more containers==.

</details>


24. <details markdown=1><summary markdown="span"> What is a k8s node? How can they become members of a cluster</summary>
    
    \
    It is a ==virtual of physical machine and represents a member of a cluster==. To become members of a cluster, they must ==self register with the control plane API== or ==be manually added==.

</details>


25. <details markdown=1><summary markdown="span"> What are the possible states for a k8s node?</summary>
    
    \
    A few possible conditions:
    - ready
    - diskpressure
    - memory pressure
    - etc...

</details>


26. <details markdown=1><summary markdown="span"> Describe the control plane components and the node components in detail.?</summary>
    
    \
    See kubernets resorces.

</details>


27. <details markdown=1><summary markdown="span"> What is a k8s controller?</summary>
    
    \
    They are ==control loops that watch the state of a k8s cluster==, and specifically monitor at least one resource type.

</details>

28. <details markdown=1><summary markdown="span"> How does scheduling work in k8s? What's this process called? </summary>
    
    \
    In k8s ==scheduling refers to making sure that pods are matched to nodes, so that kubelets can run them==. The process is called ==Filtering and Scoring==, and terminates with ==the API communicating the decision== to the ctl plane through ==binding==.


</details>

