#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace std;

string lshift(string s)
{
    string a;
	a=s[0];
    
    //cout<<"prev="<<s<<" ";
    s.erase(0,1);
    s.append(a);
   // cout<<s<<endl;
    return s;
}

int rotated_pallindrone(string s)
{
	for(int i=0;i<s.length();i++)
	
	{
		s=lshift(s);
		string ls;
		string rs;
		int half;
		if(s.length()%2!=0)
		{
			half=s.length()/2+1;
			
		}
		else
			half=s.length()/2;
		for(int j=0;j<s.length()/2;j++)
		{
				string temp;
				temp=s[j];
				ls.append(temp);	
		}
		for(int j=s.length()-1;j>=half;j--)
		{
				string temp;
				temp=s[j];
				rs.append(temp);	
		}
		cout<<ls<<" "<<rs<<endl;
		
		if(ls.compare(rs)==0)
			return 1;
		
	}
	return 0;
}

int main()
 {
	int t;	cin>>t;
	while(t--)
	{
		string s;	cin>>s;
	cout<<rotated_pallindrone(s)<<endl;	
	}
	
	getchar();
	return 0;
}
