#include <iostream>
#include "QueueLinkedList.h"
using namespace std;

int main()
{
    QueueLinkedList list;
    list.enqueue(30);
    list.enqueue(40);
    list.enqueue(50);
    list.enqueue(60);
    list.enqueue(70);

    try{
        cout<<"\nDisplay:";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();

        cout<<list.dequeue()<<"\t";
        list.display();
    }
    catch(int msg)
    {
        cout<<"\nthe Queue is already empty \n";
    }
    return 0;
}
