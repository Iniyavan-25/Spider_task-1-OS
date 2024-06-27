#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a process
struct Process {
    int pid; 
    int burstTime; 
};


void findWaitingTime(vector<Process>& processes, vector<int>& waitingTime) {
    waitingTime[0] = 0;

    for (int i = 1; i < processes.size(); i++) {
        waitingTime[i] = processes[i-1].burstTime + waitingTime[i-1];
    }
}

void findTurnAroundTime(vector<Process>& processes, vector<int>& waitingTime, vector<int>& turnAroundTime) {
    for (int i = 0; i < processes.size(); i++) {
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void findAverageTime(vector<Process>& processes) {
    int n = processes.size();
    vector<int> waitingTime(n), turnAroundTime(n);

    findWaitingTime(processes, waitingTime);

    findTurnAroundTime(processes, waitingTime, turnAroundTime);

    cout << "Processes  " << "Burst time  " << "Waiting time  " << "Turn around time\n";

    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << "   " << processes[i].pid << "\t\t" << processes[i].burstTime << "\t    " << waitingTime[i] << "\t\t    " << turnAroundTime[i] << endl;
    }

    cout << "Average waiting time = " << (float)totalWaitingTime / (float)n << endl;
    cout << "Average turn around time = " << (float)totalTurnAroundTime / (float)n << endl;
}

int main() {
    vector<Process> processes = {{1, 10}, {2, 5}, {3, 8}};
    
    findAverageTime(processes);
    
    return 0;
}
