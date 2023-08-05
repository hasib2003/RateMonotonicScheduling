//
// Created by hasib on 9/27/22.
//

#include "linked_list.h"
#include "node.h"
#include <iostream>
linked_list ::linked_list() {
    start = nullptr;
    last = nullptr;
    loc = nullptr;
    ploc = nullptr;

}



void linked_list ::Search(int value) {
    if (!isEmpty()) {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->period < value) {
            ploc = loc;
            loc = loc->next;
        }

        if(ploc!=last)
        {
            if (loc->period != value)
            {
                loc = nullptr;
            }
        }



    }
}
void linked_list ::InsertSorted(node * node) {

    if (!isEmpty()) {
        Search(node->period);
        if (loc == nullptr) {
            if (ploc != nullptr) {
                if (ploc == last) {
                    InsertAtLast(node);
                }
                else {
                    node->next = ploc->next;
                    node->previous = ploc;
                    ploc->next->previous= node;
                    ploc->next = node;

                }
            }
            else {
                InsertAtFront(node);
            }
        }
    }
    else {
        InsertAtFront(node);
    }
}


bool linked_list ::isPresent(int value) {
    Search(value);

    if (loc!= nullptr){
        if (loc->period == value) {
            return true;
        }
        else{
            return false;
        }

    }
    else{
        return false;
    }
}
bool linked_list :: isEmpty() const{
    return start == nullptr;
}
void linked_list ::printlist() const {

    node *temp = start;
    std::cout<<"List: ";
    while(temp!= nullptr){
        std::cout<<temp->period<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void linked_list::InsertAtFront(node * node) {
        node->next = start;
        node->previous = nullptr;

            if (isEmpty()) {
                last = node;
            }
            else{
                start->previous = node;

            }
            start = node;
        }



void linked_list ::InsertAtLast(node * node) {
        node->next = nullptr;
        node->previous = last;

        if (isEmpty()) {
            start = node;
        } else {
            last->next = node;
        }
        last = node;
    }


void linked_list ::DeleteFront() {
    if(!isEmpty())
    {
        node *temp = start;
        if (start->next == nullptr)
        {
            start = nullptr;
            last = nullptr;
        }
        else
        {
            start = start->next; // moving the start node to second position;
            start->previous = nullptr;// removing value of to be deleted first node in modified start node
        }
        delete temp;
    }
    else{
        std::cout<<"Error:the list is empty"<<std::endl;

    }
}

void linked_list ::DeleteLast() {
    if(!isEmpty())
    {
        node *temp = last;
        if (last->previous == nullptr)
        {
            start = nullptr;
            last = nullptr;
        }
        else
        {
            last = last->previous; // moving the last node to second last position;
            last->next = nullptr;// removing value of to be deleted last node in modified last node
        }
        delete temp;
    }
    else{
        std::cout<<"Error:the list is empty"<<std::endl;

    }

}
void linked_list ::DeleteValue(int value) {
    if(isPresent(value)) // Search has already been called in isPresent Function
    {
        if (loc == start){
            DeleteFront();
        }
        else if (loc == last){
            DeleteLast();
        }
        else{
            node *temp = loc;

            //targeted node's next is pointing to temp->next
            ploc->next = temp->next;
            //successor of the targeted node's(temp->next) previous is pointing to temp
            temp->next->previous = ploc;
        }
    }
    else{
        std::cout<<"Error: "<<value<<" is not present in the list"<<std::endl;
    }



}

void linked_list::ReverseDoubleLinkedList(){
    loc = start; // adress of current node
     // ploc as a swapper
    while (loc!= nullptr){
        ploc = loc->next;
        loc->next = loc->previous;
        loc->previous = ploc;

        loc = loc->previous;
    }

    loc = start;
    start = last;
    last = loc;


}



void linked_list ::SwapWhere(int x, int y)
{
    //x should be the start

    if(x>y){
        int temp = x;
        x = y;
        y = temp;
    }

    Search(y);
    node * loc_2 = loc;
    node * ploc_2= ploc;
    loc = nullptr;
    ploc= nullptr;
    Search(x);

    if (loc!= nullptr && loc_2!=nullptr) {

        //if we need to swap both the first and last node
        if ((loc == start && loc_2 == last) || (loc_2 == start && loc == last)) {

            if (start->next == last)     // if we have only two nodes
            {
                last->previous = nullptr;
                last->next = start;
                start->previous = last;
                start->next = nullptr;
                start = last;
                last = loc;
            }
                // if there are other nodes as well in between first and last
            else {


                ploc_2 = last->previous;
                last->previous = nullptr;
                last->next = start->next;
                start->next->previous = last;
                ploc_2->next = start;
                start->previous = ploc_2;
                start->next = nullptr;

                loc = start;
                start = last;
                last = loc;


            }


        }




        else if (loc == start )
        {
            // we need to have loc == start;

            node* temp = loc->next;
            loc->next = loc_2->next;
            loc->previous = ploc_2;

            loc_2->next->previous = loc;
            ploc_2->next = loc;

            loc_2->next = temp;
            temp->previous = loc_2;
            if (ploc!= nullptr)
            {
            ploc->next = loc_2;
            }
            loc_2->previous = ploc;

            start = loc_2;

        }

        else if (loc==last)
        {
            node* temp = loc->next;
            loc->next = loc_2->next;
            loc->previous = ploc_2;

            if(loc_2->next!= nullptr)
            {
            loc_2->next->previous = loc;
            }
            ploc_2->next = loc;

            loc_2->next = temp;
            temp->previous = loc_2;
            ploc->next = loc_2;
            loc_2->previous = ploc;

            last = loc_2;
        }
        else


        {
            node* temp = loc->next;
            loc->next = loc_2->next;
            loc->previous = ploc_2;

            loc_2->next->previous = loc;
            ploc_2->next = loc;

            loc_2->next = temp;
            temp->previous = loc_2;
            ploc->next = loc_2;
            loc_2->previous = ploc;





        }






    }



}
void linked_list ::SwapNodes() {
    loc = start;
    if (start == last){

    }
        // loc will be used as the temp node

    else if (start->next == last)
    {
        last->previous = nullptr;
        last->next = start;
        start->previous = last;
        start->next = nullptr;
        start = last;
        last = loc;

    }

    else
    {
        //working on four nodes
        ploc =loc;   // we shall start from swapping the 1 and 2 node
        loc=loc->next;
        start = loc; // moving the start pointer one node ahead

        node* will_effected_link = nullptr;
        while (loc!= nullptr)
        {
            ploc->next = loc->next;
            loc->next = ploc;

            loc->previous = ploc->previous;
            ploc->previous = loc;
            if(ploc->next != nullptr) {
                ploc->next->previous = ploc;
            }
            if (will_effected_link != nullptr) {
                will_effected_link->next = loc;
            }
            will_effected_link = loc;
            loc = ploc->next;


        }





    }
    loc = nullptr;
    ploc = nullptr;


}



void linked_list ::GroupEvenOdd() {
    if (!isEmpty()){
         if (start==last){
             return;
         }
         else if(start->next == last){
             return;
         }

         else{
             // we will move the even ones to the last
             node *terminator = last;
             loc = start; // will store the position
             ploc = nullptr;
             terminator = last;
             bool shift_start = false;
             int remainder = 0;
             if (start->period%2==0)
             {
                 remainder = 1;
                 shift_start = true;
             }
             // for starting with odd


             ploc = loc;
             loc=loc->next;

             while (loc!=terminator)
             {

                 if(loc->period%2==remainder) // shifting the even numbers to the end
                 {
                     ploc->next = loc->next;
                     ploc->next->previous = start;

                     loc->next = last->next;
                     last->next = loc;
                     loc->previous = last;


                     loc = ploc->next;
                     last = last->next;
                 }

                else
                {
                    ploc =loc;
                    loc=loc->next;
                }

             }


         }



    }
}



void linked_list ::DestroyList() {
    partialNode * pTemp = nullptr;
    while (start!=nullptr){
        node *temp = start;
        pTemp = temp->leftOverExec;
        temp->leftOverExec = nullptr;
        start = start->next;
        if(pTemp){
        delete pTemp;
        }
        delete temp;
    }
    last = nullptr;
}

linked_list :: ~linked_list() {
    DestroyList();

}

void linked_list :: PrintReverse(){
    node *temp = last;
    std::cout<<"List Reversed: ";
    while(temp!= nullptr){
        std::cout<<temp->period<<" ";
        temp = temp->previous;
    }
    std::cout<<std::endl;

}

void linked_list ::reverseList() {
    node *current = this->start;
    node *prev = nullptr;
    node *next = nullptr;

    while (current) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link

        prev = current;       // Move prev and current one step forward
        current = next;       // Move current one step forward
    }

    this->last = this->start; // Update the last pointer
    this->start = prev;       // Update the start pointer
printlist();
}