#ifndef AvlTree_hpp
#define AvlTree_hpp
#include "AvlNode.hpp"
class AvlTree{
public:
    AvlTree();
    ~AvlTree();
    void insert(Queue* data,int lenght);
    void remove();
    void postOrderTreversal();
    void becauseTrigger(Node* a);
private:
    void remove(Node* currentNode);
    Node* rotateLeft(Node* parentNode);
    Node* rotateRight(Node* parentNode);
    int height(Node* currentNode);
    void postOrder(Node* a);
    Node* insertFunction(Node* currentNode,Queue* data,int lenght);
    Node* root;
};
#endif