/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : cpp file for stack/queue storage
*/

#include "stack.h"
stack::stack(int size)
{
    arraySize = size;
}
stack::~stack()
{
    arraySize = 0;
}

int stack::pop()
{
    int x = array[arraySize-1];
    arraySize--;
    return x;
}
void stack::push(int x)
{
    arraySize++;
    array[arraySize-1] = x;
}

int stack::commonInteger(stack& A)
{
    int sizeOfA = A.arraySize;
    int size = arraySize;
    for(int i=size-1; i>=0; i--)
    {
        for(int j=sizeOfA-1; j>=0; j--)
        {
            if(array[i] == A.array[j])
            {
                return A.array[j];
            }
        }
    }
}
int stack::peak()
{
    return array[arraySize-1];
}
int stack::popFromBottom()
{
    int x = array[0];
    for(int i=0; i<arraySize-1; i++)
    {
        array[i] = array[i+1];
    }
    arraySize--;
    return x;
}
int stack::peakFromBottom()
{
    return array[0];
}
int stack::copyStack(stack &A)
{
    this->arraySize = A.arraySize;
    for(int i=0; i<A.arraySize; i++)
    {
        this->array[i] = A.array[i];
    }

}
