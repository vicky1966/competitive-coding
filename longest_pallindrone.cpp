#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

void print(string s,int start,int end)
{
	for(int i=start;i<=end;i++)
		cout<<s[i];
	cout<<endl;
}


void longest_pallindrone(string s)
{
	int n=s.length();
	bool table[n][n];
	
	for(int i=0;i<n;i++)
		table[i][i]=true;
	
	int start_of_palindrone=0;
	int max_size=1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			table[i][i+1]=true;
			start_of_palindrone=i;
			max_size=2;
		}
	}
	
	for(int size=3;size<=n;size++)
	{
		for(int start=0;start<n-size+1;start++)
		{
			int end=start+size-1;
			if(table[start+1][end-1] && s[start]==s[end])
			{
				table[start][end]=true;
				if(size>max_size)
				{
					max_size=size;
					start_of_palindrone=start;
				}
				
			}
		}
	}
	
	print(s,start_of_palindrone,start_of_palindrone+max_size-1);
	
}

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		longest_pallindrone(s);
	}
	return 0;
}
