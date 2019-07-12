#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
int seg_tree(ll segt[] ,int a[], int start , int end, int pos)
{
    int mid;
    if(start == end)
    segt[pos] = a[start];
    else
    {
        mid=(start+end)/2;
        segt[pos] = seg_tree(segt,a,start,mid,2*pos+1)+seg_tree(segt,a,mid+1,end,2*pos+2);
    }
    return segt[pos];
}


int update(ll segt[] , int start, int end, int targ, int pos)
{
    int mid;
    if(start==end && start==targ)
    {
        if(segt[pos]==1)
        segt[pos]=-1;
        else 
        segt[pos]=1;
    }
    else
    {
        mid=(start+end)/2;
        if(targ<=mid)
        segt[pos]= update(segt,start,mid,targ,2*pos+1) + segt[2*pos+2];
        else 
        segt[pos]= update(segt,mid+1,end,targ,2*pos+2) + segt[2*pos+1];
    }
    return segt[pos];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m,x;int a[30009];
  int t=10;
  while(t--)
  {
  cout<<"Test "<<10-t<<":"<<endl;
  cin>>n;
  ll segt[100009];
  for(int i=0;i<=n;i++)
  a[i]=0;
  char ch;
  for(int i=0;i<n;i++)
  {
      cin>>ch;
      if(ch=='(')
      a[i]=1;
      else 
      a[i]=-1;
  }
  seg_tree(segt,a,0,n-1,0);
  cin>>m;
  for(int i=0;i<m;i++)
  {
      cin>>x;
      if(x)
        update(segt,0,n-1,x-1,0);
      else
      {
        if(segt[0]==0)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
      }
  }
  }
  return 0;
}