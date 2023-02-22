#ifndef Queue_hpp
#define Queue_hpp
#include "QueueNode.hpp"
class Queue{
public:
    Queue();
    ~Queue();
    void enqueue(int x,int y,int z);
    void dequeue();
    bool isEmpty();
    int peekOrigin();
    int distanceToOrigin(int* arrayToCalculate); 
    void remove();
    
private:    
    QueueNode* beforeMostPriortyNode();       
    QueueNode* head;
    QueueNode* tail;
};
#endif