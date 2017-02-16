#include<iostream>
#include<string>
#include<vector>
using namespace std;
class a
{
	public :
	string name,status;
	
};

int main()
{
	int n;	cin>>n;
	a obj[n];
	for(int i=0;i<n;i++)
	{
		string s;	cin>>s;
		obj[i].name=s;
		cin>>s;
		obj[i].status=s;	
	}
	int c=0,r=0,w=0,m=0;
	vector<string> child,captain,rat,woman,man;
	for(int i=0;i<n;i++)
	{
		if(obj[i].status=="captain")
		{
			captain.push_back(obj[i].name);
		}
		if(obj[i].status=="rat")
		{
			rat.push_back(obj[i].name);
		}
		if(obj[i].status=="woman" || obj[i].status=="child")
			woman.push_back(obj[i].name);
		if(obj[i].status=="man")
			man.push_back(obj[i].name);
	}
		for(int i=0;i<rat.size();i++)
			cout<<rat[i]<<endl;
		for(int i=0;i<woman.size();i++)
			cout<<woman[i]<<endl;
		for(int i=0;i<man.size();i++)
			cout<<man[i]<<endl;
			for(int i=0;i<captain.size();i++)
			cout<<captain[i]<<endl;
}

