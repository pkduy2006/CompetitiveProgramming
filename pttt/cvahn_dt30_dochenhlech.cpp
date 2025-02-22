#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e2 + 11;
int n, m, a[N][N], start_x, start_y, end_x, end_y;
bool mark[N][N];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};

bool bfs(int dif)
{
    queue<pair<int, int>> q;
    memset(mark, false, sizeof mark);
    q.push({start_x, start_y});
    mark[start_x][start_y] = true;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if(x == end_x && y == end_y)
            return true;

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + jump_x[i], next_y = y + jump_y[i];

            if(next_x < 1 || next_x > n || next_y < 1 || next_y > m)
                continue;

            if(mark[next_x][next_y] || abs(a[x][y] - a[next_x][next_y]) > dif)
                continue;

            mark[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Bai5.inp","r",stdin);
    freopen("Bai5.out","w",stdout);

    cin >> n >> m >> start_x >> start_y >> end_x >> end_y;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    int l = 0, r = (int)1e9;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(bfs(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}
