#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std;


void exchange(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int start,int end)
{
    int i=start-1;
    int pivot=arr[end];
    int j;
    for(j=start;j<=end-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            exchange(&arr[i],&arr[j]);
            for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
		cout<<endl<<endl;
        }
        
    }
    
    
    exchange(&arr[i+1],&arr[end]);
    for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
		cout<<endl<<endl;
    return (i+1);
    
}

void quicksort(int arr[],int start,int end)
{
    int p;
    if(start < end)
    {
        p=partition(arr,start,end);
        //cout<<p<<" ";
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}


int main()
{
	
	int arr[] = {1, 4, 45, 6, 10, -8};
	quicksort(arr,0,5);
	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
}
