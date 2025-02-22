#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9, N = 1e6 + 16;
int k, a[N], n, sum;
long long factorial[N], inverseFactorial[N], res = 1;

int power(long long x, long long y)
{
    if(y == 0)
        return 1;
    
    long long tmp = power(x, y / 2);
    if(y % 2 == 0)
        return (tmp * tmp) % MOD;
    return (((tmp * tmp) % MOD) * x) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CARDS.INP","r",stdin);
    freopen("CARDS.OUT","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> a[i];
    
    factorial[0] = 1;
    for(long long i = 1; i <= (long long) 1e6; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    inverseFactorial[(int) 1e6] = power(factorial[(int) 1e6], MOD - 2);
    for(long long i = (int) 1e6 - 1; i >= 0; i--)
        inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD;
    
    for(int i = 1; i <= k; i++)
    {
        res *= factorial[n - sum];
        res %= MOD;
        res *= inverseFactorial[n - sum - a[i]];
        res %= MOD;
        res *= inverseFactorial[a[i]];
        res %= MOD;
        sum += a[i];
    }

    cout << res;
    return 0;
}
