#ifndef N5_HPP
#define N5_HPP

#include <cstddef>



class PriorityQueue {
    protected:
        struct QueueElement {
            int key_;
            char* value_;
            QueueElement* next;
        };
        QueueElement* head;
        size_t size;
        
    public:
        PriorityQueue();
        virtual ~PriorityQueue();

        virtual void insert(int key, const char* value) = 0;
        virtual const char* peek() const = 0;
        virtual void pop() = 0;
        virtual PriorityQueue& merge(const PriorityQueue& other) = 0;
        
        bool isEmpty() const;
}


#endif