#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define al(v) v.begin(), v.end()
#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        int a[n+1];
        rep(i,0,n-1)
        {
            cin>>a[i+1];
            sum+=a[i+1];
        }
        int dp[sum+1][n+1];
        int ans[sum+1]={0};
        for(int i=1;i<=sum;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        
        for(int i=0;i<=sum;i++)
                ans[i]=-1;
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
              if(dp[i-a[j]][j-1]!=-1)
              {
                  dp[i][j]=1+dp[i-a[j]][j-1];
                  ans[i]=max(ans[i],dp[i][j]);
              }
            }  
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        int mn=sum;
        int res=n;
        for(int i=1;i<=sum;i++)
        {
           if(ans[i]!=-1)
           {
               int diff=2*i-sum;
               if(diff<0)
                   continue;
               else 
               {
                   if(diff<=mn)
                   {
                       mn=min(mn,diff);
                       res=n-ans[i];
                   }
               }
           }
        }
        cout<<res<<endl;
        
    }
    return 0;
}
