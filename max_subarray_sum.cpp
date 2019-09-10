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
ll t,n;
cin>>t;
ll a[100009],b[100009]={0},c[100009];
while(t--)
{
    for(int i=0;i<=n;i++)
    {
        b[i]=0;
        c[i]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=max(a[i]+b[i-1],a[i]);   //b[i] - maximum subarray sum
        if(i==1)
        c[i]=a[i];
        else
        c[i]=max(a[i]+c[i-1],max(c[i-1],a[i]));   //c[i] - maximum subsequence sum
    }
    cout<<*max_element(b+1,b+n+1)<<" "<<c[n]<<endl;
}

return 0;
} 