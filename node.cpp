//
// Created by hasib on 9/27/22.
//

#include "node.h"
node ::node() {
    next = nullptr;
    previous = nullptr;
    leftOverExec = nullptr;
    pId = -1;
    period = -1;
    brustTime = -1;
    // tells us when we have to execute this process
    nextExecTime = 0;
}

