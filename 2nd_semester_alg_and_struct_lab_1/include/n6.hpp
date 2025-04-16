#ifndef N6_HPP
#define N6_HPP

#include "n5.hpp"

class BinaryPriorityQueue : public PriorityQueue {
    private:
        struct HeapElement {
            int key_;
            char* value_;
        };
        HeapElement* heap;
        size_t capacity;
        size_t size;

        void heapifyUp(size_t index);
        void heapifyDown(size_t index);
        void resizeHeap();
    public:
        BinaryPriorityQueue();
        ~BinaryPriorityQueue();


        void insert(int key, const char* value) override;
        const char* peek() const override;
        void pop() override;
        PriorityQueue& merge(const PriorityQueue& other) override;
}

#endif