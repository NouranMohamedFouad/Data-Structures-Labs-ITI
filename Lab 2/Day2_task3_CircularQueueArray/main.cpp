#include <iostream>
#include "QueueArray.h"

using namespace std;


int main()
{
    QueueArray arr(5);
    arr.enqueue(30)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(40)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(50)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(60)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(70)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(80)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(90)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";
    arr.enqueue(100)?cout<<"data entered successfully\n":cout<<"data failed to be entered\n";

    try
    {
        cout<<arr.dequeue()<<"\t";
        cout<<arr.dequeue()<<"\t";
        cout<<arr.dequeue()<<"\t";
        cout<<arr.dequeue()<<"\t";
        cout<<arr.dequeue()<<"\t";
        cout<<arr.dequeue()<<"\t";
    }
    catch(int msg)
    {
        cout<<"\nthe Queue is already empty \n";
    }
    return 0;
}
