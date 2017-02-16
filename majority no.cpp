#include<iostream>
using namespace std;


int findcad(int arr[],int n)
{
	int can;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(count==0)
		{
			can=arr[i];
			count++;
		}
		else
		{
			if(arr[i]==can)
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		
	}return can;
}

bool ismajority(int arr[],int n,int candidate)
{
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]==candidate)
			count++;
		if(count> n/2)
			return true;
	}
	if(count<=(n/2))
	return false;
}

void printmajority(int arr[],int n)
{
	int candidate = findcad(arr,n);
	cout<<candidate<<endl;
	if(ismajority(arr,n,candidate))
		cout<<candidate<<endl;
	else
		cout<<"NO Majority Element"<<endl;
}


int main()
{
	int t;	cin>>t;
	while(t--)
	{
		int size;	cin>>size;
		int arr[size];
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
		printmajority(arr,size);
	}
	getchar();
}
