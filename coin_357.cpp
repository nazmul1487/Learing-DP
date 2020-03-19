#include<bits/stdc++.h>
using namespace std;
int coin[]= {1,5,10,25,50};
long long  dp[6][30003];

long long call(int i, int amount)
{
    if(i>=5)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    long long r1=0,r2=0;
    if(amount-coin[i]>=0)
    {
        r1 = call(i, amount-coin[i]);
    }
    r2 = call(i+1,amount);
    //cout<<r1<<r2<<endl;
    return dp[i][amount]=r1+r2;

}
int main()
{
    memset(dp, -1, sizeof(dp));
    int  make;
    while(scanf("%d",&make)==1)
    {
        long long  res = call(0,make);
       // cout<<call<<endl;
//        if(res) cout<<"yes"<<endl;
//        else cout<<"No"<<endl;
        //cout<<res<<endl;
        if(res==1LL)
            printf("There is only %lld way to produce %d cents change.\n",res,make);
        else
            printf("There are %lld ways to produce %d cents change.\n",res,make);

    }

    return 0;
}
