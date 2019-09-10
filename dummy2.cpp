#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define null 0ll
#include <bits/stdc++.h>
using namespace std;
ll Log2n(ll n)
{
  return (n > 1) ? 1 + Log2n(n / 2) : 0;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t, n, a[65];
  a[1] = 0;
  a[2] = 1;
  for (int i = 3; i <= 60; i++)
  {
    a[i] = (a[i - 1] + a[i - 2]) % 10;
  }
  ll index, exponent, base, result;
  cin >> t;
  while (t--)
  {
    cin >> n;
    index = Log2n(n);
    base = 2;
    exponent = index;
    result = 1;
    while (exponent != 0)
    {
      result *= base;
      --exponent;
    }
    index = (result % 60);
    if (index <= 60)
      cout << a[index];
    else
      cout << a[index + 1];

    cout << endl;
  }
}
