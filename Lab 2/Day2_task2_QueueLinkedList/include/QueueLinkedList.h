#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

#include "QueueNode.h"

using namespace std;

class QueueLinkedList
{
    QueueNode* front;
    QueueNode* rear;
    public:
        QueueLinkedList()
        {
            front=rear=NULL;
        }
        ///////////////////////////
        void enqueue(int data){
            QueueNode *newNode=new QueueNode(data);
            if(front==NULL){
                rear=front=newNode;
                return;
            }
            rear->next=newNode;
            rear=newNode;
        }
        /////////////////////////
        int dequeue(){
            int data=0;
            if(front==NULL){
                throw -1;
            }
            QueueNode *temp=front;
            data=front->data;
            front=front->next;
            if(front==NULL){
                    rear=NULL;
            }
            delete temp;
            return data;
        }
        //////////////////////////
        void display()
        {
            if(front==NULL)
            {
                throw -1;
            }
            QueueNode *current=front;
            while(current!=NULL){
                cout<<current->data<<"\t";
                current=current->next;
            }
            cout<<"\n";
        }
        ///////////////////////////
        ~QueueLinkedList()
        {
            delete front;
            delete rear;
        }
};

#endif // QUEUELINKEDLIST_H
