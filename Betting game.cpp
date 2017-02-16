#include<iostream>
using namespace std;

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		int sum=4;
		int bet=1;
		string s;	cin>>s;
		for(int i=0;i<s.length() && sum>0;i++)
		{
			if(s[i]=='W')
			{
				sum=sum+bet;
				bet=1;
			}
			else if(s[i]=='L')
			{
				sum=sum-bet;
				bet=bet*2;
			}
			cout<<i<<" sum= "<<sum<<" bet="<<bet<<endl;
			 
		}
		if(sum<=0)
			cout<<"-1"<<endl;
		if(sum>0)
			cout<<sum<<endl;
	}
}
