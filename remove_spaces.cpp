#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std;
int main()
 {
	int t;  
	cin>>t;
	flush(cin);
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	while(t--)
	{
	    string s;   getline(cin,s);
	    string p="";
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]!=' ')
	            p+=s[i];
	    }
	    cout<<p<<endl;
	}
	return 0;
}
