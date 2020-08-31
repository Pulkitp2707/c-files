#define ll long long
#include <bits/stdc++.h> 
using namespace std; 
ll max_xor(ll arr[], ll n) 
{ 
    ll maxx = 0, mask = 0; 
  
    set<ll> se; 
  
    for (ll i = 30; i >= 0; i--) { 

        mask |= (1 << i); 
  
        for (ll i = 0; i < n; ++i) { 

            se.insert(arr[i] & mask); 
        } 
  
        ll newMaxx = maxx | (1 << i); 
  
        for (ll prefix : se) { 

            if (se.count(newMaxx ^ prefix)) { 
                maxx = newMaxx; 
                break; 
            } 
        } 
  

        se.clear(); 
    } 
  
    return maxx; 
} 
  

int main() 
{ 
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
  
    cout << max_xor(arr, n); 
  
    return 0; 
} 