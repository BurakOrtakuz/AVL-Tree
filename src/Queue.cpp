/**
* @file Queue.cpp
* @description Kuyruk yapısı
* @course Veri yapıları
* @assignment 2
* @date 13 Aralık 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
#include <iostream>
#include <math.h>
Queue::Queue(){
    head=0;
    tail=0;
}
Queue::~Queue(){
    remove();
}
void Queue::enqueue(int x,int y,int z){
    QueueNode* temp= new QueueNode(x,y,z);
    if(head==0){
        head=temp;
        tail=temp;
    }else{
        tail->next=temp;
        tail=temp;
    }    
}
void Queue::dequeue(){
    QueueNode* temp=beforeMostPriortyNode();
    if(temp!=0){ 
        if(temp->next==tail){
            tail=temp;
        } 
        QueueNode* deletedNode= temp->next;
        temp->next=deletedNode->next;
        delete deletedNode;
    }else{
        if(head==0) return;
        QueueNode* deletedNode=head;
        head=head->next;
        delete deletedNode;
    }
}
void Queue::remove(){
        while(!isEmpty()){
        dequeue();
    }
}
int Queue::peekOrigin(){
    if(head!=0){
        if(beforeMostPriortyNode()!=0){
            return distanceToOrigin(beforeMostPriortyNode()->next->array);
        }else{
            return distanceToOrigin(head->array);
        }    
    }           
    throw std::out_of_range("Kuyruk Bos");    
}

bool Queue::isEmpty(){
    if(head==0)
        return true;
    return false;    
}
QueueNode* Queue::beforeMostPriortyNode(){
    if(head==0) return 0;
    QueueNode* temp= head;
    QueueNode* before=0;
    int nearestOrigin=distanceToOrigin(head->array);
    while(temp->next!=0){
        int tempOrigin=distanceToOrigin(temp->next->array);
        if(tempOrigin<nearestOrigin){
            nearestOrigin=tempOrigin;
            before=temp;
        }
        temp=temp->next;
    }
    return before;
}
int Queue::distanceToOrigin(int* arrayToCalculate){
    int x=*arrayToCalculate;
    int y=*(arrayToCalculate+1);
    int z=*(arrayToCalculate+2);

    int distance=std::sqrt(x*x+y*y+z*z);
    return distance;
}
