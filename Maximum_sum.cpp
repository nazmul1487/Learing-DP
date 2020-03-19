#include<bits/stdc++.h>
using namespace std;
int ara1[1003], left_sum[1003], right_sum[1003];
int n,k,ans;
int dp[1003][1003];

int DP(int s, int e)
{
    if(s + (n-1-e)==k-1)
    {
        return 0;

    }
    if(dp[s][e]!=-1)
        return dp[s][e];
    return dp[s][e]= max(ara1[s]+DP(s+1,e), ara1[e]+DP(s,e-1));

}

int main()
{
    memset(dp, -1, sizeof dp);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ara1[i];
    }
    int s=0,e=n-1;
    ans = DP(s,e);
    cout<<ans<<endl;
    return 0;
}
