#include<iostream>
#include<string>
using namespace std;

int main()
{
	int arr[20];
	arr[0]=2;
	arr[1]=3;
	arr[2]=5;
	arr[3]=7;
	arr[4]=11;
	arr[5]=13;
	arr[6]=17;
	arr[7]=19;
	arr[8]=23;
	arr[9]=29;
	arr[10]=31;
	arr[11]=37;
	arr[12]=41;
	arr[13]=43;
	arr[14]=47;
	arr[15]=4;
	arr[16]=9;
	arr[17]=49;
	arr[18]=;
	arr[19]=73;
	string s;
	int count=0;
	for(int i=0;i<=17;i++)
	{
		cout<<arr[i]<<"\n";
		fflush(stdout);
		cin>>s;
		if(s.compare("yes")==0)
		{count++;
		}
		if(count>=2)
		{
			cout<<"composite";
			fflush(stdout);
			return 0;
		}
	}	
	cout<<"prime";
			fflush(stdout);
			return 0;
}
