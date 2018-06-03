#include<bits/stdc++.h>
using namespace std;
int n;
double x[1005],y[1005],dp[1005][1005];

double d(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double func(int i,int j)
{
    int k = max(i,j)+1;

    if(dp[i][j])
    {
        return dp[i][j];
    }

    if(k==n)
    {
        dp[n][n] = d(i,k) + d(j,k);
        return dp[n][n];
    }

    dp[i][j] = min(func(i,k)+d(j,k),func(j,k)+d(i,k));
    return dp[i][j];
}

int main()
{
    while(scanf(" %d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf(" %lf %lf",&x[i],&y[i]);
        }
        if(n==1)
        {
            printf("0.00\n");
            continue;
        }
        memset(dp,1e9,sizeof(dp));

        func(1,1);

        printf("%.2lf\n",dp[1][1]);
    }
    return 0;
}
