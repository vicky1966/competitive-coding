#include<iostream>
using namespace std;

int main()
{
	int n;	cin>>n;
	int arr[n];
	int oddcount=0;
	int evencount=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]%2==0)
		{
			oddcount++;
		}
		else
		{
			evencount++;
		}
		sum+=arr[i];
	}
	if(sum%2==0)
	cout<<oddcount;
	else
	cout<<evencount;
}
