#include <bits/stdc++.h>
using namespace std;

const int N = 4e2 + 16, MOD = 1e9 + 7;
int a[N][N], u, v, d1, d2, n, m, f[N][N][21][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RMX.INP","r",stdin);
    freopen("RMX.OUT","w",stdout);

    cin >> n >> m >> u >> v >> d1 >> d2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    f[1][1][a[1][1] % u][a[1][1] % v] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1)
                continue;
            
            for(int k = 0; k <= u - 1; k++)
            {
                for(int l = 0; l <= v - 1; l++)
                {
                    int val1 = (k + a[i][j]) % u, val2 = (l + a[i][j]) % v;

                    f[i][j][val1][val2] = f[i - 1][j][k][l] + f[i][j - 1][k][l];
                    f[i][j][val1][val2] %= MOD;
                }
            }
        }
    }

    cout << f[n][m][d1][d2];

    return 0;
}
