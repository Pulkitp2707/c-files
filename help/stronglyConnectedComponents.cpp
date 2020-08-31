
//Kosaraju's Algorithm

#define ll long long
#define MOD 1000000007
#define MOD2 998244353
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set2d(array, val, m, n) memset(array, val, sizeof(array[0][0]) * m * n);
#include <bits/stdc++.h>
using namespace std;
vector<ll> v[200009];
vector<ll> v_rev[200009];
vector<ll> sccs[200009];
ll vis[200009] = {0};
ll vis_rev[200009] = {0};
stack<ll> s;
ll cnt = 1;
ll n;
void dfs(ll start)
{
    vis[start] = 1;
    for (int i : v[start])
    {
        if (!vis[i])
            dfs(i);
    }
    s.push(start);
}
void reverseGraph()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j : v[i])
            v_rev[j].pb(i);
    }
}
void dfs2(ll start, ll cnt)
{
    vis_rev[start] = 1;
    for (int i : v_rev[start])
    {
        if (!vis_rev[i])
        {
            sccs[cnt].pb(i);
            dfs2(i, cnt);
        }
    }
}
void scc()
{
    while (!s.empty())
    {
        ll tp = s.top();
        s.pop();

        if (!vis_rev[tp])
        {
            sccs[cnt].pb(tp);
            dfs2(tp, cnt);
            cnt++;
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
    ll m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    reverseGraph();
    scc();
    for (int i = 1; i < cnt; i++)
    {
        for (int j : sccs[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
