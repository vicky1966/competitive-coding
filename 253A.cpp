#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int b=0,g=0;
	int arr[2];
	int a;
	int i=0;
	ifstream myfile;
	ofstream out;
	out.open("C:\\Users\\Vicky\\Downloads\\output.txt");
	myfile.open("C:\\Users\\Vicky\\Downloads\\input.txt");
	bool flagg = myfile;
	if(flagg)
	while((a=myfile.get())!=-1)
	{
		if(a!=32)
		{
			arr[i++]=int(a)-48;
			//cout<<a<<" ";
		}
			
		
	}
		
	//myfile>>c;
	cout<<arr[0]<<" "<<" ";
	
	b=arr[0];
	g=arr[1];
	int n=b+g;
	bool flag=true;
	if(b>=g)
	{
		flag=true;
		
		for(int i=1;i<=n;i++)
		{
			if(flag && b>=1)
			{
				out<<"B";
				if(g>=1)	
				flag=false;
				b--;
			}
			
			else if(flag==false && g>=1)
			{
				out<<"G";
				if(b>=1)	
				flag=true;
				g--;
			}
			
		}
	}
	else if(g>b)
	{
		flag=false;
		
		for(int i=1;i<=n+1;i++)
		{
			if(flag==true && b>=1)
			{
				out<<"B";
				if(g>=1)	
				flag=false;
				b=b-1;
			}
			
			else if(flag==false && g>=1)
			{
				out<<"G";
				if(b>=1)	
				flag=true;
				g=g-1;
			}
			
		}
	}
}
