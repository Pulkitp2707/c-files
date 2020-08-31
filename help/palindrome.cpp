//Z-algorithm to find longest prefix palindrome

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
ll z[1000] = {0};
ll find(string s)
{
    ll n = s.length();
    z[0] = 0;
    ll l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (s[r] == s[r - l] && r < n)
                r++;
            z[i] = r - l;
            r--;
        }
        else if (i <= r)
        {
            ll k = i - l;
            if (i + z[k] - 1 < r)
                z[i] = z[k];
            else
            {
                l = i;
                while (s[r] == s[r - l] && r < n)
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    ll mx = -1;
    ll pos;
    ll np = (n - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        if (n - i == z[i] && z[i] > mx)
        {
            mx = z[i];
            pos = i;
        }
    }
    return pos;
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
    string s;
    cin >> s;
    string p = s;
    reverse(s.begin(), s.end());
    string t = s + "#" + p;
    for (int i = 0; i < z[find(t)]; i++) //find(t) returns the position(pos) of the character where the paalindrome starts from
        cout << p[i];                    //and z[pos] contains the length of palindrome
    return 0;
}