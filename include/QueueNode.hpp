#ifndef  QueueNode_hpp
#define QueueNode_hpp

class QueueNode{
public:    
    QueueNode(int x,int y,int z);  
    QueueNode* next;
    ~QueueNode();
    int* array;
private:
    int data[3];
};

#endif