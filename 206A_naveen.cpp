#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007;

int main()
{
	std::ios_base::sync_with_stdio(false);
    int a, b, n;
    cin >>a>>b>>n;
    bool flag = false;
    for (int i = 0; i < 10; ++i)
    {
        if ((a * 10 + i) % b == 0)
        {
            cout << a * 10 + i;
            string s(n - 1, '0');
            cout << s << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
    return 0;	
}
