#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
struct node{
    pair<ll,ll>suffix,prefix,maxc;               
};
node segt[1000009];
 
ll a[100009];
void build(ll start,ll end,ll pos)
{
  if(start==end)
  {
    segt[pos].prefix=mp(a[start],1);
    segt[pos].suffix=mp(a[start],1);
    segt[pos].maxc=mp(a[start],1);
    return;
  }
  ll mid;
  mid=(start+end)/2;
  build(start,mid,2*pos);
  build(mid+1,end,2*pos+1);
  if(segt[2*pos].suffix.ff == segt[2*pos+1].prefix.ff)
  {
      ll newc=(segt[2*pos].suffix.ss+segt[2*pos+1].prefix.ss);
      if(newc >= segt[2*pos].maxc.ss && newc >= segt[2*pos+1].maxc.ss)
      {
          segt[pos].maxc=mp(segt[2*pos].suffix.ff,newc);
          if(segt[pos].maxc.ff == segt[2*pos].prefix.ff)
          segt[pos].prefix = mp(segt[2*pos].prefix.ff,newc);
          else 
          segt[pos].prefix = segt[2*pos].prefix; 
          if(segt[pos].maxc.ff == segt[2*pos+1].suffix.ff)
          segt[pos].suffix = mp(segt[2*pos+1].suffix.ff,newc);
          else
          segt[pos].suffix = segt[2*pos+1].suffix; 
          
          return;
      }
      else if(segt[2*pos].maxc.ss >= segt[2*pos+1].maxc.ss)
      segt[pos].maxc = segt[2*pos].maxc ;
      else 
      segt[pos].maxc = segt[2*pos+1].maxc;
 
      segt[pos].prefix = segt[2*pos].prefix;  
      segt[pos].suffix = segt[2*pos+1].suffix;
  }
  else
  {
      if(segt[2*pos].maxc.ss > segt[2*pos+1].maxc.ss)
      segt[pos].maxc = segt[2*pos].maxc ;
      else 
      segt[pos].maxc = segt[2*pos+1].maxc;
 
      segt[pos].prefix = segt[2*pos].prefix;  
      segt[pos].suffix = segt[2*pos+1].suffix;
  }
}
 
 
 
 
 
node query(ll start,ll end,ll pos,ll x,ll y)
 {   
  if(start>=x && end<=y)
    return segt[pos];
  ll mid=(start+end)/2;
  if(y<=mid)
    return query(start,mid,2*pos,x,y);
  if(x>mid)
    return query(mid+1,end,2*pos+1,x,y);
 
  node left = query(start,mid,2*pos,x,y);
  node right = query(mid+1,end,2*pos+1,x,y);
  node nodal;
  if(left.suffix.ff == right.prefix.ff)
  {
      ll newc=(left.suffix.ss+right.prefix.ss);
      if(newc > left.maxc.ss && newc > right.maxcgit add.ss)
      {
          nodal.maxc=mp(left.suffix.ff,newc);
          if(nodal.maxc.ff == left.prefix.ff)
          nodal.prefix=mp(left.prefix.ff,newc);
          else 
          nodal.prefix = left.prefix;
          if(nodal.maxc.ff == right.suffix.ff)
          nodal.suffix = mp(right.suffix.ff,newc);
          else 
          nodal.suffix = right.suffix;
          
          return nodal;
      }
      else if(left.maxc.ss > right.maxc.ss)
      nodal.maxc = left.maxc ;
      else 
      nodal.maxc = right.maxc;
 
      nodal.prefix = left.prefix;  
      nodal.suffix = right.suffix;
  }
  else
  {
      if(left.maxc.ss > right.maxc.ss)
      nodal.maxc = left.maxc ;
      else 
      nodal.maxc = right.maxc;
 
      nodal.prefix = left.prefix;  
      nodal.suffix = right.suffix;
  }
  return nodal;
 }
 
 
 
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,q;
  cin>>n;
  while(n!=0){
  cin>>q;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  build(1,n,1);
  ll x,y;
  for(int i=0;i<q;i++)
  {
      cin>>x>>y;
      cout<<query(1,n,1,x,y).maxc.ss<<endl;
  }
  cin>>n;
  }
  return 0;
}  