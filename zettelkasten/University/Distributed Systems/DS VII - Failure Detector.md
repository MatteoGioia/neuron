# Failure Detector

## Recall questions
    - WIP

## What is a failure detector 

The failure detector $D_p$ is ...

>$q \in D_p (\sigma, t) \equiv q$ is believed to be crashed at time $t$, run $\sigma$, by failure detector $D_p$

We also define ... oracle..

>crashed$(\sigma) \equiv$ set of processes which crashed in run $\sigma$

>up($\sigma) \equiv$ set of processes that have not crashed during run $\sigma$

### Desirable Properties

>Completeness: a failure detector is complete if it can detect other processes crashing
>- STRONG: $\forall \sigma \space \forall p \in crashed(\sigma) \space \forall q \in up(\sigma) \space \exists t : \forall t' > t \space p \in D_q(\sigma, t')$
>- WEAK: $\forall \sigma \space \forall p \in crashed(\sigma) \space \exists q \in up(\sigma) \space \exists t : \forall t' > t \space p \in D_q(\sigma, t')$

Completeness alone doesn't mean much, since a detector that always reports processes as crashed is complete.

>Accuracy: a failure detector is accurate if processes that are reported as crashed are actually crashed
>- STRONG: $\forall \sigma \forall t \forall p,q \in up(\sigma, t) p \notin D_q (\sigma, t)$
>- WEAK: $\forall \sigma \exist p \in up(\sigma) \forall t \forall q \in up(\sigma,t) p \notin D_q(\sigma,t)$
>- EVENTUAL STRONG: $\forall \sigma \exists t \forall t' > \forall p,q \in up(\sigma) p \notin D_q (\sigma, t')$
>- EVENTUAL WEAK: ...

The failure detector that has both strong completeness and strong is said to be perfect
- paxos can be made live with the help of such a detector, since we can build a protocol to choose a coordinator+
- in async systems, this type of failure detector does not exist

Sync system with hearbeat signal for failure detection:
- known maximum delay: strong/strong
- unkown delay (doubles with each timeout): strong/eventual strong

### Failure detectors taxonomy

|  | Str | Weak | even. Str | even. Weak|
|---|---|---|---|---|
|Str| Perfect | Strong | even. Perfect| even. Strong|
|Weak| Weak | $\Theta$ | even. weak | even. $\Theta$ |

We can simulate strong detectors with weak ones by broadcasting info on which process has crashed to the whole system.