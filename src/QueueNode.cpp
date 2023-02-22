/**
* @file QueueNode.cpp
* @description Kuyruk yapısının düğümü
* @course Veri yapıları
* @assignment 2
* @date 13 Aralık 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
#include <iostream>
QueueNode::QueueNode(int x,int y,int z){
    this->next=0;
    array=data;
    data[0]=x;
    data[1]=y;
    data[2]=z;
}
QueueNode::~QueueNode(){
}
