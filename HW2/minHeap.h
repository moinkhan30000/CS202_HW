/**
* Title: AVL Trees & Heap
* Author: Moin Khan
* ID: 22101287
* Section : 1
* Homework : 2
* Description : h file for minHeap class where  its functions are declared.
*/
#ifndef HW2_MINHEAP_H
#define HW2_MINHEAP_H
#include <stdexcept>
#include <string>
using namespace std;
const int MAX_HEAP = 100001;
typedef int HeapItemType;
class HeapException : public std::runtime_error {
public:
    HeapException(const std::string& message) : std::runtime_error(message) {}
};

class minHeap {
public:
    minHeap();
    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem) throw(HeapException);
    void heapDelete(HeapItemType& rootItem) throw(HeapException);
    void heapRebuild(int root);
    HeapItemType items[MAX_HEAP];
    int          size;
};


#endif //HW2_MINHEAP_H
