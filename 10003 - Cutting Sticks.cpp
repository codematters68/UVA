#include <bits/stdc++.h>
using namespace std;
int n,l,a[55],dp[55][55];

int solve(int i,int j)
{
    if(i+1==j)
    {
        return 0;
    }
    if(dp[i][j])
    {
        return dp[i][j];
    }
    int ret = 100000000;
    for(int k=i+1;k<j;k++)
    {
        ret = min(ret,solve(i,k)+solve(k,j)+(a[j]-a[i]));
    }
    dp[i][j]=ret;
    return ret;
}



int main()
{
    while(1)
    {
        memset(dp,0,sizeof(dp));
        scanf(" %d",&l);
        if(l==0)
        {
            break;
        }
        scanf(" %d",&n);
        a[0] = 0;
        for(int i=1;i<=n;i++)
        {
            scanf(" %d",&a[i]);
        }
        a[n+1] = l;
        int ans;
        ans = solve(0,n+1);
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
