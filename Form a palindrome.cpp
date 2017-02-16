#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;

int pallindrone(string s)
{
	int end=s.length();
	int table[end][end];
	for(int i=0;i<end;i++)
		for(int j=0;j<end;j++)
			table[i][j]=0;
	for(int gap=1;gap<end;++gap)
	{
		for(int i=0,j=gap;j<end;++i,++j)
		{
			table[i][j]=(s[i]==s[j])?(table[i+1][j-1]):(min(table[i][j-1],table[i+1][j])+1);
		}
	}
	
	return table[0][end-1];
}
int main()
 {
	int n;	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int x=pallindrone(s);
		cout<<x<<endl;
	}
	return 0;
}
