#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;


string remove_duplicates(string s)
{
	int arr[256]={0};
	string p="";
	for(int i=0;i<s.length();i++)
	{
		if(arr[s[i]]==0)
		{
			p=p+s[i];
			arr[s[i]]=1;
		}
	}
	return p;
}
int main()
 {
 	int t;	cin>>t;
 	while(t--)
 	{
 		string s;
 		cin>>s;
 		cout<<remove_duplicates(s)<<endl;
 	}
	
	return 0;
}
