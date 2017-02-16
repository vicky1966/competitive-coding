#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	string s;
	cin>>s;
	long long int arr[256];
	for(long long int i=0;i<256;i++)
	{
		arr[i]=-1;
	}
	arr[66]=arr[117]=arr[108]=arr[98]=arr[97]=arr[115]=arr[114]=0;
	for(long long int i=0;i<s.length();i++)
	{
		if(s[i]=='B' || s[i]=='u' || s[i]=='l' || s[i]=='b' || s[i]=='a' || s[i]=='s' ||s[i]=='r')
		{
			arr[s[i]]++;
			//cout<<s[i]<<" "<<arr[s[i]]<<endl;
		}
	}
	int min = 99999;
	arr[97]=arr[97]/2;
	//arr[98]=arr[98]/2;
	arr[117]=arr[117]/2;
	for(int i=0;i<256;i++)
	{
		if(arr[i]>=0)
		{
			
			if(arr[i]<min)
				min=arr[i];
				//cout<<min<<endl;
		}
	}
	if(min<0 || min ==9999)
		min=0;
	cout<<min;
}

