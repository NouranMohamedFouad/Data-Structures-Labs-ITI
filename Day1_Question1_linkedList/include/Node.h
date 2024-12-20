#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T d){
        data=d;
        next=NULL;
        prev=NULL;
    }
    ~Node(){
    }
};

#endif // NODE_H
