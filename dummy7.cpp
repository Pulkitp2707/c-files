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
vector<int>vec[300009];
vector<bool>vis;
vector<int>ans;
void dfs1(int start,int par,int mx,int cur)
{
  
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
  ll n,m;
  cin>>n>>m;
  vector<pii>v[n+1];
  ll dp[n+1];
  rep(i,0,m-1)
  {
    int x,y,z;
    cin>>x>>y>>z;
    v[x].pb(mp(y,z));
    v[y].pb(mp(x,z));
    mpp[mp(x,y)]=i+1;
  }
  priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
  int par[n+1];
  rep(i,1,n)
  {
    par[i]=-1;
    dp[i]=INF;
  }
  par[1]=1;
  dp[1]=0;
  for(auto itr:v[1])
  {
    pq.push(mp(mp(itr.ss,itr.ff),1));
    par[itr.ff]=1;
    dp[itr.ff]=itr.ss+dp[1];
  }
  while(!pq.empty())
  {
    auto tp=pq.top();
    pq.pop();
    for(auto itr:v[tp.ff.ss])
    {
      if(itr.ss+dp[tp.ff.ss]<dp[itr.ff])
      {
        dp[itr.ff]=itr.ss+dp[tp.ff.ss];
        pq.push(mp(mp(itr.ss,itr.ff),tp.ff.ss));
        par[itr.ff]=tp.ff.ss;
      }
    }
  }
}
for(int i=2;i<=n;i++)
{
  vec[par[i]].pb(i);
  vec[i].pb(par[i]);
}
vis.resize(n+1,false);
if(k>n-1)
{
  cout<<n-1<<endl;
  dfs1(1,-1,n-1,0);
}
else
{
  cout<<k<<endl;
  dfs1(1,-1,k,0);
}


//dp-> array storing the shortest distance from 1 to i
//par-> storing the parent of ith node in the shortest path from 1 to i
//ans-> storing the path from 1 to n