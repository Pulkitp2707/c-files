#include <bits/stdc++.h>
using namespace std;
int vis[100009];
vector<long long> f[100009];
dfs(int s)
{
	vis[s] = 1;
	for (int i : f[s])
		if (!vis[i])
			dfs(i);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	long long n, e;
	while (t--)
	{
		k = 0;
		vis[100009] = {0};
		cin >> n >> e;
		for (int i = 0; i < e; i++)
		{
			cin >> x >> y;
			f[x].push_back(y);
			f[y].push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			{
				if (!vis[i])
				{
					dfs(i);
					k++;
				}
			}
		}
		cout << k;
		for (int i = 0; i < n; i++)
			f[i].clear();
	}
}