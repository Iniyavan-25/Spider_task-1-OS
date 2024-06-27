# Spider_task-1-OS
# Process Scheduling: Waiting Time and Turnaround Time

## Waiting Time

**Definition**: Waiting time is the total time a process spends in the ready queue waiting to be executed. It does not include the time taken for the process to execute (i.e., the burst time).

**Calculation**: 
- For a given process, waiting time is calculated as the sum of the burst times of all previous processes.
- In the FIFO (First In, First Out) scheduling, the waiting time for the first process is always zero because it does not have to wait.
- For subsequent processes, the waiting time is the sum of the burst times of all preceding processes.

## Turnaround Time

**Definition**: Turnaround time is the total time taken from the submission of a process to the completion of the process. It includes both the waiting time and the burst time (execution time).

**Calculation**:
- Turnaround time for a process is the sum of its burst time and its waiting time.
- It represents the total time a process takes to get executed after it is submitted.






