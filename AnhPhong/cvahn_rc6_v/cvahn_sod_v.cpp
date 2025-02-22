#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16, MAXP = 1e7 + 7;
const long long MOD = 1e9 + 7;
int n;
long long res = 1;
int r[(int) 1e7 + 16];
pair<long long, long long> a[N];

long long power(long long x, long long y)
{
    if(y == 0)
        return 1ll;
    
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
    freopen("SOD.INP","r",stdin);
    freopen("SOD.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    
    sort(a + 1, a + 1 + n);

    r[1] = 1;
    for(int i = 2; i < MAXP; i++)
        r[i] = (MOD - (MOD / i) * r[MOD % i] % MOD) % MOD;
    
    for(int i = 1; i <= n; i++)
    {   
        res *= (power(a[i].first, a[i].second + 1) - 1);
        res %= MOD;
        //cout << res << ' ';
        res *= (long long)r[a[i].first - 1];
        res %= MOD; 
        //cout << res << '\n';
    }

    //cout << power(a[2].first, a[2].second + 1) - 1 << '\n';

    cout << res;

    return 0;
}
