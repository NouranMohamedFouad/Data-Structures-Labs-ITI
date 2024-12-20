#include <iostream>

#include "LinkedList.h"

using namespace std;

///////////////////////////////////////////

int linearSearchOneItem(int *arr,int size,int item)
{
    int index=-1;
    int iteration=0;
    for(int i=0;i<size;i++)
    {
        iteration++;
        if(arr[i]==item)
        {
            index=i;
            cout<<"number of iterations for linear search to get the target element="<<iteration<<endl;
            return index;
        }
    }
    return index;
}

///////////////////////////////////////////

//////////////BONUS///////////////////////
int linearSearchItems(int *arr,int size,int item,LinkedList& list)
{
    int index=-1;
    int iteration=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==item)
        {
            index=i;
            list.add(item,index);

        }
        iteration++;
    }
    cout<<"number of iterations for linear search for all occurrences ="<<iteration<<endl;
    return index;
}
///////////////////////////////////////////
int main()
{
    int arr[10]={5,10,2,6,20,3,6,5,2,10};
    LinkedList list1;
    int index1=linearSearchItems(arr,10,2,list1);
    if(index1==-1)
        cout<<"number is not found\n";
    else
        list1.display();


    int index2=linearSearchOneItem(arr,10,2);
    index2==-1?cout<<"number is not found\n" :cout<<"number is found at index="<<index2<<endl;

    return 0;
}
