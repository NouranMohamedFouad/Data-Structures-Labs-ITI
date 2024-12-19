#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include "StackNode.h"

using namespace std;


class StackLinkedList
{
    private:
        StackNode *tail;

    public:
        StackLinkedList(){
            tail=NULL;
        }
        ~StackLinkedList(){}
        /////////////////////////
        void push(int data)
        {
            StackNode* newNode=new StackNode(data);
            if(tail==NULL)
            {
                tail=newNode;
                return;
            }
            newNode->prev=tail;
            tail=newNode;
        }
        //////////////////////////
        int pop(){
            if(tail==NULL){
                throw -1;
            }
            StackNode *temp=tail;
            int data=tail->data;
            tail=tail->prev;
            delete temp;
            return data;
        }
        //////////////////////////
        int peak(){
            if(tail==NULL){
                throw -1;
            }
            return tail->data;
        }
        //////////////////////////
        void display(){
            if(tail==NULL){
                throw -1;
            }
            StackNode *current=tail;
            while(current!=NULL){
                cout<<current->data<<"\t";
                current=current->prev;
            }
            cout<<"\n";
        }
};

#endif // STACKLINKEDLIST_H
