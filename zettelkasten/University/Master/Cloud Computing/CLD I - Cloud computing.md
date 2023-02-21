# Intro to cloud computing

### Recall questions


1. <details markdown=1><summary markdown="span"> What are the most relevant technologies for CC? </summary>
    
    \
    Techs:
    - ==Virtualization==: hardware (VMs) or software/application (containers)
    - ==Web 2.0==: platform for web applications like Google Docs
    - ==Service orientation==: design paradigm for computer software in the form of services

</details>


2. <details markdown=1><summary markdown="span"> What are the 3 business drivers of CC? Briefly explain each of them. </summary>
    
    \
    Business drivers:
    - ==capacity planning==: provide the right capacity when needed, the strategy can be ==lag==, ==lead== or ==match==;
    - ==cost reduction==: mostly the cost for personnel mantaining the infrastructure;
    - ==organizational agility==

</details>

3. <details markdown=1><summary markdown="span"> What is the NIST definition of cloud computing? </summary>
    
    \
    Model for enabling ==ubiquitous, convenient, on-demand network access to a shared pool of computing resources== that can be rapidly provisioned and released with minimal management/interaction.

</details>

4. <details markdown=1><summary markdown="span"> What are the 5 essential characteristics of cloud computing?</summary>
    
    \
    Characteristics:
    - on demand self-service: user can satisfy his needs on his own whenever needed;
    - broad network access;
    - resource pooling;
    - rapid elasticity
    - measured services

</details>

5. <details markdown=1><summary markdown="span"> What is resource pooling? </summary>
    
    \
    ==Computing resources are pooled to serve customers in a multi-tenant model==. This model is possible through virtualization.

</details>

6. <details markdown=1><summary markdown="span"> What is the difference between multi-tenance and virtualisation? Why are the terms sometimes used interchangeably? </summary>
    
    \
    ![](../../../CLD/cld1.png) \
    Sometimes multitenancy can be also be used to refer to users using their own virtualised environment running on the same bare metal.
    
</details>

7. <details markdown=1><summary markdown="span"> What is rapid elasticity? </summary>
    
    \
    It is another way of naming ==scalability==, the ==degree to which a system is able to adapt to workload changes in an automatic manner==,
    such that the available resources match the current demand.

</details>

8. <details markdown=1><summary markdown="span"> What is the meaning of measured services? </summary>
    
    \
    ==Ability for both the customer and the cloud provider to measure various aspects of services offered==.

</details>

9. <details markdown=1><summary markdown="span"> What are the possible service models? </summary>
    
    \
    Service models:
    - ==IaaS==: only the infrastructure is provided
    - ==PaaS==: the infrastructure and platforms to deploy apps are provided;
    - ==SaaS==: everything is already configured: infrastructure, platforms and the app themselves.

</details>

10. <details markdown=1><summary markdown="span"> What are the possible deployment models? </summary>
    
    \
    Deployment models:
    - ==public==
    - ==private==: e.g. google VPC
    - ==hybrid==
    - ==community==: the cloud service is provided to a specific community

</details>

11. <details markdown=1><summary markdown="span"> What are the roles in the cloud architecture? What is the role of the auditor, broker and carrier? </summary>
    
    \
    ![](../../../CLD/cld2.png) \
    Important roles:
    - ==auditor==: verifies the authenticity/quality of the services provided;
    - ==broker==: intermediate between provider and consumer, turns high level requests into specific services required to a provider;
    - ==carrier==: provides connectivity and transport between customer and provider.

</details>

12. <details markdown=1><summary markdown="span"> What is the cloud service owner? Is it the same as the administrator? </summary>
    
    \
    ==Legal owner of the cloud platform. Not necessarily the admin==. The legal owner is also a "user" himself of the cloud service, in a sense.

</details>