#include <bits/stdc++.h>
using namespace std;
int dp1[1001][1001];
int dp2[1005];
int l;
char str[1005];

int pal(int i,int j)
{
    if(i>=j) return 1;
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }
    int ret=0;
    if(str[i] == str[j])
    {
        ret = pal(i+1,j-1);
    }
    dp1[i][j] = ret;
    return dp1[i][j];
}



int solve(int i)
{
    if(i>=l) return 0;
    if(dp2[i])
    {
        return dp2[i];
    }
    int ret = 1e9;
    for(int j=i;j<l;j++)
    {
        if(pal(i,j))
        {
             ret = min(ret,solve(j+1)+1);
        }
    }
    dp2[i] = ret;
    return dp2[i];
}


int main()
{
    int n;
    scanf(" %d",&n);

    while(n--)
    {
        scanf(" %s",str);
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        l = strlen(str);
        printf("%d\n",solve(0));
    }
    return 0;
}
