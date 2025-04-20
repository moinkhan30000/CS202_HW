/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : Header File for BST(Binary Search Tree) class
*/

#ifndef HW1_BST_H
#define HW1_BST_H
#include "Node.h"
#include "stack.h"
#include "Queue.h"


class BST {
public:
    BST();
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    int recursiveSumPath(Node* node,stack&maxPath);
    void pathFromAtoB(int A, int B);
    Node* minValueNode(Node* node);
    void recursivePrint(Node* node,int* array,int* x);
    int recursiveLevelCount(Node* node);
    int largestNumber(int A,int B);
    void insertKeyNoPrint(int key);
    void deleteTree(Node* node);
    int heightOfTree(Node* node);
    Node* root;
    int counter;
    int smallestNumber;


};


#endif //HW1_BST_H
