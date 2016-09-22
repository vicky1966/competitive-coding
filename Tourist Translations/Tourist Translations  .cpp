/* 
 * File:   Tourist Translations  .cpp
 * Author: Vicky
 *
 * Created on September 19, 2016, 10:08 PM
 */

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


int main(int argc, char** argv) {
    int n;cin>>n;
    string s,t;
    cin>>t;
    /*
 * for(int i=0;i<26;i++)
    {
        s[i]=65+i;
    }
    
    for(int i=26;i<52;i++)
    {
        s[i]=i+71;
    }
   
 */ 
    string p[n];
    
    for(int i=0;i<n;i++)
        cin>>p[i];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p[i].length();j++)
        {
            if(int(p[i][j])>=65 && int(p[i][j])<=90)
            {
                int x=p[i][j]-65;
                char c=toupper(t[x]);
                cout<<c;
            }
            else if(int(p[i][j])>=97 && int(p[i][j])<=122)
            {
                int y=p[i][j]-97;
                cout<<t[y];
                
            }
            else if(int(p[i][j])==95)
            {
                cout<<" ";
            }
            else
            {
             cout<<p[i][j];   
            }
        }
        cout<<endl;
    }
    return 0;
}

