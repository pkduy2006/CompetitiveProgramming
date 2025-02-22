#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
int d[N][N], n, m, res = 0, cnt = 0, trace[N][N];

struct roads
{
    int u, v, w;
};
vector<roads> a;

bool findBack(int x, int y)
{
    int ans = 0;
    while (y != x)
    {
        ans++;
        y = trace[y][x];
    }

    return (ans == 1);
}

void setup()
{
    memset(d, 0x3f3f3f, sizeof d);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            trace[i][j] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("city.inp","r",stdin);
    freopen("city.out","w",stdout);

    cin >> n >> m;
    setup();
    for(int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        
        a.push_back({x, y, c});
        d[x][y] = min(d[x][y], c);
        d[y][x] = min(d[y][x], c);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(d[i][j] >= d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        if(findBack(a[i].u, a[i].v))
        {
            cnt++;
            res += a[i].w;
        }
    }

    cout << cnt << ' ' << res;

    return 0;
}
