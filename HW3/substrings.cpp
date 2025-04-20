/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : Code for Q1
*/

#include "substrings.h"
#include "algorithm"
const int HASH_TABLE_SIZE = 1000000007;
int substrings::getValue(char x)
{
    switch (x) {
        case 'a': return 1;
        case 'b': return 2;
        case 'c': return 3;
        case 'd': return 4;
        case 'e': return 5;
        case 'f': return 6;
        case 'g': return 7;
        case 'h': return 8;
        case 'i': return 9;
        case 'j': return 10;
        case 'k': return 11;
        case 'l': return 12;
        case 'm': return 13;
        case 'n': return 14;
        case 'o': return 15;
        case 'p': return 16;
        case 'q': return 17;
        case 'r': return 18;
        case 's': return 19;
        case 't': return 20;
        case 'u': return 21;
        case 'v': return 22;
        case 'w': return 23;
        case 'x': return 24;
        case 'y': return 25;
        case 'z': return 26;
        default: return -1; // For invalid inputs
    }
}

int substrings::stringSize(char* charArray)
{
    int length = 0;
    while(charArray[length] != '\0')
    {
        length++;
    }
    return length;
}

int substrings::Pow(int base, int power)
{
    int result = 1;
    for(int i=0; i<power; i++)
    {
        result = result*base;
    }
    return result;
}

void substrings::preCalculatePower(int size,int* power, int* power2)
{
    long long result = 1;
    int base = 26;
    int base2 = 37;
    long long result2 = 1;
    power[0] = 1;
    power2[0] = 1;
    for(int i=1; i<size; i++)
    {
        power[i] = (result*base)%prime;
        result = power[i];
        power2[i] = (result2*base2)%prime2;
        result2 = power2[i];
    }

}

int substrings::calculateHashValue(char* key,int keySize, int* powerArray,int* powerArray2, int& hashVal2)
{
    int hashVal = 0;
    int power = 1;
    int base = 26;
    for (int i = 0; i < keySize; i++) {
        hashVal = (hashVal + ((long long)getValue(key[i])*powerArray[keySize-1-i]))%prime;
        hashVal2 = (hashVal2 + ((long long)getValue(key[i])*powerArray2[keySize-1-i]))%prime2;
    }
    return hashVal;
}


int substrings::rollHash(int hashValue, char remove, char add, int lengthOfPattern, int* powerArray)
{
    hashValue = (hashValue - ((long long)getValue(remove) * powerArray[lengthOfPattern - 1]) % prime + prime) % prime;
    hashValue = ((long long)hashValue*26)%prime;
    hashValue = hashValue + (getValue(add));
    return hashValue;
}
int substrings::rollHash2(int hashValue2, char remove, char add, int lengthOfPattern, int* powerArray2)
{
    hashValue2 = (hashValue2 - ((long long)getValue(remove) * powerArray2[lengthOfPattern - 1]) % prime2+ prime2) % prime2;
    hashValue2 = ((long long)hashValue2*37)%prime2;
    hashValue2 = hashValue2 + (getValue(add));
    return hashValue2;
}
int substrings::binarySearchFirst(hashV* arr, int n, hashV target) {
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].hashValue1 < target.hashValue1 ||
            (arr[mid].hashValue1 == target.hashValue1 && arr[mid].hashValue2 < target.hashValue2)) {
            low = mid + 1;
        } else if (arr[mid].hashValue1 > target.hashValue1 ||
                   (arr[mid].hashValue1 == target.hashValue1 && arr[mid].hashValue2 > target.hashValue2)) {
            high = mid - 1;
        } else {
            result = mid;
            high = mid - 1;
        }
    }
    return result;
}
int substrings::binarySearchLast(hashV* arr, int n, hashV target) {
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].hashValue1 < target.hashValue1 ||
            (arr[mid].hashValue1 == target.hashValue1 && arr[mid].hashValue2 < target.hashValue2)) {
            low = mid + 1;
        } else if (arr[mid].hashValue1 > target.hashValue1 ||
                   (arr[mid].hashValue1 == target.hashValue1 && arr[mid].hashValue2 > target.hashValue2)) {
            high = mid - 1;
        } else {
            result = mid;
            low = mid + 1;
        }
    }
    return result;
}


int main(int argc, char *argv[]) {
    substrings ss;
    bool outputFileFlag = true;
    ofstream outFile;
    ifstream file(argv[1]);
    if (argc == 3)
    {
        outFile.open(argv[2]);
    }
    else
    {
        outputFileFlag = false;
    }

    char mainString[ss.MAX_SIZE];
    file.getline(mainString, ss.MAX_SIZE);
    int mainStringLength = ss.stringSize(mainString);
    char patternC[ss.MAX_SIZE];
    file.getline(patternC, ss.MAX_SIZE);
    int patternCount = atoi(patternC);
    char* firstPattern = new char[ss.MAX_SIZE];
    file.getline(firstPattern, ss.MAX_SIZE);
    int minPatternLength = ss.stringSize(firstPattern);
    int powerSize = minPatternLength + 5;
    int powerArray[powerSize];
    int powerArray2[powerSize];
    ss.preCalculatePower(powerSize,powerArray,powerArray2);
    char* patternArray[patternCount];
    int patternSizeArray[patternCount];
    hashV hashArray[patternCount];
    patternArray[0] = firstPattern;
    patternSizeArray[0] = minPatternLength;
    hashArray[0].hashValue1 = ss.calculateHashValue(patternArray[0],minPatternLength,powerArray,powerArray2,hashArray[0].hashValue2);

    for(int i=1; i<patternCount; i++)
    {
        char* pattern = new char[ss.MAX_SIZE];
        file.getline(pattern, ss.MAX_SIZE);
        patternArray[i] = pattern;
        patternSizeArray[i] = ss.stringSize(pattern);
        hashArray[i].hashValue1 = ss.calculateHashValue(pattern,patternSizeArray[i],powerArray,powerArray2,hashArray[i].hashValue2);
    }
    int patternCArray[patternCount];



    int m = 0;
    while(m<patternCount)
    {
        patternCArray[m] = 0;
        int size = patternSizeArray[m];
        hashV searchArray[mainStringLength-size+1];
        int h2 =0;
        int h1 = ss.calculateHashValue(mainString+0,size,powerArray,powerArray2,h2);
        searchArray[0].hashValue1 = h1;
        searchArray[0].hashValue2 = h2;
        for(int i=1; i<mainStringLength-size+1; i++)
        {
            h1 = ss.rollHash(h1,mainString[i-1],mainString[i+size-1],size,powerArray);
            h2 = ss.rollHash2(h2,mainString[i-1],mainString[i+size-1],size,powerArray2);
            searchArray[i].hashValue1 = h1;
            searchArray[i].hashValue2 = h2;
        }
        sort(searchArray,searchArray+(mainStringLength-size+1), [](const hashV& a, const hashV& b) {
            return (a.hashValue1 == b.hashValue1) ? (a.hashValue2 < b.hashValue2) : (a.hashValue1 < b.hashValue1);
        });
        int indexF = ss.binarySearchFirst(searchArray,mainStringLength-size+1,hashArray[m]);
        int indexL = ss.binarySearchLast(searchArray,mainStringLength-size+1,hashArray[m]);
        if(indexF ==-1)
        {
            patternCArray[m] = 0;
        }
        else
        {
            patternCArray[m] = indexL - indexF + 1;
        }
        m++;
    }
    if(!outputFileFlag)
    {
        for(int i =0; i<patternCount; i++)
        {
            cout<<patternCArray[i]<<endl;
            delete[] patternArray[i];
        }
    }
    else
    {
        for(int i =0; i<patternCount; i++)
        {
            outFile<<patternCArray[i]<<endl;
            delete[] patternArray[i];
        }
    }
    outFile.close();



}