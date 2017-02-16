#include<string>
#include<iostream>
using namespace std;

int longest_substring(string s)
{
	int max_length=1;
	int cur_length=1;
	int arr[256];
	for(int i=0;i<256;i++)
	{
		arr[i]=-1;
	}
	arr[s[0]]=0;
	for(int i=1;i<s.length();i++)
	{
		int lasvisit=arr[s[i]];
		if(arr[s[i]]==-1 || i-cur_length>arr[s[i]])
		{
			arr[s[i]]=i;
			cur_length++;
		}
		else
		{
			if(max_length<cur_length)
			{
				max_length=cur_length;
				
			}	cur_length=i-arr[s[i]];
				arr[s[i]]=i;
		}
		//cout<<i<<" current length="<<cur_length<<" "<<s[i]<<" lastvited"<<lasvisit<<endl;
	}
	if(cur_length>max_length)
		max_length=cur_length;
	return max_length;
}


int main()
{
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
		cout<<longest_substring(s)<<endl;
		
	}
}
