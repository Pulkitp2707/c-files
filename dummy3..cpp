#define ll long long
#define lld long double
#define cn(n)  ll n;cin >> n;
#define tes(t) ll t;cin>>t;while(t--) 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define al(v) v.begin(), v.end()
#define oset(X) tree<X, null_type, less<X>, rb_tree_tag, tree_order_statistics_node_update>
#define roset(X) tree<X, null_type, greater<X>, rb_tree_tag, tree_order_statistics_node_update>
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const ll MOD2 = 998244353;
const long double PI = 3.141592653589793;
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
ll power(ll x, ll y, ll p){ll res = 1;x %= p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
ll po(ll base, ll powerRaised){if (powerRaised != 0)return (base * po(base, powerRaised - 1));else return 1;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif //*
	ll t;
  cin>>t;
  int tp=t;
  while(t--)
  {
    ll n;
    cin>>n;
    vector<ll>v[n+1];
    vector<ll>res;
    rep(i,0,n-1)
    {
      ll x;
      cin>>x;
      v[x].pb(i);
      res.pb(x);
    }
    if(tp-t==64)
    {
      rep(i,0,n-1)
      cout<<res[i]<<" ";
    }
    ll dp[n+1]={0};
    ll ans=0;
    rep(i,1,n)
    {
      int m=v[i].size();
      if(v[i].size()>1)
      {
        rep(j,0,m-2)
        {
          int p1=v[i][j];
          int p2=v[i][j+1];
          rep(k,p1+1,p2-1)
          {
            int num=res[k];
            auto itr=lower_bound(al(v[num]),p2+1);
            int siz=v[num].end()-itr;
            dp[p2]+=(siz*(j+1));
          }
          if(p2-p1==1)
          dp[p2]=dp[p1];

          // dp[p2]+=dp[p1];
          ans+=dp[p2];
        }
      }
      ll prod=(m*(m-1)*(m-2)*(m-3))/24;
      ans+=max(prod,0ll);
    }
    
    cout<<ans<<endl;

  }
	
	
}
	

  
