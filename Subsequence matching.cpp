#include<iostream>
using namespace std;

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
		int count=1;
		int flag=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!='R')
			{
				cout<<"NO"<<endl;
				flag=1;
				break;			
			}
			else
			{
				if(s[i+1]=='R')
				{
					count=1;
				}
				else if(s[i+1]=='Y')
				{
					count++;
					if(s[i+2]=='Y')
					{
						count++;
						i=count-1+1;
						count=1;
					}
					else
					{
						i=i+count-1;
						count=1;
					}
				}
			}		
		}
		if(flag!=1)
			cout<<"YES"<<endl;
	}
}
