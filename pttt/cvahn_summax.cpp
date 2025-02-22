#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125, INF = 1e15 + 25;
int a[N][N], sum[N][N], n, res = -INF, posA, posB, posI, posJ;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int a = i + 1; a <= n; a++)
            {
                for(int b = j + 1; b <= n; b++)
                {
                    if(res < sum[a][b] - sum[i - 1][b] - sum[a][j - 1] + sum[i - 1][j - 1])
                    {
                        res = sum[a][b] - sum[i - 1][b] - sum[a][j - 1] + sum[i - 1][j - 1];
                        posA = a;
                        posB = b;
                        posI = i;
                        posJ = j;
                    }
                }
            }
        }
    }

    cout << posI << ' ' << posJ << ' ' << posA - posI + 1 << ' ' << posB - posJ + 1 << '\n' << res;
}

main()
{
    freopen("SUMMAX.inp","r",stdin);
    freopen("SUMMAX.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
