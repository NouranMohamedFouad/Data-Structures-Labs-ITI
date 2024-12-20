#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
     LinkedList list;
    list.add(100);
    list.display();
    list.add(70);
    list.display();
    list.add(15);
    list.display();
    list.add(20);
    list.display();
    list.add(25);
    list.display();
    list.add(50);
    list.display();
    list.add(40);
    list.display();
    list.add(45);
    list.display();


    cout<<endl<<endl<<endl<<"after Bubble Sort:\n";
    list.bubbleSort();
    list.display();

    return 0;
}
