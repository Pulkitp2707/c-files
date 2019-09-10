#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long index = log2(1000000000000000000);
    cout << ((long long)pow(2, index)) % 60;
    return 0;
}