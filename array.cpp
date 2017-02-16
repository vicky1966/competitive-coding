#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m,n;
	
	cin>>m>>n;
	vector<vector<int> > s[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			{
				int x;	cin>>x;
				s[i][j]=x;
			}
}
