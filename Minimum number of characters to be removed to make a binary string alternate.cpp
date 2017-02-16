#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
		int count=0;
		string p="";
		p=p+s[0];
		char last=s[0];
		for(int i=1;i<s.length();i++)
		{
			if(last!=s[i])
			{
				p=p+s[i];
				last=s[i];
			}
			else
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}
