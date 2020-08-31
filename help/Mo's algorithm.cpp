
// MO's algorithm to solve D-Query(Spoj Question)
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
int block;
bool mycomp(pair<int,int>a,pair<int,int>b)
{
  if(a.ff/block == b.ff/block)
  return a.ss < b.ss; 

  return a.ff/block < b.ff/block;
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
  ll n,q;
  cin>>n>>q;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  vector<pii>v,queries;
  map<pii,int>mpp;
  rep(i,0,q-1)
  {
    int x,y;
    cin>>x>>y;
    x--;y--;
    v.pb(mp(x,y));
    queries.pb(mp(x,y));
    mpp[mp(x,y)]=0;
  }
  block=sqrt(n);
  sort(al(v),mycomp);
  int s,e;
  e=-1;s=0;
  int freq[n+1]={0};
  int cnt=0;
  for(auto itr:v)
  {
    int l=itr.ff;
    int r=itr.ss;
    
    while(e<r)
    {
      e++;
      freq[a[e]]++;
      if(freq[a[e]]==1)
      cnt++;
    }
    while(e>r)
    {
      freq[a[e]]--;
      if(freq[a[e]]==0)
      cnt--;
      e--;
    }
    while(s<l)
    {
      freq[a[s]]--;
      if(freq[a[s]]==0)
      cnt--;
      s++;
    }
    while(s>l)
    {
      s--;
      freq[a[s]]++;
      if(freq[a[s]]==1)
      cnt++;
    }
    mpp[mp(l,r)]=cnt;
  }
  for(auto itr:queries)
  cout<<mpp[mp(itr.ff,itr.ss)]<<endl;
  


	
	
	
}
	

  
