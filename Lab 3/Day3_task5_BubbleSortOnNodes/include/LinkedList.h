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
    //////////////////////////////////////
    Node* removeNodeForSwap(Node* node)
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
        node->prev=NULL;
        node->next=NULL;
        return node;
    }
    /////////////////////////////////////
    void swapNodes(Node* a,Node* b)
    {

    }


public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        counter=0;
    }
    ///////////////////////////////////
    ~LinkedList(){
        delete head;
        delete tail;
    }
    ////////////////////////////////////
    int add(int data)
    {
        counter++;
        Node* newNode=new Node(data);
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
            cout<<"data="<<current->data<<" \t";
            current=current->next;
        }
        cout<<"\n";
    }
    //////////////////////////////////////
    int validateFindNode(int data)
    {
        Node* result=getNodeByData(data);
        if(result==NULL)
        {
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
    int insertAfter(Node* newNode,Node* result)
    {
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
    int insertBefore(int data,int beforeData)
    {
        Node* result=getNodeByData(beforeData);
        Node* newNode=new Node(data);

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
    ///////////////////////////////////////////
    int bubbleSortOnNodes()
    {
        int iterations=0;
        int sorted=0;
        int size=counter;
        for(int outer=0;sorted==0;outer++){
           sorted=1;
           Node* current=head;
            for(int i=0;i<size-1-outer;i++)
            {
                if(current->data > current->next->data)
                {
                    Node* temp=current;
                    current=current->next;
                    Node* removedNode=removeNodeForSwap(temp);
                    cout<<"Removed node value: "<<removedNode->data<<endl;
                    insertAfter(removedNode,current);
                    sorted=0;
                }
                else{
                    current=current->next;

                }
                iterations++;
            }
        }
        return iterations;
    }

};

#endif // LINKEDLIST_H
