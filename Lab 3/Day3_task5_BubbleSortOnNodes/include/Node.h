#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
    Node(Node& n2){
        this->data=n2.data;
        n2.next=this->next;
        n2.prev=this->prev;
    }
    ~Node(){
    }
};

#endif // NODE_H
