#include<bits/stdc++.h>
using namespace std;
int dp[51][1005];
int c[51],q[51];
int n,k;
long long call(int i, int amount)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    long long  r1=0,r2=0;
    for(int p=1;p<=q[i];p++)
    {
         if(amount-(c[i]*p)>=0)
            r1+=call(i+1, amount-(c[i]*p))%100000007;
         else break;
    }
    r2 = call(i+1, amount);
    return dp[i][amount]= (r1+r2)%100000007;

}
int main()
{
//    memset(dp, -1, sizeof(dp));
    int tst;
    cin>>tst;
    int l=0;
    while(tst--)
    {
        memset(dp, -1, sizeof(dp));
         l++;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for (int i=0;i<n;i++)
        {
            cin>>q[i];
        }
        int res = call(0,k);
    printf("Case %d: %d\n",l,res);
    }
//    int res = call(0,k);
//    printf("Case %d: %d",tst,res);
    return 0;
}

