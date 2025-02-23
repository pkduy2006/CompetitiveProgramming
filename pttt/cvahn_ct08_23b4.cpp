#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
const int jump_x[] = {-1, 0, 1, 0, -1, 1, -1, 1};
const int jump_y[] = {0, 1, 0, -1, 1, -1, -1, 1};
int m, n, a[N][N], s, res, cnt;
bool mark[N][N];

void dfs(int x, int y, int value)
{
    mark[x][y] = true;
    s++;

    for(int i = 0; i < 8; i++)
    {
        int next_x = x + jump_x[i], next_y = y + jump_y[i];

        if(next_x < 1 || next_x > m || next_y < 1 || next_y > n)
            continue;
        if(mark[next_x][next_y] || a[next_x][next_y] != value)
            continue;
        
        dfs(next_x, next_y, value);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BANGSO.inp","r",stdin);
    freopen("BANGSO.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!mark[i][j])
            {
                s = 0;
                dfs(i, j, a[i][j]);
                if(s >= 2)
                    cnt++;
                //cout << i << ' ' << j << ' ' << s << '\n';
                res = max(res, s);
            }
        }
    }

    cout << cnt << '\n' << res;

    return 0;
}
