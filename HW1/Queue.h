/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : header file for Queue storage
*/
#ifndef HW1_QUEUE_H
#define HW1_QUEUE_H
#include "Node.h"

class Queue {
public:
Node array[50000];
int arraySize;
    Queue(int size);
    ~Queue();
    void push(Node x);
    Node pop();
    Node popFromBehind();
    Node peak();

};


#endif //HW1_QUEUE_H
