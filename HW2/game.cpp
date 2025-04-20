/**
* Title: AVL Trees & Heap
* Author: Moin Khan
* ID: 22101287
* Section : 1
* Homework : 2
* Description : main code for the card Game using AVL trees
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "AVL.h"
using namespace std;
int main(int argc, char *argv[]) {

    string inputFilename = argv[1];
    string outputFilename;
    if(argc==3)
        outputFilename = argv[2];
    else
        outputFilename = "NoName";
    ifstream file(inputFilename);
    ofstream outFile(outputFilename);
    string line;
    getline(file, line);
    int numberOfCards = stoi(line);
    AVL B_tree = AVL();
    AVL H_tree = AVL();
    getline(file, line);
    stringstream ss(line);
    int cardNumber;
    while(ss >> cardNumber)
    {
        Node* newNode = new Node(cardNumber);
        B_tree.root = B_tree.insertNode(B_tree.root,newNode);
    }
    getline(file, line);
    stringstream ss2(line);
    while(ss2 >> cardNumber)
    {
        Node* newNode = new Node(cardNumber);
        H_tree.root = H_tree.insertNode(H_tree.root,newNode);
    }
    int turnCount = 0;
    int B_Score = 0;
    int H_score = 0;

    while(turnCount<numberOfCards)
    {
        turnCount++;
        if(turnCount%2!=0)
        {
            int B_card = B_tree.largestNumber(B_tree.root);
            B_tree.root = B_tree.removeNode(B_tree.root,B_card);
            int H_card = H_tree.optimalCardNumber(H_tree.root,B_card);
            H_tree.root= H_tree.removeNode(H_tree.root,H_card);
            if(B_card>H_card)
            {
                B_Score++;
            }
            else
            {
                H_score++;
            }

        }
        else
        {
            int H_card = H_tree.largestNumber(H_tree.root);
            H_tree.root = H_tree.removeNode(H_tree.root,H_card);
            int B_card = B_tree.optimalCardNumber(B_tree.root,H_card);
            B_tree.root=B_tree.removeNode(B_tree.root,B_card);
            if(H_card>B_card)
            {
                H_score++;
            }
            else
            {
                B_Score++;
            }
        }

    }
    if(outputFilename == "NoName")
    {
        cout<<B_Score<<" "<<H_score<<endl;
    }
    else
    outFile << B_Score<<" "<<H_score << "\n";



}