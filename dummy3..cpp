#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
  return (a.first > b.first);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t, n, k, a[100009];
  map<ll, ll> mpp;
  cin >> t;
  vector<pair<ll, ll>> v;
  while (t--)
  {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mpp[a[i]]++;
    }
    ll pos1 = 1;
    ll pos3 = k;
    int flag = 0;
    for (auto itr = mpp.begin(); itr != mpp.end(); itr++)
    {
      v.pb(mp(itr->ss, itr->ff));
    }
    ll cun = 0;
    sort(v.begin(), v.end(), sortinrev);
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i].ff > n / k)
      {
        cun = 0;
        for (int j = pos1; cun < n / k && j <= n; j += (k))
        {
          a[j] = v[i].ss;
          cun++;
        }
        v[i].ff -= n / k;
        mpp[v[i].ss] -= n / k;
        pos1++;
      }
      else if (v[i].ff == n / k)
      {
        cun = 0;
        for (int j = pos1; cun < n / k && j <= n; j += (k))
          a[j] = v[i].ss;
        v[i].ff = 0;
        mpp[v[i].ss] = 0;
        pos1++;
      }
      else
      {
        if (2 * k > n)
        {
          for (; v[i].ff > 0; pos3--)
          {
            a[pos3] = v[i].ss;
            v[i].ff--;
          }
        }
        else
        {
          flag = 1;
          break;
        }
      }
    }
    // for (int i = 1; i <= n; i++)
    //   cout << a[i];
    if (flag != 1)
    {
      for (int i = 1; i <= n % k; i++)
      {
        a[(k * (n / k)) + i] = a[i];
        if (mpp[a[i]] == 0)
        {
          flag = 1;
          break;
        }
        else
          mpp[a[i]]--;
      }
    }
    for (int i = 1; i <= n; i++)
      cout << a[i] << " ";
    for (auto itr = mpp.begin(); itr != mpp.end(); itr++)
      if (itr->ss > 0)
      {
        flag = 1;
        break;
      }

    if (flag == 1)
      cout << "NO";
    else
    {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    }
    cout << endl;
    mpp.clear();
    v.clear();
  }
}