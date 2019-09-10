#define ll long long
#define MOD 1000000007 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t,n,m,k,a[105];
  cin>>t;
  while(t--)
  {
    m=0;k=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int flag=0;
    ll noob=0;
    for(int i=1;i<=n;i++)
    {
      if(i==n)
      {
        flag=1;
        break;
      }
      else if(abs(a[i]-a[i+1])>k)
      {
        if(a[i]>a[i+1])
        m+=a[i]-a[i+1];
        else if(a[i+1]>a[i])
        {
          noob=(a[i+1]-a[i])-k;
          if(m>=noob)
          m-=noob;
          else 
          break;
        }
      }
      else if(abs(a[i]-a[i+1])<=k && a[i]>a[i+1])
      m+=a[i]-a[i+1]; 
    }
    if(flag==1)
    cout<<"YES";
    else 
    cout<<"NO";
    cout<<endl;
  }
}