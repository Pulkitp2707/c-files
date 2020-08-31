//works on a tree
//returns the minimum weight of the edge between a and b
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
pair<ll, ll> par[MAX][20];
ll vis[MAX] = {0};
ll height[MAX];
vector<ll> path;
vector<pair<ll, ll>> v[MAX];
int flag = 0;
ll res = INT_MIN;
map<pair<ll, ll>, ll> mpp;
void dfs(ll node, ll parent)
{
    vis[node] = 1;
    height[node] = 1 + height[parent];
    for (auto itr : v[node])
    {
        if (!vis[itr.ff] && itr.ff != parent)
        {
            dfs(itr.ff, node);
            par[itr.ff][0] = mp(node, itr.ss);
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
                par[node][i] = mp(par[par[node][i - 1].ff][i - 1].ff, max(par[node][i - 1].ss, par[par[node][i - 1].ff][i - 1].ss));
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
        {
            res = max(res, par[v][cnt].ss);
            v = par[v][cnt].ff;
        }
        gap /= 2;
        cnt++;
    }
    if (u == v)
    {
        return res;
    }
    for (int i = 18; i >= 0; i--)
    {
        if (par[u][i].ff != par[v][i].ff && par[u][i].ff != -1)
        {
            ll x1 = max(par[u][i - 1].ss, par[u][i].ss);
            ll x2 = max(par[v][i - 1].ss, par[v][i].ss);
            u = par[u][i].ff;
            v = par[v][i].ff;
            res = max({res, x1, x2});
        }
    }
    return max({res, mpp[mp(u, par[u][0].ff)], mpp[mp(v, par[v][0].ff)]});
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
    set2d(par, -1, MAX, 20);
    FOR(i, 0, n - 1)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        v[x].pb(mp(y, z));
        v[y].pb(mp(x, z));
        mpp[mp(x, y)] = z;
        mpp[mp(y, x)] = z;
    }
    height[0] = 0;
    dfs(1, 0);
    sparseMatrix(n);
    // cout << lca(4, 17);->returns the minimum weight of the edge from 4 to 17
}