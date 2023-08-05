//
// Created by hasib on 9/27/22.
//

#ifndef DOUBLE_LINKED_LIST_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_LINKED_LIST_H

#include "node.h"
class linked_list {
public:
    node *start;
    node *last;
    node *loc;
    node *ploc;
linked_list();
~linked_list();







void PrintReverse();
void GroupEvenOdd();
void SwapWhere(int,int);
void ReverseDoubleLinkedList();
void SwapNodes();
bool isEmpty() const;
void printlist() const;
void Search(int);
bool isPresent(int);
void InsertSorted(node *);
void InsertAtFront(node *);
void DeleteFront();
void DeleteLast();
void DeleteValue(int);
void DestroyList();
void InsertAtLast(node *);
void reverseList();



};


#endif //DOUBLE_LINKED_LIST_LINKED_LIST_H
