
for (int i = 2; i <= MAXN; i++)
    prime[i] = i;
for (int i = 2; i * i <= MAXN; i++)
{
    if (prime[i] == i)
    {
        for (int j = i * i; j <= MAXN; j += i)
            if (prime[j] == j)
                prime[j] = i;
    }
}
// ll num=x;
// while(num!=1)
// {
//     v.pb(prime[num]);
//     num/=prime[num];
// }

// if num=12  v->2 2 3