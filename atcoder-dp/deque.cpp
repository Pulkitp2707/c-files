#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
ll dp[3005][3005]={0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  ll a[3005];
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  for(int i=n;i>=1;i--)
  {
    for(int j=i;j<=n;j++)
    {
      if((j-i+1)%2!=n%2)
      dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
      else 
      dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
    }
  }
  cout<<dp[1][n];
  return 0;
}