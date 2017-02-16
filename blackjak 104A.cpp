#include<iostream>
using namespace std;

int main()
{
	int a[15],b[15],c[15],d[15];
	for(int i=1;i<=11;i++)
	{
		a[i]=i;
		b[i]=i;
		c[i]=i;
		d[i]=i;
	}	
	for(int i=12;i<=14;i++)
	{
		a[i]=10;
		b[i]=10;
		c[i]=10;
		d[i]=10;
	}
	d[14]=0;
	
	int n; cin>>n;
	n=n-10;
	if(n==0)
	{
		cout<<"0";
		return 0;
	}
	int ans=0;
	for(int i=1;i<=14;i++)
	{//cout<<"n= "<<n<<" i "<<i<<" "<<a[i]<<endl;
		if(a[i]==n)
			ans++;
		if(b[i]==n)
			ans++;
		if(c[i]==n)
			ans++;
		if(d[i]==n)
			ans++;
	}cout<<ans;
}
