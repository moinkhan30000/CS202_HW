/**
* Title: Graphs
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 4
* Description : Queue header file
*/

#ifndef HW4_QUEUE_H
#define HW4_QUEUE_H


class Queue {
public:
    int* array;
    int arraySize;
    Queue(int size);
    Queue();
    ~Queue();
    void push(int x);
    bool isEmpty();
    int pop();
    int popFromBehind();
    int peak();


};


#endif //HW4_QUEUE_H
