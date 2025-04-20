/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : header file for Code for Q2
*/
#ifndef HW3_MINIMALSET_H
#define HW3_MINIMALSET_H
struct index{
    int first = -1;
    int last = -1;
};
struct hashV{
    int hashValue1=0;
    int hashValue2=0;
    bool r = false;
    bool visited = false;
    int docIndex = -1;

};

class minimalset {
public:
   char*  reverseString(char* string,int size);
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


#endif //HW3_MINIMALSET_H
