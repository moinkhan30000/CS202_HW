/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : cpp file for Queue storage
*/
#include "Queue.h"
Queue::Queue(int size)
{
    arraySize = size;
}
Queue::~Queue()
{
    arraySize = 0;
}

Node Queue::pop()
{
    Node x = array[arraySize-1];
    arraySize--;
    return x;
}
void Queue::push(Node x)
{
    arraySize++;
    array[arraySize-1] = x;
}
Node Queue::peak()
{
    return array[arraySize-1];
}

Node Queue::popFromBehind()
{
    Node x = array[0];
    for(int i=0; i<arraySize-1; i++)
    {
        array[i] = array[i+1];
    }
    arraySize--;
    return x;
}