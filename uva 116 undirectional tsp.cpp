#include <bits/stdc++.h>
using namespace std;
int n,m;
int M[11][101],dp[11][101],go[11][101];

int main()
{
    while(scanf(" %d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf(" %d",&M[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            dp[i][m-1] = M[i][m-1];
        }

        for(int j = m-2;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                dp[i][j] = 1000000000;
                go[i][j] = 101;

                for(int k=-1;k<=1;k++)
                {
                    int r = (i+k+n)%n;
                    if(dp[i][j]>dp[r][j+1]+M[i][j])
                    {
                        dp[i][j] = dp[r][j+1]+M[i][j];
                        go[i][j] = r;
                    }
                    else if(dp[i][j]==dp[r][j+1]+M[i][j])
                    {
                        dp[i][j] = dp[r][j+1]+M[i][j];
                        if(go[i][j]>r)
                        {
                            go[i][j] = r;
                        }
                    }
                }
            }
        }

        int ans = 1000000000;
        for(int i =0;i<n;i++ )
        {
            ans = min(ans,dp[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(ans == dp[i][0])
            {
                for(int j = 0;j<m-1;j++)
                {
                    printf("%d ",i+1);
                    i = go[i][j];
                }
                printf("%d",i+1);
                printf("\n%d\n",ans);
                break;
            }
        }
    }



    return 0;
}
