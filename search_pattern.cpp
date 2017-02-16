#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;
int main()
 {
	int t;  cin>>t;
	while(t--)
	{
	    string str,pat; cin>>str>>pat;
	    int m=pat.length();
	    bool flag=false;
	    int pos=0;
	    while(pos<=(str.length()-m))
	    {
	        pos=str.find(pat,pos);
	        if(pos>=0)
	        {
	            cout<<pos+1<<" ";
	            pos=pos+1;
	            flag=true;
	        }
	        else
	        {
	            if(flag==false)
	            {
	            cout<<"-1";
	            break;
	            }
	        }
	        
	    }
	    cout<<endl;
	}
	return 0;
}
