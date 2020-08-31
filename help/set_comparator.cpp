#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.ss - a.ff + 1 > b.ss - b.ff + 1)
            return true;
        else if (a.ss - a.ff + 1 == b.ss - b.ff + 1)
        {
            if (a.ff < b.ff)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
int main()
{
    set<pair<int, int>, comp> s;
    s.insert(mp(1, n));
}
