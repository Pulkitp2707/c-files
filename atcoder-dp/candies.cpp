#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
ll dp[105][100009]={0},sum[105][100009]={0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,a[105];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            dp[i][j]=1;
            else if(j<=a[i])
            {
                dp[i][j]=(1+(sum[i-1][j]-sum[i-1][0]+MOD)%MOD)%MOD;
                sum[i][j]=(dp[i][j]+sum[i][j-1])%MOD;
            }
            else 
            {
                dp[i][j]=(sum[i-1][j]-sum[i-1][j-a[i]-1]+MOD)%MOD;
                sum[i][j]=(dp[i][j]+sum[i][j-1])%MOD;
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][k];
return 0;
} 