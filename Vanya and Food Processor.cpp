#include<iostream>
using namespace std;

int main()
{
	int n;
	long long int h,k;
	cin>>n>>h>>k;
	long long int arr[n];
	long long int count = 0;
	long long int curr=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int  i=1;
	curr=arr[0];
	count=0;
	while(curr>=0 && i<n)
	{
		if((arr[i]+curr) <= h )
		{
			//count++;
			curr+=arr[i];
			if(curr<0)
			curr=0;
			i++;
		}
		else
		{
			
			
			int ans = curr/k;
			if(ans==0 && curr<k)
			{
				curr=curr-k;
				count++;
			}
			else
			{
			
			count+=ans;
			curr=curr-k*ans;
		}
			if(curr<0)
			curr=0;
		}
		//cout<<count<<" "<<curr<<endl;
	}
	while(curr>0)
	{curr=curr-k;
	count++;
	}
	cout<<count;
}
