#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr,arr+n);
	//cout<<arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[0]!=1)
		{
			cout<<1;
			return 0;
		}
		else if(i!=0)
		{
			if(arr[i]==arr[i-1] || arr[i]==arr[i-1]+1)
			{
			}
			else
			{//cout<<arr[i]<<" "<<arr[i-1];
				cout<<arr[i-1]+1;
				return 0;
			}
		
		}
	}
	cout<<n+1;
	return 0;
}
