#include<iostream>
#include<string>
//#include<math.h>
#include <algorithm>
using namespace std;

int findmax(int arr[],int start,int end)
{
	int index;
	int max=-9999;
	for(int i=start;i<=end;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			index=i;
		}
	}
	return index;
}

int main()
{
	long long int n,a,b,c;
	cin>>n>>a>>b>>c;
	int books;
	if(n>=4)
	 books = n%4;
	 else
	 books = 4-n;
	 cout<<books<<" ";
	if(books == 0)
	{
		cout<<"0";
		return 0;
	}
	long long int p,q,r,ans=0;
	if(books == 1)
		ans = a;
	else if(books == 2)
		ans =b;
	else if(books ==3)
		ans =c;
	if(a==1)
	{
		p=(books/a)*1;
		ans = min(ans,p);
	}
	
	else if(b==1)
	{
		q=(books/b)*2;
	}
	
	else if(c==1)
	{
		r=(books/c)*3;
	}
	
	//cout<<p<<q<<r<<endl;
	
	cout<<ans;
}
