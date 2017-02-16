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
	    string s,pattern,p="";
	    cin>>s>>pattern;
	    int l=pattern.length();
	    int k=0;
	    for(int i=0;i<s.length();i++)
	    {
	        int index=s.find(pattern,i);
	        //cout<<index<<endl;
	        if(index==-1 || index!=i)
	        {
	            p=p+s[i];
	            
	        }
	        else if(p[p.length()-1]!='X')
	        {
	            p=p+'X';
	            i+=l-1;
	        }
	        else
	        {
	        	i+=l-1;
	        }
	      	//cout<<p<<" "<<index<<" i="<<i<<endl;

	    }
	    cout<<p<<endl;
	}
	return 0;
}
