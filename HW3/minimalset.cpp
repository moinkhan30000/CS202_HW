/**
* Title: Hashing
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 3
* Description : Code for Q2
*/
#include "minimalset.h"
#include "fstream"
#include "algorithm"
#include "iostream"
using namespace std;
const int HASH_TABLE_SIZE = 1000000007;
int minimalset::getValue(char x)
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

int minimalset::stringSize(char* charArray)
{
    int length = 0;
    while(charArray[length] != '\0')
    {
        length++;
    }
    return length;
}

int minimalset::Pow(int base, int power)
{
    int result = 1;
    for(int i=0; i<power; i++)
    {
        result = result*base;
    }
    return result;
}

void minimalset::preCalculatePower(int size,int* power, int* power2)
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

int minimalset::calculateHashValue(char* key,int keySize, int* powerArray,int* powerArray2, int& hashVal2)
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


int minimalset::rollHash(int hashValue, char remove, char add, int lengthOfPattern, int* powerArray)
{
    hashValue = (hashValue - ((long long)getValue(remove) * powerArray[lengthOfPattern - 1]) % prime + prime) % prime;
    hashValue = ((long long)hashValue*26)%prime;
    hashValue = hashValue + (getValue(add));
    return hashValue;
}
int minimalset::rollHash2(int hashValue2, char remove, char add, int lengthOfPattern, int* powerArray2)
{
    hashValue2 = (hashValue2 - ((long long)getValue(remove) * powerArray2[lengthOfPattern - 1]) % prime2+ prime2) % prime2;
    hashValue2 = ((long long)hashValue2*37)%prime2;
    hashValue2 = hashValue2 + (getValue(add));
    return hashValue2;
}
int minimalset::binarySearchFirst(hashV* arr, int n, hashV target) {
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
int minimalset::binarySearchLast(hashV* arr, int n, hashV target) {
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
const int maxLength = 100000;
char* minimalset:: reverseString(char* string,int size) {
    char* temp = new char[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = string[size-i-1];
    }
    return temp;
}
int main(int argc, char *argv[]) {
    minimalset ss;
    bool outputFileFlag = true;
    ofstream outFile;
    ifstream file(argv[1]);
    if (argc == 3) {
        outFile.open(argv[2]);
    } else {
        outputFileFlag = false;
    }
    char stringC[ss.MAX_SIZE];
    file.getline(stringC, ss.MAX_SIZE);
    int StringCount = atoi(stringC);
    int powerArray[maxLength];
    int powerArray2[maxLength];
    ss.preCalculatePower(maxLength,powerArray,powerArray2);
    char* patternArray[StringCount];
    int patternSizeArray[StringCount];
    hashV hashArray[StringCount];
    for(int i=0; i<StringCount; i++)
    {
        char* pattern = new char[ss.MAX_SIZE];
        file.getline(pattern, ss.MAX_SIZE);
        patternArray[i] = pattern;
        patternSizeArray[i] = ss.stringSize(pattern);
        hashArray[i].hashValue1 = ss.calculateHashValue(pattern,patternSizeArray[i],powerArray,powerArray2,hashArray[i].hashValue2);
    }
    int rcount = 0;
    int lcount = 0;
    int size = 0;
    for(int i=0; i<StringCount; i++)
    {
        size = size + patternSizeArray[i];
    }
    size = 2*size;
    hashV* allHash;
    int allHashSize = 0;
    char* reversePattern[StringCount];
    for(int i=0; i<StringCount; i++)
    {
        reversePattern[i] = ss.reverseString(patternArray[i],patternSizeArray[i]);
    }
    int flag = 0;
    index iArray[StringCount];
    int setCount = 0;
    int reverseCount = 0;
    while(flag<StringCount)
    {
        allHashSize = 0;
        size = patternSizeArray[flag]*2;
        allHash = new hashV[size];
        char* temp = patternArray[flag];
        char* reverseTemp = reversePattern[flag];
        allHashSize++;
        int h1 = 0;
        int h2 = 0;
        int rh1 = 0;
        int rh2 = 0;
        h1 = ss.calculateHashValue(temp,patternSizeArray[flag],powerArray,powerArray2,h2);
        allHash[allHashSize-1].hashValue1 = h1;
        allHash[allHashSize-1].hashValue2 = h2;
        allHash[allHashSize-1].r = false;
        allHashSize++;
        rh1 = ss.calculateHashValue(reverseTemp,patternSizeArray[flag],powerArray,powerArray2,rh2);
        allHash[allHashSize-1].hashValue1 = rh1;
        allHash[allHashSize-1].hashValue2 = rh2;
        allHash[allHashSize-1].r = true;
        for(int i=1; i<patternSizeArray[flag]; i++)
        {
            allHashSize++;
            char t = temp[i-1];
            char rt = reverseTemp[i-1];
            h1= ss.rollHash(h1,t,t,patternSizeArray[flag],powerArray);
            h2= ss.rollHash2(h2,t,t,patternSizeArray[flag],powerArray2);
            allHash[allHashSize-1].hashValue1 = h1;
            allHash[allHashSize-1].hashValue2 = h2;
            allHash[allHashSize-1].r = false;
            allHashSize++;
            rh1= ss.rollHash(rh1,rt,rt,patternSizeArray[flag],powerArray);
            rh2= ss.rollHash2(rh2,rt,rt,patternSizeArray[flag],powerArray2);
            allHash[allHashSize-1].hashValue1 = rh1;
            allHash[allHashSize-1].hashValue2 = rh2;
            allHash[allHashSize-1].r = true;
        }
        sort(allHash,allHash+(allHashSize), [](const hashV &a, const hashV &b) {
            if (a.hashValue1 != b.hashValue1) return a.hashValue1 < b.hashValue1;
            if (a.hashValue2 != b.hashValue2) return a.hashValue2 < b.hashValue2;
            return a.r < b.r;
        });
        int setBool = false;
        int reverseBool = false;
        int x = -1;

        for(int i=0; i<StringCount; i++)
        {
            if(!hashArray[i].visited)
            {

                x = ss.binarySearchFirst(allHash,allHashSize,hashArray[i]);
                if(x!=-1)
                {
                    hashArray[i].visited = true;
                    setBool = true;
                }
                if(x!=-1 && allHash[x].r)
                {
                    rcount++;

                }
                else if(x!=-1 && !allHash[x].r)
                {
                    lcount++;
                }
                x=-1;
            }
        }
        if(rcount<lcount)
        {
            reverseCount = reverseCount + rcount;
        }
        else
        {
            reverseCount = reverseCount + lcount;
        }
        if(setBool == true)
        {
            setCount++;
        }

        flag++;
        delete[] allHash;
        allHash = nullptr;
        rcount =0;
        lcount = 0;
    }
    if(!outputFileFlag)
    {
        cout<<reverseCount<<endl;
        cout<<setCount<<endl;
        for(int i=0; i<StringCount; i++)
        {
            delete[] patternArray[i];
            delete[] reversePattern[i];
        }
    }
    else
    {
        outFile<<reverseCount<<endl;
        outFile<<setCount<<endl;
        for(int i=0; i<StringCount; i++)
        {
            delete[] patternArray[i];
            delete[] reversePattern[i];
        }

    }
    outFile.close();



}