#include<iostream>
using namespace std;
int main()
{
	long long int a,b,n;
	long long int temp;
	cin>>a>>b>>n;
	bool flag;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			temp=a*10 +j;
			if(temp%b==0)
			{
				a=temp;
				flag=true;
				break;
			}
			else
			{
				flag=false;
			}
		}
		cout<<a<<" ";
	}
		if(flag)
	cout<<a;
	else
	cout<<"-1";
}
