bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    if (abs(a.ff) + abs(a.ss) < abs(b.ff) + abs(b.ss)) //Manhattan distance
        return true;
    else if (abs(a.ff) + abs(a.ss) > abs(b.ff) + abs(b.ss))
        return false;
    else
    {
        if (abs(a.ff) < abs(b.ff))
            return true;
        else
            return false;
    }
}
//if result is true it keeps the pair above

bool meracompare(pair<ll, ll> a, pair<ll, ll> b)
{
    if (b.ff <= a.ff && b.ss < a.ss)
        return false;
    else if (b.ff > a.ff && b.ss < a.ss)
        return false;
    else
        return true;
}
//this comparator sorts the pairs in this manner
// input - (1, 6), (1, 4), (2, 5), (2, 8), (4, 5)
// output - (1, 4), (4, 5), (2, 5), (1, 6), (2, 8)