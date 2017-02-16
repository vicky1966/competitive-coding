
#include <iostream>
#include <vector >

using namespace std;


int main()
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }
        
        int j;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(M[i][j]!=0 && j!=i && M[j][i]!=0)
                    {
                    M[i][j]--;
                    M[j][i]--;
                    j--;
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(M[i][j]!=0 && i!=j)
                {
	                cout<<"Impossible"<<endl;
	            	flag=true;
					break;
            	}
            }
            if(flag)
            break;
        }
        
        if(flag==false)
        cout<<"Possible"<<endl;
}
return 0;
}

