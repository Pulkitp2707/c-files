//CONSTRUCT ARRAY- MATRIX MULTIPLICATION
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set2d(array, val, m, n) memset(array, val, sizeof(array[0][0]) * m * n);
#include <bits/stdc++.h>
using namespace std;
ll ans[2][2];
ll matrixPower(ll f[2][2], ll ind)
{
    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;
    
    while (ind > 0)
    {
        if (ind & 1)
        {
            ll res[2][2];
            res[0][0] = ((ans[0][0] * f[0][0]) % MOD + (ans[0][1] * f[1][0]) % MOD) % MOD;
            res[0][1] = ((ans[0][0] * f[0][1]) % MOD + (ans[0][1] * f[1][1]) % MOD) % MOD;
            res[1][0] = ((ans[1][0] * f[0][0]) % MOD + (ans[1][1] * f[1][0]) % MOD) % MOD;
            res[1][1] = ((ans[1][0] * f[0][1]) % MOD + (ans[1][1] * f[1][1]) % MOD) % MOD;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                    ans[i][j] = res[i][j];
            }
        }
        ind /= 2;
        ll res[2][2];
        res[0][0] = ((f[0][0] * f[0][0]) % MOD + (f[0][1] * f[1][0]) % MOD) % MOD;
        res[0][1] = ((f[0][0] * f[0][1]) % MOD + (f[0][1] * f[1][1]) % MOD) % MOD;
        res[1][0] = ((f[1][0] * f[0][0]) % MOD + (f[1][1] * f[1][0]) % MOD) % MOD;
        res[1][1] = ((f[1][0] * f[0][1]) % MOD + (f[1][1] * f[1][1]) % MOD) % MOD;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                f[i][j] = res[i][j];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //*/
    ll t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n == 1)
        {
            cout << m % MOD << endl;
            continue;
        }
        ll dp[2][2];
        dp[0][0] = 2;
        dp[0][1] = 2;
        dp[1][0] = 1;
        dp[1][1] = 0;
        matrixPower(dp, 1);
        ll x = (((ans[0][0] % MOD + ans[1][0] % MOD) % MOD) * (m % MOD)) % MOD;
        cout << x << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}