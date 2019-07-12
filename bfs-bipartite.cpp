#define ll long long
#define MOD 1000000007 
#define pb push_back
#define mp make_pair
#include <bits/stdc++.h>
using namespace std;
vector<ll>v[200009];
int vis[200009]={0};
int a[2]={0};
vector<ll>num[2];
ll bfs(ll start)
{
  pair<ll, int> pos;
  queue<pair<ll,int>>q;
  vis[start]=1;
  q.push(mp(start,0));
  a[0]++;
  num[0].pb(1);
  while(!q.empty())
  {
    pos=q.front();
    q.pop();
    for(ll j:v[pos.first])
    {
      if(!vis[j])
      {
        vis[j]=1;
        a[1-pos.second]++;
        q.push(mp(j,1-pos.second));
        num[1-pos.second].pb(j);
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m,t,x,y;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      vis[i]=0;
    for(int i=1;i<=m;i++)
    {
      cin>>x>>y;
      v[x].pb(y);
      v[y].pb(x);
    }
    a[0]=0;a[1]=0;
    bfs(1);
    cout<<min(a[0],a[1])<<endl;
    if(a[0]==min(a[0],a[1]))
    x=0;
    else x=1;
    for(ll i: num[x])
    cout<<i<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++)
    v[i].clear();
    num[0].clear();
    num[1].clear();
  }
  
  return 0;
}