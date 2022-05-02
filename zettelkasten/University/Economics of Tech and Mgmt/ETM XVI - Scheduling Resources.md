# Scheduling resources and costs

### Recall questions

1. <details markdown=1><summary markdown="span">Why is it imporant to schedule resources and costs?</summary>

    \
	Because ==until resources are not assigned, project network times are not a schedule==. Cost estimates ==can't also be considered a budget until they have been time-phased==.
	
</details>

2. <details markdown=1><summary markdown="span"> What is the difference between resource smoothing and resource constrained scheduling?</summary>

    \
	Resource ==smoothing: using slack to even out adequate resources== over the time span of the project. \
	Resource ==constrained scheduling: delay late start of some tasks== if the resources are not adequate.
	
</details>

3. <details markdown=1><summary markdown="span">How do we understand if a project is resource or time constrained?</summary>

    \
	First of all, we can use a ==priority matrix==, as seen in [[ETM X - Understanding Strategy]]
	In general, ==one of the 2 items will be fixed, while the other will be flexible.==
	
</details>

4. <details markdown=1><summary markdown="span"> What are the assumptions made when scheduling? What about risk?</summary>

    \
	General assumptions:
	- ==no splitting activities==
	- ==nr. of resources for an activity cannot be changed==
	
	Assumptions on risk:
	- activities with ==least slack pose the least risk==
	- ==reduction of flexibility does not increase risk==
	- ==nature of an activity does not increase risk==
	
</details>

5. <details markdown=1><summary markdown="span">What is the scheduling technique used for time constrained projects? And for resoruce constrained projects?</summary>

    \
	In the case of ==time constrained==, the ==leveling== approach is preferred. In case of ==resource constrained==, the use of ==heuristics like minimum slack or smallest duration== are used.
	
	
</details>

6. <details markdown=1><summary markdown="span"> What is the parallel method and why is it not ideal? What can be used instead?</summary>

    \
	The parallel methods ==consists in iteratively applying the three rules to decide which heuristics to apply.== The issue is that ==it often changes the structure of project schedule==,== up to the point that sometimes even the critical path may change. \
	If ==startup and shutdown costs are low, splitting activities is preferred.==
	
	![](../../../static/ETM/sr1.png)
	
</details>

7. <details markdown=1><summary markdown="span">What are possible ways of handling multiple projects (in the context of scheduling)?</summary>

    \
	Managing multiproject scheduling:
	- create ==departments that oversee the global scheduling of resources across projects==
	- ==outsourcing some projects==
	- consider ==all projects as part of a mega-project==
	- use ==priority systems for resources==, i.e. FIFO
	
</details>