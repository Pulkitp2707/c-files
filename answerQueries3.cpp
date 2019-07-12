#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
ll a[1000009];
struct node{
   ll sum,prefixsum,suffixsum,maxsum;
 };
node segt[1000009];
void build(ll start,ll end,ll pos)
{
  ll mid;
  if(start==end)
  {
    segt[pos].sum=a[start];
    segt[pos].prefixsum=a[start];
    segt[pos].suffixsum=a[start];
    segt[pos].maxsum=a[start];
    return;
  }
  mid=(start+end)/2;
  build(start,mid,2*pos);
  build(mid+1,end,2*pos+1);
  segt[pos].sum=segt[2*pos].sum+segt[2*pos+1].sum;
  segt[pos].prefixsum=max(segt[2*pos].prefixsum,segt[2*pos].sum+segt[2*pos+1].prefixsum);
  segt[pos].suffixsum=max(segt[2*pos+1].suffixsum,segt[2*pos+1].sum+segt[2*pos].suffixsum);
  segt[pos].maxsum=max(segt[pos].suffixsum,max(segt[pos].prefixsum,max(segt[2*pos].maxsum,max(segt[2*pos+1].maxsum,segt[2*pos].suffixsum+segt[2*pos+1].prefixsum))));
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
  nodal.sum = left.sum + right.sum;
  nodal.prefixsum = max(left.prefixsum,left.sum+right.prefixsum);
  nodal.suffixsum = max(right.suffixsum,right.sum+left.suffixsum);
  nodal.maxsum = max(nodal.prefixsum,max(nodal.suffixsum,max(right.maxsum,max(left.maxsum,left.suffixsum+right.prefixsum))));
  return nodal;
 }

 void update(ll start,ll end,ll pos,ll target)
 {
   if(start==end && start==target)
   {
    segt[pos].sum=a[start];
    segt[pos].prefixsum=a[start];
    segt[pos].suffixsum=a[start];
    segt[pos].maxsum=a[start];
    return;
   }
   ll mid=(start+end)/2;
   if(target<=mid)
   update(start,mid,2*pos,target);
   else 
   update(mid+1,end,2*pos+1,target);

  segt[pos].sum=segt[2*pos].sum+segt[2*pos+1].sum;
  segt[pos].prefixsum=max(segt[2*pos].prefixsum,segt[2*pos].sum+segt[2*pos+1].prefixsum);
  segt[pos].suffixsum=max(segt[2*pos+1].suffixsum,segt[2*pos+1].sum+segt[2*pos].suffixsum);
  segt[pos].maxsum=max(segt[pos].suffixsum,max(segt[pos].prefixsum,max(segt[2*pos].maxsum,max(segt[2*pos+1].maxsum,segt[2*pos].suffixsum+segt[2*pos+1].prefixsum))));
 }
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m,x,y,op;
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  build(1,n,1);
  cin>>m;
  for(int i=0;i<m;i++)
  {
    cin>>op>>x>>y;
    if(op==1)
    cout<<query(1,n,1,x,y).maxsum<<endl;
    else 
    {
      a[x]=y;
      update(1,n,1,x);
    }
  }
  return 0;
} 