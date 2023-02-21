# Reinforcement learning

## Recall questions
        - What is the main point of RL models? How can you summarise what they do?
        - What is online learning? Why the outcome of a decision is not always immediately clear?
        - What are rewards and the reward hypotesis?
        - What is the exploration exploitation dilemma?
        - Describe the model in use.
        - What is the history? What is a state? Why the agent's state could be different from the environment's?
        - What are the components of a RL agent?

## Intro to RL 

We already addressed a complicated use case of WSN: a smart home where each device can transmit and be queried for information. In this scenario, multiple devices have to share the same channel and each has to be able to send its data in different intervals. 

In the following, we are going to see reinforcement learning methodologies that can allow us to create protocols to deal with similar situations, so we are going to ==apply RL to networking.==

### Goal of RL and characteristics

The ==main point of RL models is that they:==
>Learn to make good sequences of decisions

3 key aspects:
- the ==agent learns by acquiring experience in the target environment==
- we ==focus on sequences of decisions, not a single one==
- ==goodness of decisions is measured through some utility==

What RL models do can be summarized as ==goal-directed learning from interaction==. 

### Online learning

When we deal with RL, there is ==no predetermined best behaviour. In fact, RL agents are said to learn online, because they learn by trial and error.==

Furthermore, the ==total outcome of their decisions is not always immediate, since some sequences could lead to small good/bad rewards immediately but huge bad/good rewards in the long term.==

### Reward and optimization problem

Since agents must have some measure of goodness of their actions, we define ==rewards== as:
>Reward $R_t$ is a scalr feedback signal, indicating how good the agent is doing at step $t$

The focus of RL agent is to ==maximize the cumulative reward (optimization problem). In fact, RL is based on the reward hypotesis==:
>All goals can be described by the maximization of expected cumulative reward

### Exploration-exploitation dilemma

Maximizing rewards is not an easy task. While comproved strategies could consistently lead to good results, it is possibile that adopting the same strategy for a long time yields a worse final result.

In ==RL, we strive to find the balance== between:
- ==exploration== of new actions, that could be potentially better than the strategies we know
- ==exploitation== of old strategies, that we have confirmed work well

Furthermore, ==a good sequence of actions could become bad as the environment changes==, and we have to observe sequences' outcomes many times before being able to say if they're good or not.

## ==A general RL framework==

![](../../../AN/model1.png)

At each step $t$ an agent==:
- executes action $A_i$
- receives observation of the environent $O_t$
- receives a scalar reward $R_t$

The environment:
- receives action $A_t$
- emits observation $O_{t+1}$
- emits scalar reward $R_{t+1}$

### History and state

We define the ==history as the sequence of observations, actions and rewards==
- e.g. $H_t = A_1, O_1, R_1, \ldots, A_t, O_t, R_t$ 

We also define the ==state as a function of the history $S_t = f(H_t)$. The state can be used to determine 
what happens next.==

The ==environment has its own state $S_{t}^{e}$ used to choose the next observation/reward and that is invisible to the agents. The agents have their own state $S_{t}^{a}$ too.==

Depending on if the ==environemnt is fully observable or not, the agent state will coincide or be different with the environment's state.==
- in most real life situations they do not coincide

### Components of RL agent

The only way an ==agent can pick the best sequence of actions is if it keeps track of its actions and assigns some probabilities of possible rewards to parts of the sequence==. Each agent is made up of a policy, a value function and a model.

==Policy: defines the agent's behaviour at a given time in the form of a map from state to action.==
- ==can be altered through rewards==
- ==can be deterministic (function of the state) or stochastic (specifying probability of each action)==

==Value function==: used to ==predict "what is good" in the long run==. It is in fact a prediction of future rewards and it's used to evaluate the goodness of a state. 

>$v_\pi$(s) = $E_{\pi} [R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3} \ldots | S_t = s]$

==The model is the agent's inner representation of the environment==. It can predict the next event or the next reward, and it is not always present.