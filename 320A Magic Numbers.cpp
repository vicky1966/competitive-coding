#include<iostream>
#include<string>
using namespace std;

int main()
{
	long long int n;	cin>>n;
	bool four=false;
	int count=0;
	while(n)
	{
		int x = n%10;
		n=n/10;
		if(x==4)
		{	
			if(count>=2)
			{
				cout<<"NO";
				return 0;
			}
			count++;
			four=true;
		}
		else if(x==1)
		{
			four=false;
			count=0;
		}
		
		else 
		{
			cout<<"NO";
			return 0;
		}
	}
	if(four)
	cout<<"NO";
	else
	cout<<"YES";
	return 0;
}
