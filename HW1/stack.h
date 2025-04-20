/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 1
* Description : cpp file for stack/queue storage
*/

#ifndef HW1_STACK_H
#define HW1_STACK_H


class stack {
public:
    stack(int size);
    ~stack();
    void push(int x);
    int pop();
    int peak();
    int commonInteger(stack& A);
    int popFromBottom();
    int peakFromBottom();
    int copyStack(stack& A);


    int array[50000];
    int arraySize;
};


#endif //HW1_STACK_H
