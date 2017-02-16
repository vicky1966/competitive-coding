#include<iostream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int t;	cin>>t;
	//std::ostringstream oss;

	while(t--)
	{
		string s;	cin>>s;
		string ans="";
		int count=0;
		ans+=s[0];
		char ss[33];
		for(int i=1;i<s.length();i++)
		{
		    
			if(s[i]==s[i-1])
				count++;
			else
			{
				itoa(count+1,ss,16);
				ans+=ss;
				ans+=s[i];
				count=0;
			}
			
		}
			//	oss<<count;
				//ans+=to_string(count+1);
				itoa(count+1,ss,16);
				ans+=ss;
				for(int j=ans.length()-1;j>=0;j--)
					cout<<ans[j];
				cout<<endl;	
			
	}	
}
