// Operating Systems Homework 1
// January 8 2018
// Matthew Tilton

#include <stdio.h>
#include <stdlib.h>

// these are the only things that are neccesary for this assignment
// WT and TAT are calculated as needed and PID is just the index in the array
struct process {
    int completionTime; // used
    int arrivalTime;// used
    int burstTimeRemaining; // used
};

int FCFS() {
    int processBurstTimes[10] = {255, 850, 80, 155, 800, 125, 75, 555, 90, 450};
    struct process processes[10];
    int currentTime = 0;
    while (currentTime < 20000) {
        //adds processes to list
        if (currentTime < 10) {
            struct process newProcess;
            newProcess.arrivalTime = currentTime;
            newProcess.burstTimeRemaining = processBurstTimes[currentTime];
            processes[currentTime] = newProcess;
        }

        //subtracts time from the first proccess in the list that is not done, since the process list is already in order of arrival this is all that is neccesary
        for (int i = 0; i < 10; i++) {
            if (processes[i].burstTimeRemaining > 0) {
                processes[i].burstTimeRemaining = processes[i].burstTimeRemaining - 1;
                if (processes[i].burstTimeRemaining == 0) {
                    processes[i].completionTime = currentTime;
                }
                break;
            }
        }

        int flag = 0; // flag to see if we're done
        // sets the flag if no processes are found with time remaining
        for (int i = 0; i < 10; i++) {
            if (processes[i].burstTimeRemaining == 0) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        currentTime = currentTime + 1;
    }

    //calculates averages
    int totalWaitTime = 0;
    int totalTAT = 0;
    for (int i = 0; i < 10; i++) {
        int TAT = (processes[i].completionTime - processes[i].arrivalTime);
        totalTAT = totalTAT + TAT;
        int waitTime = TAT - processBurstTimes[0];
        totalWaitTime = totalWaitTime + waitTime;
    }
    printf("FCFS Average wait time: %d\n", (totalWaitTime/10));
    printf("FCFS Average turn around time: %d\n", (totalTAT/10));
}

int SJF() {
    int processBurstTimes[10] = {255, 850, 80, 155, 800, 125, 75, 555, 90, 450};
    struct process processes[10];
    int currentTime = 0;
    while (currentTime < 20000) {
        //adds processes to list
        if (currentTime < 10) {
            struct process newProcess;
            newProcess.arrivalTime = currentTime;
            newProcess.burstTimeRemaining = processBurstTimes[currentTime];
            processes[currentTime] = newProcess;
        }

        //finds the shortest process
        int shortest = 9999999;
        for (int i = 0; i < 10; i++) {
            if (processes[i].burstTimeRemaining > 0) {
                if (shortest <= 10) {
                    if (processes[i].burstTimeRemaining < processes[shortest].burstTimeRemaining) {
                        shortest = i;
                    }
                } else {
                    shortest = i;
                }
            }
        }

        // all processes had burstTimeRemaining <= 0;
        if (shortest == 9999999) {
            break;
        }

        processes[shortest].burstTimeRemaining = processes[shortest].burstTimeRemaining - 1;
        if (processes[shortest].burstTimeRemaining == 0) {
            processes[shortest].completionTime = currentTime;
        }

        currentTime = currentTime + 1;
    }

    //calculates averages
    int totalWaitTime = 0;
    int totalTAT = 0;
    for (int i = 0; i < 10; i++) {
        int TAT = (processes[i].completionTime - processes[i].arrivalTime);
        totalTAT = totalTAT + TAT;
        int waitTime = TAT - processBurstTimes[0];
        totalWaitTime = totalWaitTime + waitTime;
    }
    printf("SJF Average wait time: %d\n", (totalWaitTime/10));
    printf("SJF Average turn around time: %d\n", (totalTAT/10));
}

void main() {
    FCFS();
    SJF();
}