//
// Created by hasib on 8/2/23.
//

#ifndef LAB9_10_RMS_H
#define LAB9_10_RMS_H

#include "linked_list.h"

class rms {
    double averageWaiting;
    // contains jobs arranged in the order of execution
    linked_list executionQueue;
    int totalProcess;
    // contains all processes that are willing to be executed
    linked_list readyQueue;

    // variable that help us to know where we are in time

    int timer;

public:

    rms();
    ~rms();
    // shall be called as main wrapper and driver function
    void simulate();

    // after performing one task this queue shall be updated so that
    // it has those shortest job on the front that became ready while execution of
    // previous task.

    void updateQueue();

    // takes input of all jobs, this part is unreal for the actual cases do not have prior
    // info of all jobs
    void takeInput();

    // this function shall execute jobs and shall be iterating the inputArray and calling updating queues
    void executeJobs();

    void executeProcess();

    // called when there is enought time to execute a process
    void executeProcessCompletely(node *);

    // called when we have to save the states and execute the process partially
    void executeProcessPartially(node *,int);

    // called before executing any process to calculate the anticipated ending time
    // and to allot a time slice to process and to calculate the ending time
    void beginExecution(node *);

    void headRtoE();



};


#endif //LAB9_10_RMS_H
