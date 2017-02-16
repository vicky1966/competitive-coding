

#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<int> Maximum_Occuring(string s)
{
    int arr[27]={0};
    for(int i=0;i<s.length();i++)
    {
        int index;
        if(int(s[i]>=65 && s[i]<=90))
            index=int(s[i])-65;
        else if(int(s[i]>=97 && int(s[i]<=122)))
            index=int(s[i])-97;
        arr[index]++;
    }
    vector<int> v;
    int max=-10;
    int ans;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>max)
        {
            ans=i;
            max=arr[i];
            v.clear();
            v.push_back(i);
        }
        	
    }
    return v;
    
}

//--------------------Anagram--------------------------------------------------

bool anagram(string ss,string pp)
{
	
	int s[26]={0};
	int p[26]={0};
	
	for(int i=0;i<ss.length() || i<pp.length();i++)
	{
		s[int(ss[i])-97]++;
		p[pp[i]-97]++;
		//cout<<"s[i]="<<s[i]<<" p[i]="<<p[i]<<endl;
	}
	
	for(int i=0;i<26;i++)
	{
		
		if(s[i]!=p[i])
			return false;
	}
	return true;
}
//---------------------------Binary String-----------------------------------------

int Binary_string(string s,int n)
{
	int one=0,result=0;
	//cout<<s.length()<<" wd"<<endl;
	for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			one++;
	//		cout<<one<<endl;
		}
//	cout<<"one="<<one<<endl;
	for(int i=one-1;i>0;i--)
	{
		result=result+i;
	}
	return result;
}

//--------------------------Pattern Searching string-----------------------------------

bool Pattern_Searching_string(string s,string p)
{
	int x=s.find(p);
	if(x>=0 && x<=s.length())
		return true;
	return false;
}

//---------------------------Non Repeating Character string------------------------------

char Non_Repeating_Character_string(string s)
{
	int arr[26]={0};
	string p="-1";
	for(int i=0;i<s.length();i++)
	{
		if(arr[int(s[i])-97]==0)
		{
			int x=s.find(s[i],i+1);
			//cout<<"x="<<x<<" ";
			if(x==-1)
				return s[i];
			else
				arr[int(s[i])-97]=1;
		}
	}
	return '=';
}


//-----------------------------Longest Even Length Substring such that Sum of First and Second Half is same-------------------------

int maximumsum(string s)
{
	int n=s.length();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int l=i;
		int r=i+1;
		int lsum=0;
		int rsum=0;
		while(l>=0 && r<n)
		{
			lsum+=s[l]-'0';
			rsum+=s[r]-'0';
			if(lsum==rsum)
				ans=max(ans,r-l+1);
			l--;
			r++;
		}
	}
	return ans;
}

int main() 
{
    int x=0;
    while(true)
    {
        cout<<"---------------Menu-----------------"<<endl;
        cout<<"1. Maximum Occuring Character string \n2. Anagram\n3. Binary String \n4. Pattern Searching string \n5. Non Repeating Character string \n6. Longest Even Length Substring"<<endl<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            {
                int t;
                cin>>t;
                while(t--)
                {
                    string s;
                    cin>>s;
                    vector<int> v=Maximum_Occuring(s);
                    for(int i=0;i<v.size();i++)
                    	cout<<char(v[i]+97)<<endl;
                    	
                }
                break;
            }
            
            case 2:
            {
            	int t;
            	cin>>t;
            	while(t--)
            	{
            		string p;
            		string q;
            		cin>>p>>q;
            		cout<<anagram(p,q);
            	}
            	break;
            }
            
            case 3:
            {
            	int t;
            	cin>>t;
            	
            	while(t--)
            	{
					int n; 		cin>>n;
            		string s; 	cin>>s;
            		
					cout<<Binary_string(s,n)<<endl;
            	}
            	break;
            }
            
            case 4:
            {
            	int t;	cin>>t;
            	while(t--)
            	{
            		string p,q;
            		cin>>p>>q;
            		if(Pattern_Searching_string(p,q)==true)
            			cout<<"found"<<endl;
            		else
            			cout<<"not found"<<endl;
            	}
            	break;
            }
            
            case 5:
            {
            	int t;	cin>>t;
            	while(t--)
            	{
            		int n;	cin>>n;
            		string s;	cin>>s;
            		char x=Non_Repeating_Character_string(s);
            		if(x=='=')
            			cout<<"-1"<<endl;
            		else
            			cout<<x<<endl;
            	}
            	break;
            }
            
            case 6:
            {
            	int t;	cin>>t;
            	while(t--)
            	{
            		string s;
            		cin>>s;
            		cout<<maximumsum(s)<<endl;
            	}
            	break;
            }
            
        }
    }
}
