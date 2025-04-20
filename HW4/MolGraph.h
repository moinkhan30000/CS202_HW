/**
* Title: Graphs
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 4
* Description : MolGraph header file
*/


#ifndef HW4_MOLGRAPH_H
#define HW4_MOLGRAPH_H
#include "string"
#include "fstream"
#include "sstream"
#include "Queue.h"
#include "iostream"
using namespace std;

class MolGraph {
    struct edges{
        int start;
        int end;
    };
public:
    MolGraph(const std::string & filename);
    ~MolGraph();
    void getDiameter();
    int farthestNode(int source, int& maxD);
    void minBondPath(int source, int destination);
    void getMST();
    int** documents;
    int* degree;
    int size = 0;
    int MAX = 100001;
};


#endif //HW4_MOLGRAPH_H
