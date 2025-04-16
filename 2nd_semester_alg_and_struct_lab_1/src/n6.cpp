#include "n6.hpp"

BinaryPriorityQueue::BinaryPriorityQueue() : heap(nullptr), capacity(0), size(0) {
    capacity = 10;
    heap = new HeapElement[capacity];
}

BinaryPriorityQueue::~BinaryPriorityQueue() {
    for (size_t i = 0; i < size; ++i) {
        delete[] heap[i].value_;
    }
    delete[] heap;
}