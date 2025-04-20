//
// Created by moink on 05-11-2024.
//

#include "AVL.h"

AVL::AVL():root(nullptr) {}
void AVL::deleteTree(Node* node)
{
    if(node!= nullptr)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

}
AVL::~AVL()
{
    deleteTree(root);
}
int AVL::getHeight(Node *N)
{
    if(N== nullptr)
        return 0;
    return N->height;
}

int AVL::maxOfTwoHeights(int h1, int h2)
{
    if(h1>h2)
    {
        return h1;
    }
    else
        return h2;
}

Node *AVL::rightRotation(Node *N)
{
    if (N == nullptr) {
        return nullptr;
    }
    else
    {
        Node* left = N->left;
        N->left = left->right;
        left->right = N;
        N->height = 1 + maxOfTwoHeights(getHeight(N->left), getHeight(N->right));;
        left->height = 1 + maxOfTwoHeights(getHeight(left->left), getHeight(left->right));

        return left;
    }


}

int AVL::balanceFactor(Node *N)
{
    if(N== nullptr)
    {
        return 0;
    }
    else
    {
        int balance = getHeight(N->right)- getHeight(N->left);
        return balance;
    }
}

Node *AVL::leftRotation(Node *N)
{
    if (N == nullptr) {
        return nullptr;
    }
    else
    {
        Node* right = N->right;
        N->right = right->left;
        right->left = N;
        N->height = 1 + maxOfTwoHeights(getHeight(N->left), getHeight(N->right));;
        right->height = 1 + maxOfTwoHeights(getHeight(right->left), getHeight(right->right));
        return right;
    }

}

Node *AVL::insertNode(Node *root, Node* newNode)
{
    if(root == nullptr)
    {
        return newNode;
    }
    else
    {
        if(newNode->key<root->key)
        {
            root->left = insertNode(root->left,newNode);
        }
        else if(newNode->key>root->key)
        {
            root->right = insertNode(root->right,newNode);
        }
        root->height = 1+ maxOfTwoHeights(getHeight(root->left), getHeight(root->right));




        int balance  = balanceFactor(root);
        if(balance < -1)
        {
            int leftOfLeft = getHeight(root->left->left);
            int rightOfLeft = getHeight(root->left->right);
            if(leftOfLeft>=rightOfLeft)
            root = rightRotation(root);
            else
            {
                root->left = leftRotation(root->left);
                root = rightRotation(root);
            }

        }
        else if(balance>1)
        {
            int rightOfRight = getHeight(root->right->right);
            int leftOfRight = getHeight(root->right->left);
            if(rightOfRight>=leftOfRight)
            root = leftRotation(root);
            else
            {
                root->right = rightRotation(root->right);
                root = leftRotation(root);
            }
        }

        return root;

    }
}
Node* AVL::minValueNode(Node *node)
{
    Node* currentSmallestNode = node;
    Node* currentNode = node->left;
    while(currentNode != nullptr)
    {
        currentSmallestNode = currentNode;
        currentNode = currentNode->left;
    }
    return currentSmallestNode;

}

void AVL::processLeftmost(Node *&nodePtr, int &treeItem)
{
    if (nodePtr->left == nullptr) {
        treeItem = nodePtr->key;
        Node *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = nullptr; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->left, treeItem);
}

Node* AVL::removeNode(Node *root, int key)
{
    Node* delPtr;
    if(root== nullptr)
    {
        return root;
    }
    if(key<root->key)
    {
        root->left = removeNode(root->left,key);
    }
    else if( key>root->key)
    {
        root->right = removeNode(root->right,key);
    }
    else if(root->key == key )
    {
        if(root->left != nullptr && root->right!= nullptr)
        {
            int item;
            processLeftmost(root->right, item);
            root->key = item;

        }
        else if(root->left == nullptr && root->right!= nullptr)
        {
            delPtr = root;
            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;

        }
        else if(root->left != nullptr && root->right== nullptr)
        {
            delPtr = root;
            root = root->left;
            delPtr->left = nullptr;
            delete delPtr;

        }
        else if(root->left == nullptr && root->right== nullptr)
        {
            delete root;
            root = nullptr;
        }

    }
    if(root == nullptr)
    {
        return root;
    }
    root->height = 1+ maxOfTwoHeights(getHeight(root->left), getHeight(root->right));

    int balance  = balanceFactor(root);
    if(balance < -1)
    {
        int leftOfLeft = getHeight(root->left->left);
        int rightOfLeft = getHeight(root->left->right);
        if(leftOfLeft>=rightOfLeft)
            root = rightRotation(root);
        else
        {
            root->left = leftRotation(root->left);
            root = rightRotation(root);
        }

    }
    else if(balance>1)
    {
        int rightOfRight = getHeight(root->right->right);
        int leftOfRight = getHeight(root->right->left);
        if(rightOfRight>=leftOfRight)
            root = leftRotation(root);
        else
        {
            root->right = rightRotation(root->right);
            root = leftRotation(root);
        }
    }

    return root;


}

int AVL::optimalCardNumber(Node *N, int card)
{
    Node* currentNode = N;
    Node* lastNode = nullptr;
    while(currentNode!= nullptr)
    {
        if(currentNode->key<card)
        {
            lastNode = currentNode;
            if(currentNode->right!= nullptr)
            currentNode = currentNode->right;
            else
                return currentNode->key;
        }
        else if(currentNode->key>card )
        {
            if(lastNode!= nullptr && currentNode->left== nullptr)
                return lastNode->key;
            if(currentNode->left!= nullptr)
            {
                lastNode = currentNode;
                currentNode = currentNode->left;
            }
            else
            {
                return currentNode->key;
            }
        }

    }
}

int AVL::optimalCardNumber2(Node *N, int card)
{
    Node* currentNode = N;
    Node* lastNode = nullptr;
    while(currentNode!= nullptr)
    {
        if(currentNode->key<card)
        {
            lastNode = currentNode;
            if(currentNode->right!= nullptr)
                currentNode = currentNode->right;
            else
                return currentNode->key;
        }
        else if(currentNode->key>=card )
        {
            if(lastNode!= nullptr && currentNode->left== nullptr)
                return lastNode->key;
            if(currentNode->left!= nullptr)
            {
                lastNode = currentNode;
                currentNode = currentNode->left;
            }
            else
            {
                return currentNode->key;
            }
        }
        else
        {

        }

    }
}

int AVL::largestNumber(Node *N)
{
    Node* currentNode = N;
    Node* lastNode = nullptr;
    while(currentNode!= nullptr)
    {
        lastNode = currentNode;
        currentNode = currentNode->right;

    }
    return lastNode->key;
}