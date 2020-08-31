#define ll long long
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        stack<ll> s;
        vector<ll> ans(n + 1);
        vector<ll> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &v[i]);
            ans[i] = -1;
        }
        for (ll i = 0; i < n; i++)
        {
            if (s.empty())
                s.push(i);
            else
            {
                if (v[i] <= v[s.top()])
                    s.push(i);
                else
                {
                    while (v[s.top()] < v[i])
                    {
                        ans[s.top()] = v[i];
                        s.pop();
                        if (s.empty())
                            break;
                    }
                    s.push(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
            printf("%lld ", ans[i]);
        printf("\n");
    }
    return 0;
}