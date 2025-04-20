/**
* Title: AVL Trees & Heap
* Author: Moin Khan
* ID: 22101287
* Section : 1
* Homework : 2
* Description : code to find length of prefixsubarray as requested in Question 3 using AVL trees
*/
#include "iostream"
#include "sstream"
#include "fstream"
#include "AVL.h"
#include "string"
using namespace std;
int main(int argc, char *argv[]) {

    string inputFilename = argv[1];
    string outputFilename;
    if (argc == 3)
        outputFilename = argv[2];
    else
        outputFilename = "NoName";
    ifstream file(inputFilename);
    ofstream outFile(outputFilename);
    string line;
    getline(file, line);
    stringstream ss(line);
    int N;
    int M;
    ss>> N >>M;

    getline(file,line);
    stringstream ss1(line);
    int A[N];
    int B[N];
    int index = 0;
    while(ss1)
    {
        ss1>>A[index];
        index++;
    }
    index = 0;
    getline(file,line);
    stringstream ss2(line);
    while(ss2)
    {
        ss2>>B[index];
        index++;
    }
    AVL tree1 = AVL();
    AVL tree2 = AVL();

    int count=0;
    int size = M;
    while(count<M)
    {
        count = 0;
        for(int i =0; i<size; i++)
        {
            Node* newNode1 = new Node(A[i]);
            Node* newNode2 = new Node(B[i]);
            tree1.root = tree1.insertNode(tree1.root,newNode1);
            tree2.root = tree2.insertNode(tree2.root,newNode2);
        }
        for(int i=0; i<size; i++)
        {
            int A_number = tree1.largestNumber(tree1.root);
            tree1.root = tree1.removeNode(tree1.root,A_number);
            int B_number = tree2.optimalCardNumber2(tree2.root,A_number);
            tree2.root = tree2.removeNode(tree2.root,B_number);
            if(A_number>B_number)
            {
                count++;
            }
        }
        if(count<M)
        {
            tree1.deleteTree(tree1.root);
            tree2.deleteTree(tree2.root);
            size++;
        }
    }
    if(outputFilename=="NoName")
    {
        cout<<size;
    }
    else
    {
        outFile << size;
    }
    return 0;
}