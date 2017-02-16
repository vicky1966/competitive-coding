#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std;
int main()
 {
	int t;  cin>>t;
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');
	while(t--)
	{
	    string s;
	    getline(cin,s);
	    
	    int arr[256]={0};
	    int count=0;
	    string p="";
	    for(int i=0;i<s.length();i++)
	    {
	        //cout<<arr[s[i]]<<" "<<s[i]<<endl;
	        if(arr[s[i]]==0)
	        {
	            
	            s[count++]=s[i];
	            arr[s[i]]=1;
	        }
	        
	    }
	    s[count]='\0';
	   cout<<s<<endl;
	}
	return 0;
}
