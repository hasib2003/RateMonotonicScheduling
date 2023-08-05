//
// Created by hasib on 9/27/22.
//

#ifndef DOUBLE_LINKED_LIST_NODE_H
#define DOUBLE_LINKED_LIST_NODE_H

#include "partialNode.h"

class node {
public:
 node* next;
 node* previous;
 int pId;
 int period; // the time after which the execution has to be repeated
 int brustTime;
 partialNode * leftOverExec;
 int nextExecTime;
 node();
};








#endif //DOUBLE_LINKED_LIST_NODE_H
