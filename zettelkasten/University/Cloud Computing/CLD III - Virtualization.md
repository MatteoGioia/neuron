# Virtualization

### Recall questions


1. <details markdown=1><summary markdown="span"> What are 3 main characteristics of virtualization environments? </summary>
    
    \
    Characteristics:
    - ==increased secuirity==
    - ==managed execution==
    - ==portability==: e.g. of code (JVM), containers, etc..

</details>

2. <details markdown=1><summary markdown="span"> What are potential harmful activities that become harder in a VM? </summary>
    
    \
    Harmful activities that are ==still possible but harder==:
    - DDoS on machine resources
    - stealing sensitive data

</details>

3. <details markdown=1><summary markdown="span"> What are examples of managed execution? </summary>
    
    \
    Examples:
    - ==sharing==
    - ==aggregation==
    - ==emulation==
    - ==isolation==

</details>

4. <details markdown=1><summary markdown="span"> Explain the machine reference model used to discuss virtualization. </summary>
    
    \
    ![](./static/CLD/virt1.png)

</details>

5. <details markdown=1><summary markdown="span"> What is the difference between priviliged and non priviliged operations? </summary>
    
    \
    ==Non priviliged==: can be used without interefering with the system \
    ==Priviliged==:
    - behaviour sensitive instructions on the I/O
    - control sensitive instructions on the CPU registers
   
</details>

6. <details markdown=1><summary markdown="span"> What is an hypervisor? What are its privileges? </summary>
    
    \
    It is a ==process that runs on top of the supervisor==. While in theory it runs "on top" of the supervisor, it effectively ==runs in supervisor mode==.
    ![](./static/CLD/virt2.png) \
    Note that most modern systems work with only ring 0 and ring 3.

</details>

7. <details markdown=1><summary markdown="span"> What are the possible meanings of VMM? </summary>
    
    \
    It can mean:
    - Virtual machine manager (hypervisor)
    - Virtual machine monitor (hypervisor)
    - Virt manager, a library
   
</details>

8. <details markdown=1><summary markdown="span"> What are 2 possible types of hypervisors? </summary>
    
    \
    ![](./static/CLD/virt3.png) \
    Type 1 hypervisors can work using the native virtualization capabilites of the OS, Type 2 are applications that manage the VMs not using the OS capabilites.
   
</details>

9. <details markdown=1><summary markdown="span"> What is the structure of a hypervisor? What the 3 main components </summary>
    
    \
    ![](./static/CLD/virt4.png) \
    Components:
    - dispatcher: entry point
    - allocator: for resources
    - interpreter: executes priviliged instructions in place of the VM
   
</details>

10. <details markdown=1><summary markdown="span"> What are 3 necessary properties of VMM? What is their meaning? </summary>
    
    \
    Properties:
    - equivalence: a guest should expect the same behaviour as if he were using a physical host
    - resource control: the VMM should be in complete control of the virtualized resources
    - efficiency: most of the VM instructions should be executed without intervention of the VMM

</details>

11. <details markdown=1><summary markdown="span"> How does full virtualization work? </summary>
    
    \
    In full virtualization:
    - noncritical instruction are run on the hardware
    - privileged instructions are emulated by the VMM with binary translation

</details>

12. <details markdown=1><summary markdown="span"> What are 2 possible types of binary translation? What is the difference? </summary>
    
    \
    Two types:
    - static: converts the entirety fo the code without running it first
    - dynamic
   
</details>

13. <details markdown=1><summary markdown="span"> What are examples of hardware assisted virtualization? </summary>
    
    \
    ...
   
</details>

14. <details markdown=1><summary markdown="span"> How does paravirtualization work?  What are the pros/cons?</summary>
    
    \
    Paravirtualization is ==non transparent== form of virtualization. Paravirtualized OS's replace non virtualizable instructions with hypercalls. while other instructions pass directly.
    
</details>

15. <details markdown=1><summary markdown="span"> What is VM migration? What are 2 possible scenarios? </summary>
    
    \
    Two scenarios:
    - offline migration
    - live migration: no service discontinuity
   
</details>

16. <details markdown=1><summary markdown="span"> How does live migration work? </summary>
    
    \
    Steps:
    1. migration starts
    2. the memory is copied and transferred
    3. the original VM is stopped and the last portion of the data is copied
    4. execution resumes on the new machine

    ![](./static/CLD/virt5.png) 
   
</details>