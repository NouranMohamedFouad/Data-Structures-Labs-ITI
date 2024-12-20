#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;
    list.add(5);
    list.display();
    list.add(15);
    list.display();
    list.add(20);
    list.display();
    list.add(25);
    list.display();
    list.add(30);
    list.display();
    list.add(25);
    list.display();
    list.add(50);
    list.display();
    list.add(40);
    list.display();
    list.add(45);
    list.display();

    cout<<endl<<endl<<endl<<"after Linear search:\n";
    int index=list.linearSearch(45);
    index==-1?cout<<"number is not found\n" :cout<<"number is found at index="<<index<<endl;


    cout<<endl<<endl<<endl<<"after Bubble Sort:\n";
    list.bubbleSort();
    list.display();

    cout<<endl<<endl<<endl<<"after Binary search:\n";

    int index2=list.binarySearch(45);
    index2==-1?cout<<"number is not found\n" :cout<<"number is found at index="<<index2<<endl;




    return 0;
}
