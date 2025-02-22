#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125;
int n, m, a[N][N], cnt = 0, maxS = 0, maxP = 0, s = 0;
bool mark[N][N];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    mark[x][y] = true;
    s++;

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + jump_x[i], next_y = y + jump_y[i];

        if(a[next_x][next_y] == 0)
            cnt++;

        if(mark[next_x][next_y] || a[next_x][next_y] == 0)
            continue;

        if(next_x > n || next_x < 1 || next_y > m || next_y < 1)
            continue;

        dfs(next_x, next_y);
    }
}

void Read()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!mark[i][j] && a[i][j] == 1)
            {
                cnt = 0;
                s = 0;

                dfs(i, j);

                maxS = max(s, maxS);
                maxP = max(cnt, maxP);
            }
        }
    }

    cout << maxS << ' ' << maxP;
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
