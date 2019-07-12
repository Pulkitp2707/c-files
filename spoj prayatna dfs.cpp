#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<pair<ll,ll>>v;
  ll n,l1,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    if(x>=0)
    x=-x-1;
    v.pb(mp(x,i));
  }
  sort(v.begin(),v.end());
  ll i=0;
  if(n%2!=0)
  for(i=0;i<n;i++)
  if(v[i].first!=-1)
  {v[i].first=-1*v[i].first-1;break;}
  if(i==n)
  v[0].first=-v[0].first-1;
  sort(v.begin(),v.end(),sortbysec);
  l1=v.size();
  for(int i=0;i<l1;i++)
  cout<<v[i].first<<" ";

  return 0;
}
