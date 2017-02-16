#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int curr=0;
	int ans=0;
	
	for(int i=0;i<s.length();i++)
	{
		int p = abs((s[i]-97)-curr);
		int a = min(p,26-p);
		ans+=a;
		curr=s[i]-97;
		//cout<<p<<" "<<a<<" "<<ans<<endl;;
	}
	cout<<ans;
}
