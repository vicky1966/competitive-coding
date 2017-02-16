#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int x=-10000000000;
	long long int y=10000000000;
	for(int i=0;i<n;i++)
	{
		string q,a;
		cin>>q;
		long long int no;
		cin>>no;
		cin>>a;
		if(q.compare(">=")==0)
		{
			if(a.compare("Y")==0)
			{
				if(x<=no)
				x=no;
				//cout<<"i ma in >="<<endl;
			}
			else
			{
				if(y>=no)
				{
					y=no-1;
				}
				
			}
		}
		else if(q.compare(">")==0)
		{
			if(a.compare("Y")==0)
			{
				if(no>=x)
				x=no+1;
			}
			else
			{
				if(no<=y)
				{
					y=no;
				}
			}
		}
		else if(q.compare("<=")==0)
		{
			if(a.compare("Y")==0)
			{
				if(y>no)
				y=no;
			}
			else
			{
				if(x<=no)
				{
					x=no+1;
				}
			}
		}
		else if(q.compare("<")==0)
		{
			if(a.compare("Y")==0)
			{
				if(no<=y)
				y=no-1;
			}
			else
			{
				if(x<=no)
				{
					x=no;
				}
				
			}
		}
		cout<<x<<" "<<y<<endl;
	}
if(x<-1000000000)
x=-2000000000;
if(y>1000000000)
y=2000000000;
		cout<<x<<" "<<y<<endl;
	if(x<=y)
	cout<<(x+y)/2;
	else if(x>y)
	cout<<"Impossible";
	
}
