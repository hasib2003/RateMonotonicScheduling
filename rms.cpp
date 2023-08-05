//
// Created by hasib on 8/2/23.
//

#include "rms.h"
//
// Created by hasib on 7/23/23.
//

#include <iostream>
rms ::rms() {

    totalProcess = 0;
    timer = 0;
    averageWaiting = 0;
}

void rms ::simulate() {

    takeInput();
    executeJobs();
}

void rms :: takeInput(){
    // first we shall take input from user
// inreal cases we can traverse queue for this purpose

    printf("Enter total number of processes ");
    scanf("%d",&totalProcess);

    int temp  = 1;
    int i = 0;

    for (;i<totalProcess;i++){
        node * iterator = new node();

        iterator->pId  = i;
        std::cout << "Enter the information about process with id " << i << "\n";
        std::cout << "Burst time in milliseconds (can only be an integer): ";
        std::cin>>iterator->brustTime;
        int temp;
        std::cout << "Period in milliseconds (can only be an integer): ";
        std::cin >> temp;
        while(temp < iterator->brustTime){
            std::cout << "Enter again Period in milliseconds (can only be an integer and greater than or equal to the brust time): ";
            std::cin >> temp;
        }
        iterator->period = temp;
        readyQueue.InsertAtLast(iterator);


    }
}

void rms ::executeJobs() {

    // updating the execution queue
    updateQueue();

    beginExecution(executionQueue.start);

}



void rms ::updateQueue() {

        // this function updates the execution queue in the form of
        // a doubly linked list that has priority wise arrangement


    node * temp = readyQueue.start;
    while (temp){
            // inserting it into sorted position in execution queue.
            readyQueue.start = readyQueue.start->next;
            executionQueue.InsertSorted(temp);
            // removing the job from the ready queue
            temp = readyQueue.start;

        }

    }

void rms ::beginExecution(node * process) {

    if(process) {
        int anticipatedEndingTime = 0;

        // checking if previously the process was completely executed or not

        if (!process->leftOverExec) {
            anticipatedEndingTime = timer + process->brustTime;

        }
        else {
            anticipatedEndingTime = timer + process->leftOverExec->remainingBrustTime;
            // we can load necessary states here and then

        }

        // checking if we have any high priority process waiting in ready queue
        // processes in the ready queue will also be arranged according to their priority
        // so if the first has not to be executed then we do not need to check others

        node *readyQStart = readyQueue.start;
        if (readyQStart) {
            //checking if we need to execute this process now
            if (readyQStart->nextExecTime == timer) {
                // call to a function that will update the execution queue
                // by moving the head from ready to execution
                headRtoE();

                // resume the execution
                beginExecution(executionQueue.start);
                return;

            }
                // else we have permission to start the execution of the
                // process at the start position in execution queue
                // but, we are not sure if it has to be executed completely or partially
            else if (anticipatedEndingTime <= readyQStart->nextExecTime) {
                // call to a function that can execute it safely and remove
                // it from execution and move to ready
                executeProcessCompletely(process);
                beginExecution(executionQueue.start);



            } else if (anticipatedEndingTime > readyQStart->nextExecTime) {
                // call to a function that will execute it partially and then
                // call some function to add the start of ready queue into the
                // execution queue
                executeProcessPartially(process, readyQStart->nextExecTime);
                beginExecution(executionQueue.start);

            }
        }
        else {
            executeProcessCompletely(process);
            beginExecution(executionQueue.start);
        }
    }
    else{
        std::cout<<"Idle wait"<<std::endl;
        std::cout<<"Start Time "<<timer<<std::endl;
        if(readyQueue.start){
            timer = readyQueue.start->nextExecTime;
        }
        std::cout<<"End Time "<<timer<<std::endl;
        //beginExecution(executionQueue.start);
        // just uncomment above line to make execution continous and
        // non stop
        return;

    }
}


void rms::executeProcessPartially(node * process,int stoppingTime) {

    std::cout<<"Executing partially p"<<process->pId<<std::endl;
    std::cout<<"Start Time "<<timer<<std::endl;
     // two possible situations
     //1   when it is the first time partial execution
    if(!process->leftOverExec){
        partialNode * temp = new partialNode();
        process->leftOverExec = temp;
        process->leftOverExec->remainingBrustTime = process->brustTime - (stoppingTime - timer);

    }  //2
    else{
        process->leftOverExec->remainingBrustTime -= (stoppingTime - timer);

    }

    timer = stoppingTime;
    std::cout<<"End Time "<<timer<<std::endl;
}

void rms::executeProcessCompletely(node *process) {


    std::cout<<"Executing p"<<process->pId<<std::endl;
    std::cout<<"Start Time "<<timer<<std::endl;

    // we also have two possible situations here

    // 1 process did not go under fragmentation
    if(!process->leftOverExec){
        timer = timer + process->brustTime;
    }
    else{
        timer = timer + process->leftOverExec->remainingBrustTime;
    }
    process->nextExecTime += process->period;


    std::cout<<"End Time "<<timer<<std::endl;

    // after execution, we have removed the process from execution
    // and have added it back to ready queue
    executionQueue.start = executionQueue.start->next;
    readyQueue.InsertSorted(process);

    if(process->leftOverExec){
        delete process->leftOverExec;
        process->leftOverExec = nullptr;
    }



}


void rms::headRtoE() {
    node * temp = readyQueue.start;

    readyQueue.start = readyQueue.start->next;
    if(readyQueue.start){
        readyQueue.start->previous = nullptr;
    }

    executionQueue.InsertSorted(temp);
//
//    temp->next = executionQueue.start;
//    if(executionQueue.start){
//        executionQueue.start->previous = temp;
//    }
//    executionQueue.start = temp;

}

rms::~rms(){
    std::cout<<" **happy**coding** "<<std::endl;
}