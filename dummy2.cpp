#define ll long long
#define ull unsigned long long
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
ull po(ull base, ull powerRaised){if (powerRaised != 0)return (base * po(base, powerRaised - 1));else return 1;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}
unsigned long long int mx=18446744073709551615;
// vector<int>v[100009];
// int vis[100009]={0};
// int cnt=0;
// set<pii>st;
// void dfs(int start,int par)
// {
//   vis[start]=1;
//   for(int i:v[start])
//   {
//     if(!vis[i] && i!=par)
//     dfs(i,start);
//     else if(vis[i] && i!=par)
//     {
//       st.insert(mp(min(i,start),max(i,start)));
//     }
//   }

// }
vector<ll>v;
ll check(ll mid)
{
  int n=v.size();
  ll val=1;
  ll cnt=0;
  rep(i,0,n-1)
  { 
    cnt+=abs(val-v[i]);
    val*=mid;
  }

  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif //*
  // tes(t)
  // {
    ll n;
    cin>>n;
    rep(i,0,n-1)
    {
      ll x;
      cin>>x;
      v.pb(x);
    }
    
    sort(al(v)); 
    ll p=0;
    while(po(p,n)<=mx)
    p*=2;
    ll start=0;
    unsigned ll end=p;
    ll ans=0;
    while(start<=end)
    {
      ll mid=(start+end)/2;
      ll val=check(mid);
      if(val>check(mid+1))
      {
        start=mid+1;
      }
      else if(val<=check(mid+1))
      {
        ans=val;
        end=mid-1;
      }
    }
    cout<<ans;
    
  // }

  
  
	
	
}
	

  
