#define ll long long
#define MOD 1000000007
#define MOD2 998244353
#define MAX 200009
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set2d(array, val, m, n) memset(array, val, sizeof(array[0][0]) * m * n);
#define FOR(variable, initial, less_than) for (int variable = initial; variable < less_than; variable++)
#include <bits/stdc++.h>
using namespace std;
ll par[MAX][20];
ll vis[MAX] = {0};
ll height[MAX];
vector<ll> path;
vector<ll> v[MAX];
int flag = 0;
//vertices are numbered from 1
void dfs(ll node, ll parent)
{
    vis[node] = 1;
    height[node] = 1 + height[parent];
    for (ll i : v[node])
    {
        if (!vis[i] && i != parent)
        {
            dfs(i, node);
            par[i][0] = node;
        }
    }
}
void sparseMatrix(ll n)
{
    for (int i = 1; i < 20; i++)
    {
        //i is the height of the tree=log2(n)
        for (int node = 1; node <= n; node++)
        {
            if (height[node] > 1 << i)
                par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }
}
ll lca(ll u, ll v)
{
    if (height[u] > height[v])
        swap(u, v);
    //u is above v
    ll gap = height[v] - height[u];
    ll cnt = 0;
    while (gap)
    {
        if (gap & 1)
            v = par[v][cnt];
        gap /= 2;
        cnt++;
    }
    if (u == v)
        return u;
    for (int i = 18; i >= 0; i--)
    {
        if (par[u][i] != par[v][i] && par[u][i] != -1)
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //*/ll
    ll n;
    cin >> n;
    set2d(par, -1, MAXN, 20);
    FOR(i, 0, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    height[0] = 0;
    dfs(1, 0);
    sparseMatrix(n);
    // cout << lca(4, 17);
}