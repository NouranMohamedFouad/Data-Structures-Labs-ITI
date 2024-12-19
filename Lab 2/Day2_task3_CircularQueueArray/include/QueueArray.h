#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H


class QueueArray
{
    int *items;
    int front;
    int rear;
    int size ;
    public:
        QueueArray(int s){
            size=s;
            items=new int[size];
            front=rear=-1;

        }
        /////////////////////////////////
        int isEmpty(){
            if(front==-1 && rear==-1){
                return 1;
            }
            return 0;
        }
        /////////////////////////////////
        int isFull(){
            if(front==0 && rear==size-1){
                return 1;
            }
            if(rear==front-1){
                return 1;
            }
            return 0;
        }
       //////////////////////////////////
       int enqueue(int data){
           if(isFull()){
                return 0;
           }
           if(isEmpty()){
            rear=front=0;
           }
           else if(rear==size-1 && front !=0){
               rear=0;
           }
           else{
            rear++;
           }
           items[rear]=data;
           return 1;
       }
       //////////////////////////////////
       int dequeue()
       {
           if(isEmpty()){
            throw -1;
           }
           int data=items[front];
           items[front]=0;
           if(rear==front){
               rear=front=-1;
           }
           else if(front==size-1){
               front=0;
           }
           else
           {
               front++;
           }
           return data;
        }
        ///////////////////////////////////
        ~QueueArray()
        {
            delete[] items;

        }

    protected:

    private:
};

#endif // QUEUEARRAY_H
