/**
* Title: Graphs
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 4
* Description : Queue designed using arrays
*/


#include "Queue.h"
Queue::Queue(int size)
{
    array = new int[size];
    arraySize = size;
}
Queue::Queue()
{

    array = nullptr;
    arraySize = 0;
}
Queue::~Queue()
{
    delete[] array;
    array = nullptr;
}
 int Queue::pop()
{
    int x = array[arraySize-1];
    arraySize--;
    if(arraySize!=0)
    {
        int* temp = new int[arraySize];
        for(int i=0; i<arraySize; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;

    }
    else
    {
        if(array!= nullptr)
        {
            delete[] array;
        }
        array = nullptr;
    }
    return x;
}
void Queue::push(int x)
{
    arraySize++;
    int* temp = new int[arraySize];
    for(int i=1; i<arraySize; i++)
    {
        temp[i] = array[i-1];
    }
    temp[0] = x;
    delete[] array;
    array = temp;
}
int Queue::peak()
{
    return array[arraySize-1];
}

int Queue::popFromBehind()
{
    {
        int x = array[0];
        arraySize--;
        int* temp = new int[arraySize];
        for(int i=0; i<arraySize; i++)
        {
            temp[i] = array[i+1];
        }
        delete[] array;
        array = temp;
        return x;
    }
}

bool Queue::isEmpty() {
    if(this->array== nullptr)
    {
        return true;
    }
    return false;
}