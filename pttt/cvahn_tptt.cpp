#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 450 + 25, INF = 1e15 + 25;
int d[N][N], m, n;

void Read()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;

            d[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = min(d[x][y], w);
        d[y][x] = min(d[x][y], w);
    }
}

void Solve()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }

    int res = 0, check = true, cntRes = INF;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(d[i][j] == INF && d[j][i] == INF)
                check = false;

            cnt+=d[i][j];
        }

        if(cnt < cntRes)
        {
            res = 1;
            cntRes = cnt;
        }
        else if(cnt == cntRes)
            res++;

    }

    if(check)
        cout << cntRes << ' ' << res;
    else
        cout << 0;
}

main()
{
    freopen("omega.inp","r",stdin);
    freopen("omega.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
