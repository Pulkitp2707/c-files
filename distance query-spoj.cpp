#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
ll par[100009][20];   //log2(100009) = 16
ll maxx[100009][20]={0};
ll minn[100009][20];
ll lvl[100009],a[100009];   
int len[100009][1];  
int vis[100009]={0};
vector<pair<ll,ll>>vec[100009];         

//dfs
void dfs(ll node,ll parent)
{
  vis[node]=1;
  par[node][0]=parent; 
  lvl[node]=lvl[parent]+1;
  for(auto i:vec[node])
  {
      if(!vis[i.first]){
      maxx[i.first][0]=i.second;
      minn[i.first][0]=i.second;
      a[i.first]=i.second;
      dfs(i.first,node);
      }
  }
}

// lca function
int lca(ll u , ll v)
{
  int lg;
  ll mx,my;
  if(lvl[v]>lvl[u])
  swap(u,v);

  for(lg=0;(1<<lg)<=lvl[u];lg++);
  lg--;

  mx=a[u];
  my=a[u];
  for(int i=lg;i>=0;i--)
  {
    if(lvl[u]-(1<<i) >= lvl[v])
    {
        mx=min(mx,minn[u][i]);
        my=max(my,maxx[u][i]);
        u=par[u][i];
    }
  }

if(u==v)
{
    cout<<mx<<" "<<my<<endl;
    return 0;
}


  for(int i=lg;i>=0;i--)
  {
    if(par[u][i]!=0 && par[u][i] != par[v][i])
    {
      mx=min(mx,minn[u][i]);
      mx=min(mx,minn[v][i]);
      my=max(my,maxx[u][i]);
      my=max(my,maxx[v][i]);
      u=par[u][i];
      v=par[v][i];
    }
  }
      mx=min(mx,minn[u][0]);
      mx=min(mx,minn[v][0]);
      my=max(my,maxx[u][0]);
      my=max(my,maxx[v][0]);

      cout<<mx<<" "<<my<<endl;
  return 0;
}

//main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,x,y,z,k,ui,vi;   
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    cin>>x>>y>>z;
    vec[x].pb(mp(y,z));
    vec[y].pb(mp(x,z));
  }
  cin>>k;
  for(int i=0;i<100005;i++)
  {
      for(int j=0;j<19;j++)
      {
          minn[i][j]=INT_MAX;
          par[i][j]=0;
      }
  }
  lvl[0]=0;
  dfs(1,0);
  for(int i=1;i<=logb(n);i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(par[j][i-1]!=0)
      {
          par[j][i]=par[par[j][i-1]][i-1];
          maxx[j][i]=max(maxx[j][i-1],maxx[par[j][i-1]][i-1]);
          minn[j][i]=min(minn[j][i-1],minn[par[j][i-1]][i-1]);
      }
    }
  } 
  
  for(int i=0;i<k;i++)
  {
      cin>>ui>>vi;
      lca(ui,vi);
  }
  return 0;
} 
