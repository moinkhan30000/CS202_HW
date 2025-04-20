/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : header file for Code for Q1
*/

#ifndef HW3_SUBSTRINGS_H
#define HW3_SUBSTRINGS_H

using namespace std;
#include <iostream>
#include <fstream>
struct hashV{
    int hashValue1=0;
    int hashValue2=0;
    bool r = false;
    bool visited = false;
    int docIndex = -1;

};

class substrings {
public:
    int stringSize(char* charArray);
    int getValue(char x);
    int calculateHashValue(char* key,int keySize, int* powerArray,int* powerArray2, int& hashVal2);
    void preCalculatePower(int size,int* power, int* power2);
    int Pow(int base, int power);
    int rollHash(int hashValue,char remove,char add,int lengthOfPattern, int* powerArray);
    int rollHash2(int hashValue2, char remove, char add, int lengthOfPattern, int* powerArray2);
    int binarySearchFirst(hashV* arr, int n, hashV target);
    int binarySearchLast(hashV* arr, int n, hashV target);
    const int prime = 1000000007;
    const int prime2 = 1000000009;
    const int MAX_SIZE = 100001;

};


#endif //HW3_SUBSTRINGS_H
