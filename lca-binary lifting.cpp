#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
ll par[100009][20]={0};   //log2(100009) = 16
ll lvl[100009];     
vector<ll>v[100009];         
ll dfs(ll node,ll parent)
{
  par[node][0]=parent; 
  lvl[node]=lvl[parent]+1;
  for(int i:v[node])
  dfs(i,node);
}

ll lca(ll u , ll v)
{
  int lg;
  if(lvl[v]>lvl[u])
  swap(u,v);

  for(lg=0;(1<<lg)<=lvl[u];lg++);

  lg--;

  for(int i=lg;i>=0;i--)
  {
    if(lvl[u]-(1<<i) >= lvl[v])
    u=par[u][i];
  }

  if(u==v)
  return u;

  for(int i=lg;i>=0;i--)
  {
    if(par[u][i]!=0 && par[u][i] != par[v][i])
    {
      u=par[u][i];
      v=par[v][i];
    }
  }

  return par[u][0];
  

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,x,y;    
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  lvl[1]=0;
  dfs(1,1);
  for(int i=1;i<=logb(n);i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(par[j][i-1]!=0)
      par[j][i]=par[par[j][i-1]][i-1];
      else 
      break;
    }
  }
  return 0;
} 
