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
    ~Node(){
    }
};

#endif // NODE_H
