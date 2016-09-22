/* 
 * File:   Little Elephant and Subarrays  .cpp
 * Author: Vicky
 *
 * Created on September 21, 2016, 1:57 AM
 */

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * 
 */
int cal(int i,int arr[],int x,int n)
{
    int j=i-1,k=i+1,left=0,right=0,f1=0,f2=0;
    while(j!=0 && k<n)
    {
        if(arr[j]>=arr[i] && f1==0)
        {
            left++;
        }
        else
            f1=1;
        if(arr[k]>=arr[i] && f2==0)
            right++;
        else
            f2=1;
        if(f1==1 && f2==1)
            break;
        j--;k++;
    }
    
    return (left+right+1+(left*right));
}
     
 int findd(int arr[],int n,int x)
     {
         int sum=0;
         for(int i=0;i<n;i++)
         {
             if(arr[i]==x)
             {
                 sum=sum + cal(i,arr,x,n);
             }
         }
         return sum;
     }
     
     
int main(int argc, char** argv) {
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     int k;cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;cin>>x;
        cout<<findd(arr,n,x)<<endl;
    }
    return 0;
}

