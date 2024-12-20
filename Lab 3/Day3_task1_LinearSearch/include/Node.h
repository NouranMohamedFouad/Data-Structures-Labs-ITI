#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    int index;
    Node* next;
    Node* prev;
    Node(int d,int i){
        data=d;
        index=i;
        next=NULL;
        prev=NULL;
    }
    ~Node(){
    }
};

#endif // NODE_H
