**Approach:**
This program implements and demonstrates the Round-Robin Process Scheduler by using a circular linked list data structure. The processes run in turn, and each process is given a fixed amount of time on the CPU in a cycle known as quantum. The scheduler operates in cycles and during each cycle, every process is allowed to run for a certain time quantum (which in this case is three units).

This means that if a process completes before its allocated time, then it will not be in the ready queue. Otherwise, it is waited at the back of the queue for the next circulation of the cycle. It is used to monitor the remaining time for the execution of each process and halts when the last process in the program is executed.

**Key Features:**
Process Class: It stores the information related to the individual characteristics of the process which includes the ID, execution time as well as the time left for its execution.
ProcessScheduler Class: It employs circular linked list to store processes. Is used to add new processes to the list, delete the finished ones, and schedule it.
Scheduling Mechanism: The scheduler scans all processes and reduces the remaining time by the CPU quantum for each revolution. It persists until all the processes are done.

**Assumptions:**
Fixed CPU Quantum: This means that for each process in each cycle, the amount of CPU time spent is 3 time units (in this case) but it can be changed when the function is called.
Circular Linked List: The processes are maintained in the circular linked list; it guarantees that after one cycle, the next process would be selected.
Initial Processes: The initial scheduler also comes with a set of predefined processes, but can adapt to new processes that may occur in the middle of the simulation.
Completion Check: When the time required to complete a process is zero, it is not included in the circular linked list.
CPU Time Management: If the remaining time for a process is less than the quantum for the CPU, the process is completed in the current cycle.


**Challenges Faced:**
Circular Linked List Management: One of the challenges faced while implementing the project was on managing the circular linked list to facilitate the correct insertion and deletion of processes. The problem was to make sure that after deletion, the list remains circular as it should and I had to manage pointers effectively.
Dynamic Process Management: Managing the arrival of new processes in the middle of the scheduling and inclusion of the processes into the circular linked list with no interferences.
Edge Cases: Making sure that the scheduler responds appropriately in the case when there is only the first process, when the list of processes is empty, or when multiple processes complete in a single cycle.
Remaining Time Calculation: Precisely controlling the remaining time count, possibly with negative values or incorrect behaviour when the remaining time is less than the CPU time.
