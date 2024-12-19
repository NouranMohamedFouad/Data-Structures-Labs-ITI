#include <iostream>
#include "StackLinkedList.h"
using namespace std;

int main()
{
    StackLinkedList list;
    list.push(30);
    list.push(40);
    list.push(50);
    list.push(60);
    list.push(70);

    try{
        cout<<"\nDisplay:";
        list.display();
        cout<<"\nPeak="<<list.peak()<<endl;
        cout<<list.pop()<<"\t";
        list.display();

        cout<<list.pop()<<"\t";
        list.display();

        cout<<list.pop()<<"\t";
        list.display();

        cout<<list.pop()<<"\t";
        list.display();

        cout<<list.pop()<<"\t";
        list.display();

        cout<<list.pop()<<"\t";
        list.display();
    }
    catch(int msg)
    {
        cout<<"\nthe stack is already empty \n";
    }
    return 0;
}
