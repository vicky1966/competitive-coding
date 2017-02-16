#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;


int main()
{
	string s="abcabcabc";
	for(int i=1;i<s.length()/2;i++)
	{
		string sub;
		sub.append(s,i-1,i);
		cout<<sub<<endl;
		for(int j=i+1;j<s.length();j+=i+1)
		{
			
		}
	}
}
