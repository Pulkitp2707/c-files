#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
// #define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
 
#include <bits/stdc++.h>
using namespace std;
vector<ll>segt[300009];
vector<ll>v;
ll a[100009];
 
ll query(ll start,ll end,ll pos,ll s,ll e,ll m)
{
  if(end<s || start>e)
  return 0;
  if(start>=s && end<=e)
  {
    ll k=lower_bound(segt[pos].begin(),segt[pos].end(),m)-segt[pos].begin();
    return k;
  }
  ll mid=(start+end)/2;
  return query(start,mid,2*pos,s,e,m)+query(mid+1,end,2*pos+1,s,e,m);
}
 
void build(ll start,ll end,ll pos)
{
  ll mid;
  if(start==end)
  {
    segt[pos].pb(a[start]);
    return;
  }
  mid=(start+end)/2;
  build(start,mid,2*pos);
  build(mid+1,end,2*pos+1);
  merge(segt[2*pos].begin(),segt[2*pos].end(),segt[2*pos+1].begin(),segt[2*pos+1].end(),back_inserter(segt[pos]));
}
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m,x,y,z;
  
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    v.pb(a[i]);
  }
  sort(v.begin(),v.end());
  for(int i=1;i<=n;i++)
  a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
  build(1,n,1);
  for(int i=0;i<m;i++)
  {
    cin>>x>>y>>z;
    ll start=1,end=n,mid,ans;
    z--;
    while(start<=end)
    {
      mid=(start+end)/2;
      ll k=query(1,n,1,x,y,mid);
      if(k>z)
        end=mid-1;
      else if(k<=z)
      {
        ans=mid;
        start=mid+1;
      }
    }
    cout<<v[ans-1]<<endl;
  }
  return 0;
} 