/**
* @file AvlNode.cpp
* @description Avl ağacının düğümü
* @course Veri yapıları
* @assignment 2
* @date 13 Aralık 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "AvlNode.hpp"
#include <iostream>
Node::Node(Queue* data,int totalLenght){
    left=0;
    right=0;
    this->data=data;
    this->totalLenght=totalLenght;
}
Node::~Node(){
    delete data;
}