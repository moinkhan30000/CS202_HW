/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : Code for Q4
*/

#include "iostream"
#include "fstream"
using namespace std;
const int MAX_SIZE = 100001;
bool isValid(int* hashTable, int N) {
    for (int i = 0; i < N; i++) {
        if (hashTable[i] == -1) continue;

        int originalIndex = hashTable[i] % N;
        int j ;
        for (j = originalIndex; j != i; j = (j + 1) % N) {
            if (hashTable[j] == hashTable[i])
                break;
            if (hashTable[j] == -1)
                return false;
        }
        if (j != i )
            return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    bool outputFileFlag = true;
    ofstream outFile;
    ifstream inputFile(argv[1]);
    if (argc == 3)
    {
        outFile.open(argv[2]);
    }
    else
    {
        outputFileFlag = false;
    }

    char* patternC = new char[MAX_SIZE];
    inputFile.getline(patternC, MAX_SIZE);
    int N = atoi(patternC);
    delete[] patternC;
    char character;
    int index = 0;
    int currentNumber = 0;
    int* hashTable = new int[N];
    bool isNegative = false;
    int t = 0;
    while (inputFile.get(character)) {
        if (character == ' ' || character == '\n') {
            if (index < N) {
                if(isNegative)
                {
                    hashTable[index++] = currentNumber*(-1);
                }
                else
                {
                    hashTable[index++] = currentNumber;
                    t++;
                }
            }
            currentNumber = 0;
            isNegative = false;
        } else if (character == '-') {
            isNegative = true;

        } else {
            currentNumber = currentNumber*10;
            currentNumber = currentNumber+(character-48);
        }
    }
    bool f = isValid(hashTable,N);
    int** isBefore = new int*[N];
    for (int i = 0; i < N; i++) {
        isBefore[i] = new int[N]();
    }
    int* before = new int[N]();
    int* result = new int[N];
    int resultSize = 0;

    for (int i = 0; i < N; i++) {
        if (hashTable[i] != -1) {
            int originalIndex = hashTable[i] % N;
            for (int j = originalIndex; j != i; j = (j + 1) % N) {
                if (hashTable[j] != -1) {
                    isBefore[j][i] = 1;
                    before[i]++;
                }
            }
        }
    }
    bool* processed = new bool[N]();
    bool flag = true;
    while (flag) {
        int sValue = -1;
        int smallestIndex = -1;
        int i = 0;
        while (i < N) {
            if (hashTable[i] != -1 && !processed[i] && before[i] == 0) {
                if (smallestIndex == -1 || hashTable[i] < sValue) {
                    sValue = hashTable[i];
                    smallestIndex = i;
                }
            }
            i++;
        }
        if (smallestIndex == -1) {
            flag = false;
        }
        if(flag)
        {
            resultSize++;
            result[resultSize-1] = hashTable[smallestIndex];
            processed[smallestIndex] = true;
            int j = 0;
            while ( j < N) {
                if (isBefore[smallestIndex][j]==1) {
                    isBefore[smallestIndex][j] = 0;
                    before[j]--;
                }
                j++;
            }
        }
    }

    if(!outputFileFlag)
    {
        if (resultSize == t && f) {
            for (int i = 0; i < resultSize; i++) {
                cout << result[i];
                if(i!=resultSize-1)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    else
    {
        if (resultSize == t && f) {
            for (int i = 0; i < resultSize; i++) {
                outFile<< result[i];
                if(i!=resultSize-1)
                {
                    outFile<<" ";
                }
            }
            outFile<<endl;
        } else {
            outFile << "Impossible" << endl;
        }
    }
    delete[] processed;
    for (int i = 0; i < N; i++) {
        delete[] isBefore[i];
    }
    delete[] isBefore;
    delete[] before;
    delete[] hashTable;
    delete[] result;

    return 0;
}