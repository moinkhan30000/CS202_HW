/**
* Title: Binary Search Trees
* Author : Moin Khan
* ID: 22101287
* Section : 3
* Homework : 1
* Description : cpp file for BST(Binary Search Tree) class
*/

#include "BST.h"
#include <iostream>
using namespace std;

BST::BST():root(nullptr),counter(0) {}

BST::BST(int keys[], int size):root(nullptr),counter(0)
{
    for(int i=0; i<size; i++)
    {
        insertKeyNoPrint(keys[i]);
    }
    cout<<"BST with size "<< size <<" is created."<<endl;

}
BST::~BST()
{
    deleteTree(root);
}

void BST::deleteTree(Node* node)
{
    if(node!= nullptr)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

}

void BST::insertKey(int key)
{
    //recursiveInsertion(root, nullptr,key);
    Node* currentNode = root;
    Node* parentNode = nullptr;
    int flag = -1;

    if(root == nullptr)
    {
        root = new Node(key);
        cout<<"Key "<<key<<" is added."<<endl;
        counter++;
        return;
    }
    while(currentNode!= nullptr)
    {
        parentNode = currentNode;
        if(key<parentNode->key)
        {
            currentNode = parentNode->left;
            flag =0;
        }
        else if(key>parentNode->key)
        {
            currentNode = parentNode->right;
            flag =1;
        }
        else
        {
            cout<<"Key "<<key<<" is not added. It exists!"<<endl;
            return;
        }

    }
    Node* newNode = new Node(key);
    newNode->parent = parentNode;
    if(flag == 0)
    {
        parentNode->left=newNode;
        cout<<"Key "<<key<<" is added."<<endl;
        counter++;
        return;
    }
    else if(flag==1)
    {
        parentNode->right = newNode;
        cout<<"Key "<<key<<" is added."<<endl;
        counter++;
        return;
    }

}
void BST::insertKeyNoPrint(int key)
{
    //recursiveInsertion(root, nullptr,key);
    Node* currentNode = root;
    Node* parentNode = nullptr;
    int flag = -1;

    if(root == nullptr)
    {
        root = new Node(key);
        counter++;
        return;
    }
    while(currentNode!= nullptr)
    {
        parentNode = currentNode;
        if(key<parentNode->key)
        {
            currentNode = parentNode->left;
            flag =0;
        }
        else if(key>parentNode->key)
        {
            currentNode = parentNode->right;
            flag =1;
        }
        else
        {
            return;
        }

    }
    Node* newNode = new Node(key);
    newNode->parent = parentNode;
    if(flag == 0)
    {
        parentNode->left=newNode;
        counter++;
        return;
    }
    else if(flag==1)
    {
        parentNode->right = newNode;
        counter++;
        return;
    }

}


void BST::deleteKey(int key)
{
    Node* currentNode = root;
    Node* parentNode = nullptr;
    int flag = -1;
    while(currentNode!= nullptr)
    {
        parentNode = currentNode;
        if(key<parentNode->key)
        {
            currentNode = parentNode->left;
            flag = 0;
        }
        else if(key>parentNode->key)
        {
            currentNode = parentNode->right;
            flag =1;

        }
        else if(key == parentNode->key)
        {
            if(parentNode->left == nullptr && parentNode->right == nullptr)
            {
                if(flag == 0)
                {
                    parentNode->parent->left = nullptr;
                    delete parentNode;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    return;
                }
                else if(flag == 1)
                {
                    parentNode->parent->right = nullptr;
                    delete parentNode;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    return;
                }
                else if(flag ==-1)
                {
                    delete root;
                    root = nullptr;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    return;
                }

            }
            else if(parentNode->left != nullptr && parentNode->right == nullptr)
            {
                if(parentNode->parent->left==parentNode)
                {
                    parentNode->parent->left = parentNode->left;
                }
                else if(parentNode->parent->right==parentNode)
                {
                    parentNode->parent->right = parentNode->right;
                }
                else if(flag == -1)
                {
                    Node* temp = root;
                    root = root->left;
                    delete temp;
                    return;
                }
                delete parentNode;
                cout<<"Key "<<key<<" is deleted."<<endl;
                counter--;
                return;

            }
            else if(parentNode->left == nullptr && parentNode->right != nullptr)
            {
                if(parentNode->parent->left==parentNode)
                {
                    parentNode->parent->left = parentNode->right;
                }
                else if(parentNode->parent->right==parentNode)
                {
                    parentNode->parent->right = parentNode->right;
                }
                else if(flag == -1)
                {
                    Node* temp = root;
                    root = root->right;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    delete temp;
                }
                delete parentNode;
                cout<<"Key "<<key<<" is deleted."<<endl;
                counter--;
                return;

            }
            else if(parentNode->left != nullptr && parentNode->right != nullptr)
            {
                Node* temp = minValueNode(parentNode);
                parentNode->key = temp->key;
                if(temp->right== nullptr)
                {
                    delete temp;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    return;
                }
                else
                {
                    temp->parent->left = temp->right;
                    delete temp;
                    cout<<"Key "<<key<<" is deleted."<<endl;
                    counter--;
                    return;
                }

            }

        }
    }
    if(currentNode == nullptr)
    {
        cout<<"Key "<<key<<" is not deleted. It does not exist!"<<endl;
        return;
    }


}
Node* BST::minValueNode(Node *node)
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
void BST::recursivePrint(Node *node,int* array,int* x)
{
    if(node!= nullptr)
    {
        recursivePrint(node->left,array,x);
        array[(*x)] = node->key;
        (*x)++;
        recursivePrint(node->right,array,x);
    }

}
void BST::displayInorder()
{
    int inOrder[counter];
    int z =0;
    int* x = &z;
    recursivePrint(root,inOrder,x);
    cout<<"Inorder display is: ";
    for(int i=0; i<counter; i++)
    {
        cout<<inOrder[i];
        if(i!=counter-1)
        {
            cout<<", ";
        }

    }

    cout<<endl;


}
void BST::findFullBTLevel()
{
    if(root->left== nullptr||root->right== nullptr)
    {
        cout<<"Full binary tree level is: 1"<<endl;
        return;
    }
    int level =0;
    level = recursiveLevelCount(root);
    level = level;
    cout<<"Full binary tree level is: "<< level<<endl;
    return;


}
int BST::recursiveLevelCount(Node *node)
{
    int x=0;
    int y =0;
    if(node->left!= nullptr)
    x  = x +  recursiveLevelCount(node->left);
    if(node->right!= nullptr)
    y = y + recursiveLevelCount(node->right);
    if(node->left== nullptr && node->right== nullptr)
    {
        x++;
        y++;
    }
    else if(node->left!= nullptr  && node->right!= nullptr)
    {
        x++;
        y++;
    }
    else if(node->left != nullptr  || node->right!= nullptr)
    {
        x++;
        y++;
    }

    if(x<y)
    {
        return x;
    }
    else
        return y;

}
void BST::lowestCommonAncestor(int A, int B)
{
    stack pathToA = stack(0);
    stack pathToB = stack(0);
    Node* currentNode = root;
    while(currentNode->key!= A )  //path from root to A
    {
        if(A<currentNode->key)
        {
            pathToA.push(currentNode->key);
            currentNode = currentNode->left;
        }
        else if(A>currentNode->key)
        {
            pathToA.push(currentNode->key);
            currentNode = currentNode->right;

        }
    }
    pathToA.push(A);
    currentNode = root;
    while(currentNode->key!= B)  //path from root to B
    {
        if(B<currentNode->key)
        {
            pathToB.push(currentNode->key);
            currentNode = currentNode->left;

        }
        else if(B>currentNode->key)
        {
            pathToB.push(currentNode->key);
            currentNode = currentNode->right;

        }
    }
    pathToB.push(B);
    int lCA = pathToA.commonInteger(pathToB);

    cout<<"Lowest common ancestor of "<<A<<" and "<<B<< " is: "<< lCA<<endl;

}

void BST::pathFromAtoB(int A, int B)
{
    stack pathToA = stack(0);
    stack pathToB = stack(0);
    Node* currentNode = root;
    while(currentNode->key!= A )  //path from root to A
    {
        if(A<currentNode->key)
        {
            pathToA.push(currentNode->key);
            currentNode = currentNode->left;
        }
        else if(A>currentNode->key)
        {
            pathToA.push(currentNode->key);
            currentNode = currentNode->right;

        }
    }
    pathToA.push(A);
    currentNode = root;
    while(currentNode->key!= B)  //path from root to B
    {
        if(B<currentNode->key)
        {
            pathToB.push(currentNode->key);
            currentNode = currentNode->left;

        }
        else if(B>currentNode->key)
        {
            pathToB.push(currentNode->key);
            currentNode = currentNode->right;

        }
    }
    pathToB.push(B);
    int lCA = pathToA.commonInteger(pathToB);

    stack pathAtoB = stack(0);
    while(pathToA.peak()!=lCA)
    {
        pathAtoB.push(pathToA.pop());
    }
    while(pathToB.peakFromBottom()!=lCA)
    {
        int x = pathToB.popFromBottom();
    }
    int size = pathToB.arraySize;
    for(int i=0; i<size;i++)
    {
        pathAtoB.push(pathToB.popFromBottom());
    }
    cout<<"Path from "<<A<<" to "<<B<< " is: ";
    size = pathAtoB.arraySize;
    for(int i=0; i<size; i++)
    {
        cout<<pathAtoB.popFromBottom();
        if(i!=size-1)
        {
            cout<<", ";
        }

    }
    cout<<endl;


}
void BST::maximumSumPath()
{
    stack maxSumPath = stack(0);
    recursiveSumPath(root,maxSumPath);
    cout<<"Maximum sum path is: ";
    for(int i=maxSumPath.arraySize-1; i>=0; i--)
    {
        cout<<maxSumPath.array[i];
        if(i!=0)
        {
            cout<<", ";
        }

    }
    cout<<endl;

}
int BST::largestNumber(int A, int B)
{
    if(A>B)
    {
        return A;
    }
    else if(A<B)
    {
        return B;
    }
    else
        return A;
}
int BST::recursiveSumPath(Node *node,stack& maxPath)
{
    if(node == nullptr)
    {
        return 0;
    }
    int key = node->key;
    stack leftPath = stack(0);
    stack rightPath = stack(0);
    int sum = 0;
    int leftPathSum =0;
    int rightPathSum = 0;
    if(node->left!= nullptr)
    leftPathSum = recursiveSumPath(node->left,leftPath);
    if(node->right!= nullptr)
    rightPathSum = recursiveSumPath(node->right,rightPath);

    if(leftPathSum>rightPathSum)
    {
        maxPath.copyStack(leftPath);
        sum = leftPathSum;
    }
    else if(leftPathSum<rightPathSum)
    {
        maxPath.copyStack(rightPath);
        sum = rightPathSum;
    }
    else if(leftPathSum=rightPathSum)
    {
        maxPath.copyStack(rightPath);
        sum = rightPathSum;
    }
    maxPath.push(key);
    sum = sum + key;
    return sum;

}

void BST::maximumWidth()
{
    int maxLevel = 0;
    int numberOfNodes = 0;
    Node* currentNode = root;
     Queue queue = Queue(0);
    stack maxLevelTracking = stack(0);
    int count=0;
    int countStorage =1;
    bool flag =true;
    queue.push(*root);
    maxLevelTracking.push(root->key);
    while (flag) {
        for(int i=0; i<countStorage;i++)
        {
            Node current = queue.popFromBehind();
            maxLevelTracking.push(current.key);



            if (current.left != nullptr) {
                queue.push(*current.left);
                count++;
            }

            if (current.right != nullptr) {
                queue.push(*current.right);
                count++;
            }
        }
        if(countStorage<count)
        {
            countStorage = count;
            count =0;
            flag = true;
            maxLevelTracking.arraySize =0;
        }
        else
        {
            flag = false;
        }

    }
    cout<<"Maximum level is: ";
    for(int i=0; i<maxLevelTracking.arraySize; i++)
    {
        cout<<maxLevelTracking.array[i];
        if(i!=maxLevelTracking.arraySize-1)
        {
            cout<<", ";
        }

    }
    cout<<endl;
}


int BST::heightOfTree(Node *node)
{
    int x=0;
    int y =0;
    if(node->left!= nullptr)
        x  = x +  heightOfTree(node->left);
    if(node->right!= nullptr)
        y = y + heightOfTree(node->right);
    if(node->left== nullptr && node->right== nullptr)
    {
        x++;
        y++;
    }
    else if(node->left!= nullptr  && node->right!= nullptr)
    {
        x++;
        y++;
    }
    else if(node->left != nullptr  || node->right!= nullptr)
    {
        x++;
        y++;
    }

    if(x>y)
    {
        return x;
    }
    else
        return y;
}

