#ifndef STACKNODE_H
#define STACKNODE_H


class StackNode
{
    public:
        int data;
        StackNode *prev;
        StackNode(int d){
            data=d;
            prev=NULL;
        }
        ~StackNode(){
        }
};

#endif // STACKNODE_H
