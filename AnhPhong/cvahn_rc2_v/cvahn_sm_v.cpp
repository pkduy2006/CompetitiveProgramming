#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 11, MOD = 1e9 + 7;
string a, b;
int power[N], hashB, base = 31, hashA[N], res = 0;

int get(int x, int y)
{
    return (hashA[y] - hashA[x - 1] * power[y - x + 1] + MOD * MOD) % MOD;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SM.inp","r",stdin);
    freopen("SM.out","w",stdout);

    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    for(int i = 1; i <= m; i++)
        hashB = (hashB * base + b[i] - 'a' + 1) % MOD;
    
    power[0] = 1;
    for(int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * base) % MOD;
    for(int i = 1; i <= n; i++)
        hashA[i] = (hashA[i - 1] * base + a[i] - 'a' + 1) % MOD;
    
    for(int i = 1; i <= n - m + 1; i++)
    {
        if(hashB == get(i, i + m - 1))
            res++;
    }

    cout << res;

    return 0;
}
