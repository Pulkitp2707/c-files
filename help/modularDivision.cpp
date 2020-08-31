ll binpow(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2)
    {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

//ans=(a/(b*c*d))%MOD;
//ans=a* inv(b) % MOD * inv(c) % MOD * inv(d) % MOD