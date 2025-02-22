#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 16, M = 1e6 + 16, MOD = 1e9 + 7;
int n, sum = 0, a[N], factorial[M], InverseFactorial[M];

int power(int x, int y)
{
    if(y == 0)
        return 1ll;
    
    long long tmp = power(x, y / 2);

    if(y % 2 == 0)
        return (tmp * tmp) % MOD;
    return ((tmp * tmp) % MOD * x) % MOD;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NDM.INP","r",stdin);
    freopen("NDM.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        
        sum += a[i];
    }

    factorial[0] = 1ll;
    for(int i = 1; i <= (int) 1e6; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    InverseFactorial[(int) 1e6] = power(factorial[(int) 1e6], MOD - 2);
    for(int i = (int) 1e6 - 1; i >= 0; i--)
        InverseFactorial[i] = (InverseFactorial[i + 1] * (i + 1)) % MOD;

    int res = factorial[sum];
    for(int i = 1; i <= n; i++)
    {   
        res *= InverseFactorial[a[i]];
        res %= MOD;
    }
    cout << res;

    return 0;
}
