#ifndef QUEUENODE_H
#define QUEUENODE_H


class QueueNode
{
    public:
        int data;
        QueueNode* next;

        QueueNode(int d){
            data=d;
            next=NULL;
        }
        ~QueueNode(){ }

};

#endif // QUEUENODE_H
