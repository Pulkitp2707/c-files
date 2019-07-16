#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin>>n;
  long double head[n+1],tail[n+1];
  for(int i=1;i<=n;i++)
  {
      cin>>head[i];
      tail[i]=1-head[i];
  }
  long double dp[n+1][n+1];
  for(int i=0;i<=n;i++)
  for(int j=0;j<=n;j++)
  dp[i][j]=0.0;
  dp[0][0]=1.0;  

  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<=i;j++)
      {
          if(i==j)
          dp[i][j]=dp[i-1][j-1]*head[i];
          else
          {
              dp[i][j]=dp[i-1][j]*tail[i];
              if(j-1>=0)
              dp[i][j]+=dp[i-1][j-1]*head[i];
          }
      }
  }
  long double ans=0.0;
  for(int i=n;i>=n/2+1;i--)
  ans+=dp[n][i];
  cout<<setprecision(15)<<ans;

  return 0;
}