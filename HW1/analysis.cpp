/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 1
* Description : cpp file for analysis class for time analysis
*/
#include "analysis.h"
#include "ctime"
#include <cstdlib>
#include <iostream>
using namespace std;

void analysis::timeAnalysis()
{
    clock_t start_clock;
    clock_t start_clock1;
    clock_t stop_clock;
    clock_t stop_clock1;
    double time_taken;
    const int size = 10000;
    int array[size] = {0};
    int sortedArray[size] = {0};
    int random;
    BST tree = BST();
    BST tree2 = BST();

    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        while (flag== true)
        {
            flag = false;
            random = rand() % 20000;
            for (int j = 0; j < i; j++)
            {
                if (array[j] == random)
                {
                    flag = true;
                    break;
                }
            }
        }
        array[i] = random;
    }
    int counterIndex=0;
    for(int i =0; i<10;i++)
    {

        start_clock = clock();
        for(int j=0; j<1000; j++)
        {
            tree.insertKeyNoPrint(array[counterIndex]);
            counterIndex++;
        }
        stop_clock = clock();
        time_taken = stop_clock - start_clock;
        cout<<"Time taken for 10000 insertion(unsorted) is "<<time_taken/CLOCKS_PER_SEC<<" second"<<endl;
        cout<<"Height of tree is: "<<tree.heightOfTree(tree.root)<<endl;
        cout<<endl;
    }

    ///Sorted data analysis
    cout<<"Sorted Data Analysis-------------------------------------------------------------------------------"<<endl;
    cout<<endl;

  random = 2300;
    for (int i = 0; i < size; i++) {

        sortedArray[i] = random;
        random = random+5;
    }
    counterIndex=0;
    for(int i =0; i<10;i++)
    {
        start_clock1 = clock();
        for(int j=0; j<1000; j++)
        {
            tree2.insertKeyNoPrint(sortedArray[counterIndex]);
            counterIndex++;
        }
        stop_clock1 = clock();
        time_taken = stop_clock1 - start_clock1;
        cout<<"Time taken for 10000 insertion(sorted) is "<<time_taken/CLOCKS_PER_SEC <<" second"<<endl;
        cout<<"Height of tree is: "<<tree2.heightOfTree(tree2.root)<<endl;
        cout<<endl;
    }


}