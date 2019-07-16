#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
ll segt[1000009]={0},nodes[1000009]={0},lazy_nodes[1000009]={0};

ll build(ll start,ll end,ll pos)
{
  nodes[pos]=0;
  segt[pos]=0;
  lazy_nodes[pos]=0;
  if(start==end)
  {
    nodes[pos]=1;
    return 1;
  }
  ll mid=(start+end)/2;
  nodes[pos]=build(start,mid,2*pos)+build(mid+1,end,2*pos+1);
  return nodes[pos];
}


ll update(ll start, ll end, ll pos, ll s,ll e,ll val)
{
    if(start>=s && end<=e)
    {
        segt[pos]+=(val*nodes[pos]);
        lazy_nodes[2*pos]+=val;
        lazy_nodes[2*pos+1]+=val;
        return val*nodes[pos];
    }
    ll value;
    ll mid=(start+end)/2;
    if(e<=mid)
    value=update(start,mid,2*pos,s,e,val);
    else if(s>mid)
    value=update(mid+1,end,2*pos+1,s,e,val);
    else
    value=(update(start,mid,2*pos,s,e,val)+update(mid+1,end,2*pos+1,s,e,val));
    segt[pos]+=value;
    return value;
}

ll query(ll start,ll end,ll pos,ll s,ll e)
{
    if(lazy_nodes[pos]!=0)
    {
        segt[pos]+=nodes[pos]*lazy_nodes[pos];
        lazy_nodes[2*pos]+=lazy_nodes[pos];
        lazy_nodes[2*pos+1]+=lazy_nodes[pos];
        lazy_nodes[pos]=0;
    }
    if(start>=s && end<=e)
        return segt[pos];
    ll mid=(start+end)/2;
    if(e<=mid)
    return query(start,mid,2*pos,s,e);
    else if(s>mid)
    return query(mid+1,end,2*pos+1,s,e);
    else
    return query(start,mid,2*pos,s,e)+query(mid+1,end,2*pos+1,s,e);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m,t,x,y,z,op;
  cin>>t;
  while(t--)
  {
      cin>>n>>m;
      build(1,n,1);
      for(int i=0;i<m;i++)
      {
          cin>>op;
          if(op==0)
          {
              cin>>x>>y>>z;
              update(1,n,1,x,y,z);
          }
          else if(op==1)
          {
              cin>>x>>y;
              cout<<query(1,n,1,x,y)<<endl;
          }
      }
  }
  return 0;
}