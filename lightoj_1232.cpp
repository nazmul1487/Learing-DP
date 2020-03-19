#include<bits/stdc++.h>
using namespace std;
int dp[101][10001];
int n,make;
int arr[101];

int main()
{
    int t;
    cin>>t;
    int c=1;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin>>n>>make;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        for(int i=1; i<=n; i++)
        {
            dp[i][0]=1;
            for(int j=1; j<=make; j++)
            {
                if(j-arr[i]>=0)
                {
                    dp[i][j]= (dp[i-1][j]+ dp[i][j-arr[i]])%100000007;
                }
                else
                     dp[i][j]=dp[i-1][j]%100000007;
            }
        }
        printf("Case %d: %d\n",c++,dp[n][make]);
    }
    //printf("Case %d: %lld\n",c++,res);
    return 0;
}
