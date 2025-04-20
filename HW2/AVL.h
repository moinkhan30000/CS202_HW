//
// Created by moink on 05-11-2024.
//

#ifndef HW2_AVL_H
#define HW2_AVL_H
struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int a):key(a),left(nullptr),right(nullptr),height(1){}
};

class AVL {
public:
    AVL();
    ~AVL();
    void deleteTree(Node* node);
    int getHeight(Node* N);
    Node* rightRotation(Node* N);
    Node* leftRotation(Node* N);
    int balanceFactor(Node* N);
    int maxOfTwoHeights(int h1, int h2);
    Node* insertNode(Node* root,Node* newNode);
    Node* removeNode(Node* root,int key);
    Node* minValueNode(Node *node);
    void processLeftmost(Node *&nodePtr,int& treeItem);
    int optimalCardNumber(Node* N, int card);
    int largestNumber(Node* N);
    int optimalCardNumber2(Node *N, int card);
    Node* root;
    };


#endif //HW2_AVL_H
