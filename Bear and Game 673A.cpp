#include<iostream>
using namespace std;

int main()
{
	int n;cin>>n;
	int ans=90;
	int x=0,y;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		cin>>y;
		 if(n==1)
		 {
		 	if(y>15)
		 	{
		 		ans=15;
		 	}
		 	else
		 	{
		 		ans=y+15;
		 	}
		 }
		 else
		 {
		 	if((y-x)>15)
		 	{
		 		ans=x+15;
		 		flag=true;
		 		break;
		 	}
		 	else
		 	{
		 		ans=y+15;
		 	}
		 }
		 x=y;
	}
	if(ans>90)
		ans=90;
	cout<<ans;
}
