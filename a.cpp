#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;

int string_formation(string s)
{
	for(int i=1;i<s.length()/2;i++)
	{
		string sub;
		sub.append(s,0,i);
		//cout<<sub<<endl;
		int k=1;
		int flag=0;
		for(int j=i;j<s.length();j+=i)
		{
			if(s.compare(j,i,sub)!=0)
				{
					flag=1;
					break;
				}
				
		}
		if(flag==0)
			{
			
				return 1;
			}
			
	}
	return 0;
}
int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
		cout<<string_formation(s)<<endl;
	}
	
	
}
