#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int n;	cin>>n;
	string s,ans;	cin>>s;
	int j;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o' && s[i+1]=='g' && s[i+2]=='o')
		{
			ans=ans+"***";
			for( j=i+3;j<n;j+=2)
			{
				if(s[j]!='g' || s[j+1]!='o')
				{
					break;
				}
			}
			i=j-1;
			//cout<<i<<" ";
		}
		else
		{
			ans=ans+s[i];
		}
		
	}
	cout<<ans;
	return 0;
}
