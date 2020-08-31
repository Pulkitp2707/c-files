#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
vector<ll> v;
bool bin_s(ll m, ll n, ll c)
{
  ll flag = 1;
  ll sta = 0;
  for (int i = 1; i < n; i++)
  {
    if (v[i] - v[sta] >= m)
    {
      flag++;
      sta = i;
      if (flag == c)
        return true;
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t, ans = 0, mid, x, end, start, n, c;
  cin >> t;
  while (t--)
  {
    ans = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      v.pb(x);
    }
    sort(v.begin(), v.end());
    start = 0;
    end = abs(v[0] - v[n - 1]);
    while (start != end - 1)
    {
      mid = (start + end) / 2;
      if (bin_s(mid, n, c))
      {
        start = mid;
        ans = max(ans, mid);
      }
      else
        end = mid;
    }
    cout << ans << endl;
    v.clear();
  }
  return 0;
}