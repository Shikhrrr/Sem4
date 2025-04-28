#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int burstTime;
    int priority;
};

bool compareByPriority(const Process &a, const Process &b) {
    return a.priority > b.priority;
}

void priorityScheduling(vector<Process> &processes) {
    sort(processes.begin(), processes.end(), compareByPriority);

    int n = processes.size();
    vector<int> waitingTime(n, 0);
    vector<int> turnAroundTime(n, 0);

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    cout << "PID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].priority << "\t\t"
             << processes[i].burstTime << "\t\t" << waitingTime[i] << "\t\t"
             << turnAroundTime[i] << "\n";
    }

    double avgWaitingTime = 0, avgTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnAroundTime += turnAroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnAroundTime /= n;

    cout << "\nAverage Waiting Time: " << avgWaitingTime << "\n";
    cout << "Average Turnaround Time: " << avgTurnAroundTime << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time and priority for process " << i + 1 << ": ";
        cin >> processes[i].burstTime >> processes[i].priority;
        processes[i].pid = i + 1;
    }
    
    priorityScheduling(processes);

    return 0;
}
