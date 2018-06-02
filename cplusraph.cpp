#include<bits/stdc++.h>
using namespace std;
struct block
{
    int x,y,z;
    block(int l,int w,int h)
    {
        x = l;
        y = w;
        z = h;
    }
};

vector <block> v;
int n,l,w,h,res=0,dp[500];

int func(int k)
{
   // cout << k <<endl;
    if(dp[k] != -1){
  //      cout << "first "<< dp[k] << endl;
        return dp[k];
    }
    int e=0,ans = 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[k].x > v[i].x && v[k].y>v[i].y)
        {
            e=1;
            ans = func(i) + v[i].z;
            dp[k] = max(ans,dp[k]);
        }
    }
    if(!e)
    {
  //      cout << "second" << endl;
        dp[k] = 0;
        return dp[k];
    }
    else
    {
    //    cout << "third "<< dp[k] <<endl;
        return dp[k];
    }
}

int main()
{
    int kase = 0;
    while(1)
    {
        kase++;
        scanf(" %d",&n);
        if(n==0) break;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf(" %d %d %d",&l,&w,&h);
            v.push_back(block(l,w,h));
            v.push_back(block(w,l,h));
            v.push_back(block(l,h,w));
            v.push_back(block(h,l,w));
            v.push_back(block(w,h,l));
            v.push_back(block(h,w,l));
        }
        v.push_back(block(1000000000,1000000000,0));
        res = func(v.size()-1);

        printf("Case %d: maximum height = %d\n",kase,res);

        v.clear();
    }
    return 0;
}
