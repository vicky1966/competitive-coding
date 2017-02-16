#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char str[105][1005];
int num1[35][35];
int num2[35];
int ch[5];

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
        memset(num1,0,sizeof(num1));
        for(int i = 0; i < n; i++)
		{
            scanf("%s",str[i]);
            int l = strlen(str[i]),sum = 0,flag = 0;
            memset(num2,0,sizeof(num2));
            memset(ch,0,sizeof(ch));
            for(int j = 0; j < l; j++)
			{
                num2[str[i][j]-'a']++;
                sum++;
            }
            int dis = 0;//?????
            for(int j = 0; j < 30; j++)
			{
                if(num2[j])
				{
                    ch[dis++] = j;
                }
                if(dis >= 3)
				{
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;
            if(ch[1] == 0)
			{
                for(int j = 0; j < ch[0]; j++)
                    num1[j][ch[0]] += sum;
                for(int j = ch[0]+1; j < 30; j++)
                    num1[ch[0]][j] += sum;
            }
            else
			{
                if(ch[0] > ch[1])
                    swap(ch[0],ch[1]);
                num1[ch[0]][ch[1]] += sum;
            }
        }
        int ans = 0;
        for(int i = 0; i < 30; i++)
		{
            for(int j = 0; j < 30; j++)
			{
                ans = max(ans,num1[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
