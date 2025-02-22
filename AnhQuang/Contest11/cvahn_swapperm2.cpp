#include <bits/stdc++.h>
using namespace std;

const int N = 25e2 + 16;
const long long MOD = 1e9 + 7;
long long f[N][N], res = 0;
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SWAPPERM2.INP","r",stdin);
    freopen("SWAPPERM2.OUT","w",stdout);

    cin >> n >> k;

    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (i - 1)) % MOD;
    }

    for(int i = 0; i <= k; i++)
    {
        res += f[n][n - i];
        res %= MOD;
    }

    cout << res;

    return 0;
}
