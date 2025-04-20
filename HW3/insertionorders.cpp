/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : Code for Q5
*/


#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int MODULO = 1000000009;
const int MAX_ELEMENTS = 100001;

void reverseSegment(int array[], int startIndex, int endIndex) {
    while (startIndex < endIndex) {
        swap(array[startIndex++], array[endIndex--]);
    }
}

void exchangeValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool nextPermutation(int array[], int length) {
    int index = length - 2;
    while (index >= 0 && array[index] >= array[index + 1]) {
        index--;
    }
    if (index < 0) {
        reverseSegment(array, 0, length - 1);
        return false;
    }
    int swapIndex = length - 1;
    while (array[swapIndex] <= array[index]) {
        swapIndex--;
    }
    exchangeValues(array[index], array[swapIndex]);
    reverseSegment(array, index + 1, length - 1);
    return true;
}

bool isValidPermutation(int size, const int original[], const int perm[], int permSize) {
    int hashMap[size];
    fill(hashMap, hashMap + size, -1);

    for (int i = 0; i < permSize; i++) {
        int value = perm[i];
        int hashIndex = value % size;
        while (hashMap[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % size;
        }
        hashMap[hashIndex] = value;
    }

    for (int i = 0; i < size; i++) {
        if (hashMap[i] != original[i]) {
            return false;
        }
    }
    return true;
}

int countValidInsertionOrders(int size, const int original[]) {
    int uniqueElements[size];
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (original[i] != -1) {
            uniqueElements[count++] = original[i];
        }
    }

    sort(uniqueElements, uniqueElements + count);
    long long validPermutations = 0;

    do {
        if (isValidPermutation(size, original, uniqueElements, count)) {
            validPermutations = (validPermutations + 1) % MODULO;
        }
    } while (nextPermutation(uniqueElements, count));

    return validPermutations;
}

int main(int argc, char *argv[]) {
    ifstream inputFile(argv[1]);
    ofstream outputFile;
    bool writeToFile = (argc == 3);
    if (writeToFile) outputFile.open(argv[2]);

    int size;
    inputFile >> size;

    int *originalTable = new int[size];
    for (int i = 0; i < size; i++) {
        inputFile >> originalTable[i];
    }

    int result = countValidInsertionOrders(size, originalTable);

    if (writeToFile) {
        outputFile << result << endl;
    } else {
        cout << result << endl;
    }

    delete[] originalTable;
    return 0;
}