#include<iostream>
using namespace std;

int main()
{
	int y,n,k;
	cin>>y>>n>>k;
	int range = (k-y);
	int i=y/n;
	//cout<<i;
	bool flag=true;
	for(i=i+1;;i++)
	{	
		int p=(i*n)-y;
		if(p>k-y)
			break;
			flag=false;
		cout<<(i*n)-y<<" ";	
	}
	if(flag)
		cout<<"-1";
}

