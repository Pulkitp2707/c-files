#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
int a[200009];
int b[200009];
ll lvl[200009]={0};
vector<ll>v[200009];
ll maxx[100009][20]={0};
vector<pair<ll,ll>>v2[200009];
int vis[200009]={0};
ll par[200009][20]; 
struct edge
{
  ll x,y,z;
};


void dfs(ll node,ll parent)
{
  vis[node]=1;
  par[node][0]=parent; 
  lvl[node]=lvl[parent]+1;
  for(auto i:v2[node])
  {
      if(!vis[i.first]){
      maxx[i.first][0]=i.second;
      b[i.first]=i.second;
      dfs(i.first,node);
      }
  }
}

// lca function
int lca(ll u , ll v)
{
  int lg;
  ll my;
  if(lvl[v]>lvl[u])
  swap(u,v);

  for(lg=0;(1<<lg)<=lvl[u];lg++);
  lg--;

  my=b[u];
  for(int i=lg;i>=0;i--)
  {
    if(lvl[u]-(1<<i) >= lvl[v])
    {
        my=max(my,maxx[u][i]);
        u=par[u][i];
    }
  }

   if(u==v)
   return my;


  for(int i=lg;i>=0;i--)
  {
    if(par[u][i]!=0 && par[u][i] != par[v][i])
    {
      my=max(my,maxx[u][i]);
      my=max(my,maxx[v][i]);
      u=par[u][i];
      v=par[v][i];
    }
  }
      my=max(my,maxx[u][0]);
      my=max(my,maxx[v][0]);
  return my;
}

ll find(ll node)
{
  if(a[node]==-1)
  return node;
  else 
  return find(a[node]);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  multimap<long,pair<long,long>>mup;
  unordered_map<ll,ll>mpp;
  ll n,m,x,y,z,sum=0,x1,x2,x3,x4;
  cin>>n>>m;
  struct edge e[m+1];
  for(int i=1;i<=n;i++)
  a[i]=-1;
  for(int i=0;i<200005;i++)
  {
      for(int j=0;j<20;j++)
          par[i][j]=0;
  }
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y>>z;
    mup.insert({z,mp(x,y)});
    e[i].x=x;
    e[i].y=y;
    e[i].z=z;
  }
  for(auto itr=mup.begin();itr!=mup.end();itr++)
  {
    x1=(itr->ss).ff;
    x2=(itr->ss).ss;
    x3=find(x1);
    x4=find(x2);
    if(x3==x1 && x4==x2)
    {
      a[x2]=x1;
      sum+=itr->ff;
      v2[x1].pb(mp(x2,itr->first));
      v2[x2].pb(mp(x1,itr->first));
      mpp[x1]=x2;
      mpp[x2]=x1;
    }
    else if(x3!=x4)
      {
        if(x3==x1)
          a[x1]=x4;
        else if(x4==x2)
          a[x2]=x3;
        else
          a[x3]=x4;
        sum+=itr->ff;
        v2[x1].pb(mp(x2,itr->first));
        v2[x2].pb(mp(x1,itr->first));
        mpp[x1]=x2;
        mpp[x2]=x1;
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
      }
    }
  } 
  ll ans=sum;
  for(int i=1;i<=m;i++)
  {
      ans=sum;
      x=e[i].x;
      y=e[i].y;
      if(mpp[x]!=y)
      {
        ans+=e[i].z;
        ans-=lca(x,y);
      }
      cout<<ans<<endl;
  }

  return 0;
}