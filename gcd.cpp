#include<iostream>  
#include<algorithm>  
#include<cstdlib>  
#include<cstring>  
#include<climits>  
#include<cstdio>  
#include<cmath>  
#include<queue>  
#include<stack>  
#include<map>  
#include<set>  
#define N 200020  
using namespace std;  
inline int read()  
{  
    int x=0,f=1;char ch='#';  
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
int prime[N],cnt;  
bool is[N];  
int dy[N];  
void init()  
{  
    for(int i=2;i<=100000;i++)  
    {  
        if(!is[i])  
        {  
            prime[++cnt]=i;  
            dy[i]=cnt;  
        }  
        for(int j=1;j<=cnt;j++)  
        {  
            long long tmp=prime[j]*i;  
            if(tmp>100000)break;  
            is[tmp]=1;dy[tmp]=j;  
            if(i%prime[j]==0)break;  
        }  
    }  
}  
int n,a[N];  
set<int>S[N];  
set<int>T[N];  
set<int>:: iterator it;  
void diver(int x,int ps)  
{  
    int t=x;  
    while(x!=1)  
    {  
        T[dy[x]].insert(ps);  
        S[ps].insert(dy[x]);  
        x/=prime[dy[x]];  
    }  
}  
int ans=1;  
int main()  
{  
    init();n=read();  
    for(int i=1;i<=n;i++)a[i]=read();  
    for(int i=1;i<=n;i++)diver(a[i],i);  
    for(int i=1;i<=n;i++)  
        for(it=S[i].begin();it!=S[i].end();it++)  
        {  
            int x=(*it);  
            int num=T[x].size();  
            ans=max(num,ans);  
            T[x].erase(i);  
        }printf("%d\n",ans);  
}  
