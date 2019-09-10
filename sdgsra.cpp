using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define int long long

int PO(int a, int b)
{
    int d = 1;
    for (int i = 0; i < b; i++)
        d *= a;
    return d;
}

signed main()
{
    vector<int> v1, v2, v3;
    cout << "? ";
    int val1, val2;

    int cnt = 0;
    for (int i = 128;; i += 128)
    {
        if (cnt == 100)
            break;
        cout << i << " ";
        cnt++;
    }
    cout << "\n";
    cin >> val1;
    while (val1)
    {
        v1.pb(val1 % 2);
        val1 /= 2;
    }

    for (int i = 0; i < 8; i++)
        v1.pb(0);
    for (int i = 0; i < 7; i++)
        v3.pb(v1[i]);
    /*for (auto x: v3)
		cout<<x<<" ";
	cout<<endl;*/

    cout << "? ";
    for (int i = 1; i <= 100; i++)
        cout << i << " ";
    cout << "\n";
    cin >> val2;
    while (val2)
    {
        v2.pb(val2 % 2);
        val2 /= 2;
    }

    if (v2.size() > 7)
    {
        for (int i = 7; i < v2.size(); i++)
            v3.pb(v2[i]);
    }
    /*for (auto x: v3)
		cout<<x<<" ";
	cout<<endl;*/
    int ans = 0;
    for (int i = 0; i < v3.size(); i++)
        ans += PO(2, i) * v3[i];
    cout << "! " << ans << "\n";
}
