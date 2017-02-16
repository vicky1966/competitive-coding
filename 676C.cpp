#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int a=0,b=0,ai,bi,length=0,a_at_b,b_at_a;
	int start=0,end=0;
	int max=-999;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			a++;			b_at_a=b;

			if(a<b)
			ai=i;
			if(b<a)
			if(a>m )
			{
				length=a+b-1;
				if(max<length)
				 max=length;			
				 b=b-b_at_a;
			}
		}
		if(s[i]=='b')
		{
			b++;
			bi=i;
			a_at_b=a;
			if(b<a)
			if(b>m)
			{
				length=a+b-1;
				if(max<length)
				 max=length;			
				 a=a-a_at_b;
			}
			
		}
		length=a+b;
		if(max<length)
		 max=length;
	
	}
	cout<<max;
}
