#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int counter;
    //////////helper functions/////////////
    Node* getNodeByData(int data)
    {
        Node* current=head;
        if(current==NULL)
        {
            cout<<"linked list is empty \n";
            return current;
        }
        while(current!=NULL)
        {
            if(current->data==data){
                return current;
            }
            current=current->next;
        }
        return NULL;
    }
    //////////////////////////////////////
    void removeNode(Node* node)
    {
        if(node==head)
        {
            if(node==tail)
            {
                tail=head=NULL;

            }
            else
            {
                head=head->next;
                head->prev=NULL;
            }
        }
        else if(node==tail)
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        else
        {
            Node* before=node->prev;
            Node* after=node->next;
            before->next=after;
            after->prev=before;
        }
        counter--;
        delete node;
    }
    /////////////////////////////////////


public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        counter=0;
    }
    ///////////////////////////////////
    ~LinkedList(){
    }
    ////////////////////////////////////
    int add(int data,int index)
    {
        counter++;
        Node* newNode=new Node(data,index);
        if(head==NULL)
        {
            head=tail=newNode;
            return 1;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return 1;
    }
    /////////////////////////////////////
    void display()
    {
        Node* current=head;
        if(current==NULL){
            cout<<"the linked list is already empty \n";
            return;
        }
        while(current!=NULL)
        {
            cout<<"data="<<current->data<<",index="<<current->index<<"\t";
            current=current->next;
        }
        cout<<"\n";
    }
    /////////////////////////////////////
    int validateFindNode(int data)
    {
        Node* result=getNodeByData(data);
        if(result==NULL){
            return 0;
        }
        return 1;
    }
    //////////////////////////////////////
    int removeNodeByData(int data)
    {
        Node* result=getNodeByData(data);
        if(result==NULL)
        {
            return 0;
        }
        else if(result==head)
        {
            if(result==tail)
            {
                tail=head=NULL;
            }
            else
            {
                head=head->next;
                head->prev=NULL;
            }
        }
        else if(result==tail)
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            Node* before=result->prev;
            Node* after=result->next;
            before->next=after;
            after->prev=before;
        }
        delete result;
        counter--;
        return 1;
    }
    /////////////////////////////////////////
    int removeAll(int data){
        Node* current=head;
        Node* temp=NULL;
        if(current==NULL){
            return 0;
        }
        while(current!=NULL)
        {
            temp=current;
            current=current->next;
            if(temp->data==data)
            {
                removeNode(temp);
            }
        }
        return 1;
    }
    //////////////////////////////////////////
    int insertAfter(int index,int data,int afterData)
    {
        Node* result=getNodeByData(afterData);
        Node* newNode=new Node(data,index);

        if(result==NULL)
        {
            return 0;
        }
        counter++;
        if(result==tail)
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            return 1;
        }

        newNode->next=result->next;
        result->next=newNode;
        newNode->prev=result;
        return 1;

    }
    //////////////////////////////////////////
    int insertBefore(int index,int data,int beforeData)
    {
        Node* result=getNodeByData(beforeData);
        Node* newNode=new Node(data,index);

        if(result==NULL)
        {
            return 0;
        }
        counter++;
        if(result==head)
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return 1;
        }
        Node* beforeResult=result->prev;

        newNode->next=result;
        newNode->prev=beforeResult;
        beforeResult->next=newNode;
        result->prev=newNode;
        return 1;

    }
    //////////////////////////////////////////
    int GetDataByIndex(int index)
    {
        int i=0;
        Node* current=head;
        while(current!=NULL)
        {
            if(i==index)
            {
                return current->data;
            }
            current=current->next;
            i++;
        }
        return -1;
    }
    //////////////////////////////////////////
    int getCounter()
    {
        return counter;
    }


};

#endif // LINKEDLIST_H
