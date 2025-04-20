/**
* Title: AVL Trees & Heap
* Author: Moin Khan
* ID: 22101287
* Section : 1
* Homework : 2
* Description : Code to find least 5 numbers from a minHeap
*/
#include "minHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "least5.h"
using namespace std;


void least5::selectionSort(int arr[], int count)
{
    for(int i=0; i<count-1; i++)
    {
        int minimumIndex = i;
        for(int j=i+1; j<count; j++)
        {
            if(arr[minimumIndex]>arr[j])
            {
                minimumIndex = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[minimumIndex];
        arr[minimumIndex] = t;

    }
}
int main(int argc, char *argv[]) {
    least5 obj;
    string outputFilename;
    string inputFilename = argv[1];
    if(argc==3)
    outputFilename = argv[2];
    else
        outputFilename = "NoName";
    ifstream file(inputFilename);
    ofstream outFile(outputFilename);
    string line;
    getline(file,line);
    minHeap heap;
    int smallestInteger[5];
    int smallestIntegerCount = 0;
    while(getline(file,line))
    {
        string command;
        int number = -1;
        istringstream iss(line);
        iss >> command >> number;
        if(command=="a")
        {
            heap.heapInsert(number);
            if(smallestIntegerCount<5)
            {
                smallestInteger[smallestIntegerCount] = number;
                smallestIntegerCount++;
                obj.selectionSort(smallestInteger,smallestIntegerCount);
            }
            else
            {
                if(smallestInteger[4]>number)
                {
                    smallestInteger[4] = number;
                    obj.selectionSort(smallestInteger,smallestIntegerCount);
                }
            }
        }
        else if(command == "r")
        {
            int x = -1;
            heap.heapDelete(x);
            if(heap.size<5 && heap.size>0)
            {
                smallestInteger[0] = smallestInteger[smallestIntegerCount-1];
                smallestIntegerCount--;
                obj.selectionSort(smallestInteger,smallestIntegerCount);
            }
            else if(heap.size==0)
            {
                smallestIntegerCount--;
            }
            else
            {
                int temp[5];
                for(int i=0; i<5; i++)
                {
                    int r =-1;
                    heap.heapDelete(r);
                    temp[i] = r;
                }
                smallestInteger[0] = temp[4];
                obj.selectionSort(smallestInteger,smallestIntegerCount);
                for(int i=0; i<5; i++)
                {
                    heap.heapInsert(temp[i]);
                }


            }

        }
        else if(command == "g")
        {
            if(smallestIntegerCount<5)
            {
                if(outputFilename == "NoName")
                    cout<<-1<<endl;
                else
                outFile << "-1\n";
            }
            else
            {
                for(int i=0; i<5; i++)
                {
                    string str = to_string(smallestInteger[i]);
                    if(outputFilename == "NoName")
                    {
                        cout<<str<<endl;
                    }
                    else
                    outFile << str + "\n";
                }
            }
        }


    }

    return 0;
}