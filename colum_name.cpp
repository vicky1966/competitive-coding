#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;
int main()
 {
	long int t;	cin>>t;
	while(t--)
	{
		long long int k;
		cin>>k;
		vector<int> v;
		while(k>0)
		{
			int ans=k%26;
			k=k/26;
			v.push_back(ans);
		}
		for(int i=v.size()-1;i>=0;i--)
		{
			cout<<char(v[i]+64);
		}
	}
	return 0;
}
