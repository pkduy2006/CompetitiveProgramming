#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 11;
int a[N][N], start_x, start_y, end_x, end_y, n, m, minDist[N][N];
bool mark[N][N];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, -1, 0, 1};

void bfs(int u, int v)
{
    queue<pair<int, int>> q;
    q.push({u, v});
    mark[u][v] = true;
    memset(minDist, 0x3f3f3f, sizeof minDist);
    minDist[u][v] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + jump_x[i], next_y = y + jump_y[i];

            if(next_x < 1 || next_x > m || next_y < 1 || next_y > n)
                continue;
            if(mark[next_x][next_y] || a[next_x][next_y] == 1)
                continue;
            
            mark[next_x][next_y] = true;
            minDist[next_x][next_y] = minDist[x][y] + 1;
            q.push({next_x, next_y});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Bai4.inp","r",stdin);
    freopen("Bai4.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];

            if(a[i][j] == 2)
            {
                start_x = i;
                start_y = j;
            }

            if(a[i][j] == 3)
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    cout << minDist[end_x][end_y];

    return 0;
}
