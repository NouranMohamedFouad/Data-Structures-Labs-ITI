#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;
    list.add(5);
    list.display();
    list.add(15);
    list.display();
    list.add(20);
    list.display();
    list.add(25);
    list.display();
    list.add(12);
    list.display();
    list.add(25);
    list.display();
    list.add(15);
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
    list.add(25);
    list.display();
    list.validateFindNode(22)?cout<<"Data Found \n":cout<<"Data Not Found \n";
    list.removeNodeByData(25)?cout<<"Data Deleted \n":cout<<"Data Not Deleted,it is not found \n";
    list.display();
    cout<<"linked list contains "<<list.getCounter()<<" nodes \n";

    list.removeAll(25)?cout<<"ALL Data Deleted \n":cout<<"Data Not Deleted,it is not found \n";
    list.display();
    cout<<"linked list contains "<<list.getCounter()<<" nodes \n";

    list.insertAfter(600,40)?cout<<"Data inserted after  \n":cout<<"Data after is Not inserted,data is not found \n";
    list.display();
    cout<<"linked list contains "<<list.getCounter()<<" nodes \n";


    list.insertBefore(500,40)?cout<<"Data inserted Before \n":cout<<"Data Before is Not inserted,data is not found \n";
    list.display();
    cout<<"linked list contains "<<list.getCounter()<<" nodes \n";


    list.insertBefore(850,5)?cout<<"Data inserted Before \n":cout<<"Data Before is Not inserted,data is not found \n";
    list.display();
    cout<<"linked list contains "<<list.getCounter()<<" nodes \n";

    list.insertBefore(850,555)?cout<<"Data inserted Before \n":cout<<"Data Before is Not inserted,data is not found \n";




    int result =list.GetDataByIndex(6);
    if(result==-1){
        cout<<"Index is not found \n";
    }
    else
    {
        cout<<"value for the chosen index is "<<result<<"\n";
    }


    return 0;
}
