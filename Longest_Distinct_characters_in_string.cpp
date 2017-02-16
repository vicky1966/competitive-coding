#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;

void longest(string s)
{
    int arr[256]={0};
    int size=0;
    int max_size=0;
    for(int i=0;i<s.length();i++)
    {
        if(arr[s[i]]==0)
        {
            arr[s[i]]=1;
            size++;
            if(size>max_size)
            	max_size=size;
        }
        else
        {
            for(int j=0;j<256;j++)
            	arr[j]=0;
            size=0;
        }
    }
    cout<<max_size<<endl;
    
}

int main()
 {
	int t;  cin>>t;
	while(t--)
	{
	    string s;   cin>>s;
	    longest(s);
	}
	return 0;
}
