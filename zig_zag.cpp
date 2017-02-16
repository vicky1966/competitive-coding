#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int t;	cin>>t;
	
	while(t--)
	{
		string s;	cin>>s;
		int height;	cin>>height;
		int h=height;
		int ans=height-h+1;
		cout<<s[ans-1];
		while(ans<=s.length())
			{
				ans=ans+(h-1)*2;
				if(ans<=s.length())
					cout<<s[ans-1];
			}
		for(h=height-1;h>1;h--)
		{
			ans=height-h+1;
			cout<<s[ans-1];
			while(ans<=s.length())
			{
				ans=ans+(h-1)*2;
				if(ans<=s.length())
					cout<<s[ans-1];
				ans=ans+(height-h)*2;
				if(ans<=s.length())
					cout<<s[ans-1];
				
			}
		}
		
		h=height;
		ans=height;
		cout<<s[ans-1];
		while(ans<=s.length())
		{
			ans=ans+(height-1)*2;
				if(ans<=s.length())
					cout<<s[ans-1];
		}
		
		cout<<endl;
	}
}

