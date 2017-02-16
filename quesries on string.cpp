#include<iostream>
#include<string.h>
using namespace std;
static char input_buf[512];
void reverse(string &str, size_t begin, int end) {
	while (begin < end) {
		end--;
		char tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
	}
}

void left_rotate(string &str, int amt) {
	int str_sz = str.length();
	amt %= str_sz;
	reverse(str, 0, amt);
	reverse(str, amt, str_sz);
	reverse(str, 0, str_sz);
}

int main()
{
	string s;	cin>>s;
	int t;	cin>>t;
	while(t--)
	{
	int l,r,k;
	cin>>l>>r>>k;
	string p;
	string q;
	string u;
	if(l>=2)
	p.assign(s,0,l-1);
	else
	p.assign(s,0,0);
	cout<<p<<" ";
	q.assign(s,l-1,r-l-1);
	u.assign(s,r,s.length()-r-1);
	left_rotate(p,k);
	cout<<p<<" "<<q<<" "<<u<<endl;
	string m;
	m.append(p);
	m.append(q);
	m.append(u);
	s=m;
	}
	cout<<s;
}
