/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : cpp file for BST(Binary Search Tree) class
*/
#ifndef HW1_NODE_H
#define HW1_NODE_H


class Node {
public:
    Node();

    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int a);



};


#endif //HW1_NODE_H
