#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int> v
#define vl vector<ll> v
#define vii vector<pair<int, int>> v
#define oset(X) tree<X, null_type, less<X>, rb_tree_tag, tree_order_statistics_node_update>
#define roset(X) tree<X, null_type, greater<X>, rb_tree_tag, tree_order_statistics_node_update>
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const ll MOD2 = 998244353;
const long double PI = 3.141592653589793;
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
vector<bool> vis;
vector<int> tin;
vector<int> low;
vector<int> v[10009];
int timer = 0;
int cnt = 0;
set<int> ans; //the set ans has all the articulation points
void dfs(int start, int par, int child)
{
    vis[start] = true;
    tin[start] = low[start] = ++timer;
    for (int i : v[start])
    {
        if (i == par)
            continue;
        else if (vis[i])
            low[start] = min(low[start], tin[i]);
        else
        {
            dfs(i, start, 0);
            low[start] = min(low[start], low[i]);
            if (tin[start] <= low[i] && par != -1)
                ans.insert(start);
            child++;
        }
    }
    if (par == -1 && child > 1)
        ans.insert(start);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //*
    while (1)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            v[i].clear();
        ans.clear();
        cnt = 0;
        timer = 0;
        if (n == 0 && m == 0)
            return 0;
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        vis.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        dfs(0, -1, 0);
        cout << ans.size() << endl;
        //the set ans has all the articulation points
        //the graph is initially connected(if not we need to run dfs for vertices not visited(line 86))
    }
}
