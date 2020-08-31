#define ll long long
#define pb push_back
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repd(i, a, b) for (int i = a; i >= b; i--)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[5009][5009];
vector<int> path(int n, int sum, int start)
{
    vector<int> ans;
    while (sum > 0)
    {
        ans.pb(v[start - 1]);
        sum -= v[start - 1];
        start = dp[start - 1][sum];
    }
    return ans;
}
int main()
{
    ll n, sum;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }

    rep(i, 0, n)
        rep(j, 0, sum)
            dp[i][j] = -1;
    rep(i, 0, n)
        dp[i][0] = 0;
    vector<int> index;
    rep(i, 1, n)
    {
        rep(j, 1, sum)
        {
            if (v[i - 1] <= j)
            {
                if (dp[i - 1][j - v[i - 1]] != -1)
                    dp[i][j] = i;
                else if (dp[i - 1][j] != -1)
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[i][sum] != -1)
        {
            index = path(n, sum, i);
            break;
        }
    }
    for (int i : index)
        cout << i << " "; //prints the numbers
}
