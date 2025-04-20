/**
* Title: AVL Trees & Heap
* Author: Moin Khan
* ID: 22101287
* Section : 1
* Homework : 2
* Description : minHeap class cpp files to create minHeap structure and to define functions used for that purpose that were declared in its .h file.
*/

#include "minHeap.h"
minHeap:: minHeap() : size(0) {

}


bool minHeap::heapIsEmpty() const {
    return (size == 0);
}
void minHeap::heapInsert(const HeapItemType&newItem) throw(HeapException) {

    if (size >= MAX_HEAP)
        throw HeapException("HeapException: Heap full");
    items[size] = newItem;


    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] < items[parent]) ) {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}
void minHeap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;
        if ((rightChild < size) && (items[rightChild] < items[child]))
            child = rightChild;
        if (items[root] > items[child]) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }

}
void minHeap::heapDelete(HeapItemType&rootItem) throw(HeapException) {
    if (heapIsEmpty())
        throw HeapException("HeapException: Heap empty");
    else {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}
