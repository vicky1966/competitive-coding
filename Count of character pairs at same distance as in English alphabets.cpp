#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
		int count=0;
		for(int i=0;i<s.length();i++)
		{
			for(int j=1;(i+j)<s.length();j++)
			{
				if(abs(s[i+j]-s[i])==j)
					count++;
			}
		}
		cout<<count<<endl;
	}
}
