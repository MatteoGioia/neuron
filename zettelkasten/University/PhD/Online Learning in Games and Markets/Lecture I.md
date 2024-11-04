### Lecture recap

Key concepts of online learning:
- ....
- ....

### Key introductory concepts

Algorithmic loop:
1. TBA

Adversary types:
- **stochastic**: reward picked from i.i.d
- **adversarial**: can be **oblivious** or **adaptive** (w.r.t to past actions)

Possible metrics:
- **sum** of rewards over time
- **minimise regret** with best possible reward

Feedback types:
- **full**: see each reward associated with the actions
- **bandit**: see only the reward associated with the chosen action

### Stochastic model

Formulation of the model:

Goal : make regret **sublinear**, i.e. the average regret tends to 0 over time.

**Follow the leader algorithm**: after observing a full set of rewards at a certain time $T$, pick the action with the highest reward for time $T+1$.  