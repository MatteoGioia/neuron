# Failure Detector

## Recall questions
    - How do we define a failure detector? Does each process have one? (hint: global = union of local) 
    - Are failure detectors always accurate?
    - What are the sets "crashed" and "up"?
    - What are 2 desirable properties of failure detectors? Why we want them both?
    - Why do we define eventual accuracy?
    - Explain the taxonomy of failure detectors. What is a reduction and why is useful?
    - Give an example of strong/strong and a strong/even.strong fd in a synchronous system.
    - Can we make paxos live with a strong fd? Why or why not?

## What is a failure detector 

The ==failure detector $D_p$ is a distributed oracle that give hints about failure patterns==. ==Each process $p_i$ has its own local failure detector $D_i$==. For each $p_i$, we say that another ==process $q$ is believed to be crashed== when:

>$q \in D_p (\sigma, t) \equiv q$ is believed to be crashed at time $t$, run $\sigma$, by failure detector $D_p$

We also ==define the set of processes that have crashed/not crashed as:==

>crashed$(\sigma) \equiv$ set of processes which crashed in run $\sigma$

>up($\sigma) \equiv$ set of processes that have not crashed during run $\sigma$

Notice ==that a process can be mistakenly inserted in the crashed ones and removed later== if the $D_p$ is proven otherwise (e.g. receives a signal).

### Desirable Properties

>Completeness: there is a time after which every process that has crashed is permanently suspected by a correct process

![](../../../DS/fd1.png)

==Completeness alone doesn't mean much though, since a detector that always reports processes as crashed is complete==.
For this reason, we also define accuracy.

>Accuracy: there is a time after which a correct process is never suspected by any correct process

![](../../../DS/fd2.png)

Both ==strong and weak accuracy are difficult to achieve==, as they require a correct process to be never suspected but, as we said, it is not uncommon for a correct process to be suspected and then removed.

For this reason, we ==define eventual accuracy==, so that is enough that the accuracy will be eventually satisfied.

>Eventual accuracy: We need not require accuracy property to be satisfied by each process at all the time. Instead, we require the accuracy property to be eventually satisfied

![](../../../DS/fd3.png)

### Taxonomy of failure detectors

| C/A | Str | Weak | even. Str | even. Weak|
|---|---|---|---|---|
|Str| Perfect | Strong | even. Perfect| even. Strong|
|Weak| $\Theta$ | Weak | even. $\Theta$ |  even. weak |

==Paxos can be made live with the help of a perfect detector==, since we can build a protocol to ==choose a coordinator==
- in ==async systems, this type of failure detector does not exist :(==

==Synchronous system with hearbeat signal== for failure detection:
- known maximum delay: strong/strong
- unkown delay (doubles with each timeout): strong/eventual strong

We can simulate strong detectors with weak ones by broadcasting info on which process has crashed to the whole system. 

==Generally, a failure detector $D$ is reducible into another failure detector $D'$ if there exists a distributed algorithm that can transform $D$ into $D'$.==