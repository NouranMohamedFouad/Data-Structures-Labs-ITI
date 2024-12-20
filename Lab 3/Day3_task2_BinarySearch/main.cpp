#include <iostream>

using namespace std;


void swapArray(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
////////////////////////////////////////////////
int bubbleSort(int* arr,int size){
    int iterations=0;
    int sorted=0;
    for(int outer=0;sorted==0;outer++){
        sorted=1;
        for(int i=0;i<size-1-outer;i++){
            if(arr[i]>arr[i+1]){
                swapArray(arr[i],arr[i+1]);
                sorted=0;
            }
            iterations++;
        }
    }
    return iterations;
}
/////////////////////////////////////////////////////////
int binarySearch(int *arr,int size,int search)
{
    int start=0,end=size-1,mid=0,iterations=0;
    while(start<=end)
    {
        iterations++;
        mid=(start+end)/2;
        if(arr[mid]==search)
        {
            cout<<"number of iterations for binary search to get the target element="<<iterations<<endl;
            return mid;
        }
        else if(arr[mid]>search){
            end=mid-1;
        }
        else if(arr[mid]<search){
            start=mid+1;
        }
    }
    cout<<"total number of iterations for binary search="<<iterations<<endl;

    return -1;
}


int main()
{
    int arr[10]={5,10,2,6,20,3,6,5,2,10};
    bubbleSort(arr,10);
    cout<<"\nArray after sort:\n";

    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

    int index=binarySearch(arr,10,20);
    index==-1?cout<<"number is not found\n" :cout<<"number is found at index="<<index<<endl;

    return 0;
}
