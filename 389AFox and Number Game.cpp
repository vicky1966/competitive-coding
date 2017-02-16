#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int findmax(int arr[],int start,int end)
{
	int index;
	int max=-9999;
	for(int i=start;i<=end;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			index=i;
		}
	}
	return index;
}

int main()
{
	int n;	cin>>n;
	int max=-99999;
	int arr[n];
	int index;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int start=0;
	for(int j=n-1;j>0;j--)
	{
		int index = findmax(arr,start,j-1);
		for(int k=j;j>index;j--)
		{
			arr[k]=arr[k]-arr[index];
		}
		j=index+1;
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}	
	cout<<sum;
}
