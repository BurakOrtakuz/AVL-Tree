#ifndef AvlNode_hpp
#define AvlNode_hpp
#include "Queue.hpp"

class Node{
     public:
     Node(Queue* data,int totalLenght);
     ~Node();
     Queue* data;
     Node* left;
     Node* right;
     int totalLenght;
};
#endif