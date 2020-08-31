#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set2d(array, val, m, n) memset(array, val, sizeof(array[0][0]) * m * n);
#include <bits/stdc++.h>
using namespace std;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll po(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base * po(base, powerRaised - 1));
    else
        return 1;
}
ll a[1000009];
ll ans[1000009] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<pair<ll, ll>> s;

        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                s.push(mp(a[i], i));
                ans[i] = 1;
            }
            else
            {
                if (a[i] > s.top().ff)
                {
                    s.push(mp(a[i], i));
                    ans[i] = 1;
                }
                else
                {
                    auto t = s.top();
                    ll cnt = 0;
                    while (!s.empty() && a[i] <= s.top().ff)
                    {
                        t = s.top();
                        s.pop();
                        cnt += ans[t.ss];
                        ans[t.ss] += (i - t.ss) - 1;
                        if (s.empty())
                            break;
                    }
                    ans[i] = cnt + 1;
                    s.push(mp(a[i], i));
                }
            }
        }
        ll ind;
        if (!s.empty())
        {
            ind = s.top().ss;
            s.pop();
        }
        while (!s.empty())
        {
            auto t = s.top();
            s.pop();
            ans[t.ss] += (ind - t.ss);
        }
        ll res = INT_MIN;
        for (int i = 0; i < n; i++)
            res = max(res, a[i] * ans[i]);
        cout << res << endl;
    }
    return 0;
}
