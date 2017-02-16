#include<iostream>
#include<string>
using namespace std; 
int main() 
{ int i=-1,B=0,u=0,l=0,b=0,a=0,s=0,r=0; 
string input; 
cin>>input; 
int j=input.size(); 
while(i<=j) 
{ i++; 
	if(input[i]=='B') 
	B++; 
	else if(input[i]=='u') 
	u++; 
	else if(input[i]=='l') l++; 
	else if(input[i]=='b') b++; 
	else if(input[i]=='a') a++; 
	else if(input[i]=='s') s++; 
	else if(input[i]=='r') r++; 
} 
i=0; 
while(B>0) 
{ 
if(u>=(2*B) && l>=B && b>=(B) && a>=(2*B) && s>=B && r>=B) 
{ cout<<B<<endl; 
break; 
} 
else B--; 
} 
if(B==0) 
	cout<<B; 
	return 0; 
}
