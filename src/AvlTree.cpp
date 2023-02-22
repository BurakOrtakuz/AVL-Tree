/**
* @file AvlTree.cpp
* @description Avl ağacının sınıfı
* @course Veri yapıları
* @assignment 2
* @date 13 Aralık 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "AvlTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
AvlTree::AvlTree(){
    root=0;
    int totalLenght=0;
    Queue *queue;
    std::ifstream readTxt("./doc/Noktalar.txt");
    readTxt.seekg(0);    
    while(!readTxt.eof()){      
        std::string rowData="";     
        getline(readTxt,rowData);
        queue=new Queue();
        int counter=0;
        int x,y,z;
        bool control=false;
        while(rowData!=""){
            std::stringstream ss;
            int x2,y2,z2;
            int gettedData;
            int position=rowData.find(' ');
            position=rowData.find(' ',position+1);
            position=rowData.find(' ', position+1);
            std::string firstTreeData=rowData.substr(0,position);
            ss<< firstTreeData.substr(0,firstTreeData.find(' '));        
            ss>>x2;
            std::stringstream ss2;
            firstTreeData=firstTreeData.substr(firstTreeData.find_first_of(' ')+1,firstTreeData.length()-firstTreeData.find_first_of(' '));
            ss2<< firstTreeData.substr(0,firstTreeData.find(' '));        
            ss2>>y2;
            std::stringstream ss3;
            firstTreeData=firstTreeData.substr(firstTreeData.find_first_of(' ')+1,firstTreeData.length()-firstTreeData.find_first_of(' '));
            ss3<< firstTreeData;        
            ss3>>z2;

            rowData=rowData.substr(position+1,rowData.length()-position-1);
            queue->enqueue(x2,y2,z2);
            if(control){
                totalLenght+=std::sqrt(((x-x2)*(x-x2))+((y-y2)*(y-y2))+((z-z2)*(z-z2)));
            }
            x=x2;y=y2;z=z2;
            control=true;
        }
        insert(queue,totalLenght);
        totalLenght=0;
    }
    
};
AvlTree::~AvlTree(){
    remove(root);
}

void AvlTree::insert(Queue* data,int lenght){
    root=insertFunction(root,data,lenght);

};
void AvlTree::remove(){
    remove(root);
    root=0;
};
void AvlTree::postOrderTreversal(){
    postOrder(root);
};
void AvlTree::remove(Node* currentData){

    if(currentData!=0){
        remove(currentData->left);
        remove(currentData->right);
        delete currentData;
    }
}
//Private Fonksiyonlar
Node* AvlTree::rotateRight(Node* parentNode){
    Node* leftChild=parentNode->left;
    parentNode->left=leftChild->right;
    leftChild->right=parentNode;
    return leftChild;
};
Node* AvlTree::rotateLeft(Node* parentNode){
    Node* rightChild=parentNode->right;
    parentNode->right=rightChild->left;
    rightChild->left=parentNode;
    return rightChild;
};
Node* AvlTree::insertFunction(Node* currentNode ,Queue* data,int lenght){
    if(currentNode==0){
        return new Node(data,lenght);
    }else if(currentNode->totalLenght>=lenght){
        currentNode->left=insertFunction(currentNode->left,data,lenght);
        if(height(currentNode->left)-height(currentNode->right)>1){
            if(lenght<currentNode->left->totalLenght){
                currentNode=rotateRight(currentNode);
            }else{
                currentNode->left=rotateLeft(currentNode->left);
                currentNode=rotateRight(currentNode);
            }
        }
    }else{
        currentNode->right=insertFunction(currentNode->right,data,lenght);
         if(height(currentNode->right)-height(currentNode->left)>1){
            if(lenght>currentNode->right->totalLenght){
                currentNode=rotateLeft(currentNode);
            }else{
                currentNode->right=rotateRight(currentNode->right);
                currentNode=rotateLeft(currentNode);
            }
        }
    }
    return currentNode;
    

};
void AvlTree::postOrder(Node* a){
    if(a!=0){
        postOrder(a->left);
        postOrder(a->right);
        while(!a->data->isEmpty()){
            std::cout<<a->data->peekOrigin()<<" ";
            a->data->dequeue();
        }
        std::cout<<std::endl;

    }
};
int AvlTree::height(Node* currentNode){

    if(currentNode){
        return 1+std::max(height(currentNode->left),height(currentNode->right));
    }
    return -1;

};
