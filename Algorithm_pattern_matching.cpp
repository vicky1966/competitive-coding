#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void search_pattern(string pat,string text)
{
	int m= pat.length();
	int n= text.length();
	int i,j;
	for(i=0;i<=n-m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(pat[j]!=text[i+j])
				break;
		}
		if(j==m)
		{
			cout<<"found\n";
			return;	
		}
	}
	cout<<"not found\n";
	return;
}

void createLSP(int lsp[],int m,string pat)
{
	int length=0;
	int i=0;
	lsp[0]=0;
	i++;
	while(i<m)
	{
		if(pat[i]==pat[length])
		{
			length++;
			lsp[i]=length;
			i++;
		}
		else
		{
			if(length!=0)
			{
				length = lsp[length-1];
			}
			else
			{
				lsp[i]=0;
				i++;
			}
		}
	}
}

void kmpPatternSearch(string text,string pat)
{
	int m=pat.length();
	int n=text.length();
	int lsp[m];
	createLSP(lsp,m,pat);
	
	int i=0,j=0;
	while(i<n)
	{
		if(text[i] == pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"\nPattern found at = "<<i-j;
			j = lsp[j-1];
		}
		else if(i<n && pat[j]!=text[i])
		{
			if(j!=0)
			{
				j = lsp[j-1];
			}
			else
			{
				i=i+1;
			}	
		}
	}
}

int hash(string k,int start,int end)
{
	
}
void rabinKarp(string text,string pat)
{
	int m,n;	n=text.length();	m=pat.length();
	int i=0,j=0;
	long long hashOFPattern=0,hashOFText=0;
	int prime=101;
	for(j=0;j<m;j++)
	{
		hashOFPattern+=(int)pat[j]*pow(prime,j);
		hashOFText+=(int)text[j]*pow(prime,j);
	}
	//cout<<hashOFPattern<<endl;
	//cout<<hashOFText<<endl;
	for(i=1;i<=n-m+1;i++)
	{
		
		if(hashOFText==hashOFPattern)
		{
			for(int p=0;p<m;p++)
			{
				if(pat[p]!=text[i+p-1])
				{
					cout<<"not found"<<endl;
					return;
				}
				if(p==m-1)
				{
					cout<<"found";
					return ;
				}
			}
		}
			hashOFText=hashOFText-(int)text[i-1];
			hashOFText=hashOFText/prime;
			hashOFText+=(int)text[i+m-1]*pow(prime,m-1);
			//sdfcout<<hashOFText<<" ";
	}
}
		
int main()
{
	int n; cin>>n;
	string text,pat;
	while(n--)
	{
		
		cin>>text>>pat;
		rabinKarp(text,pat);
	}
	
}
