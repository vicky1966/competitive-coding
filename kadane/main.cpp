#include<iostream>
using namespace std;

int kadane(int arr[],int n)
{
    int tillnow=0,finalsum=-9999;
    int maxc=-9999;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxc)
            maxc=arr[i];
            if(arr[i]>=0)
            flag=1;
           // cout<<maxc<<" ";
        tillnow=tillnow+arr[i];
        if(tillnow<0)
            tillnow=0;
        if(tillnow>finalsum)
        {
            finalsum=tillnow;
        }
        //cout<<finalsum<<" ";
    }
    if(flag!=1)
        return maxc;
    else
    return finalsum;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

            //cout<<endl<<endl;
        cout<<kadane(arr,n)<<endl;
    }
    return 0;
}
