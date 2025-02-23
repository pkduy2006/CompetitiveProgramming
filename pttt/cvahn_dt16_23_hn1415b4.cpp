#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16, INF = 1e9 + 16;
const int jump_x[] = {-1, 1, 0, 0};
const int jump_y[] = {0, 0, 1, -1};
int m, n, x, y, a[N][N], biggest_s, s, dis[N][N], res = INF;
vector<pair<int, int>> saved_pos, biggest_island;
bool mark[N][N], biggest_island_pos[N][N];

void dfs_s(int pos_x, int pos_y)
{
    mark[pos_x][pos_y] = true;
    saved_pos.push_back({pos_x, pos_y});
    s++;

    for(int i = 0; i < 4; i++)
    {
        int next_x = pos_x + jump_x[i], next_y = pos_y + jump_y[i];

        if(next_x < 1 || next_x > m || next_y < 1 || next_y > n)
            continue;
        if(mark[next_x][next_y] || !a[next_x][next_y])
            continue;

        dfs_s(next_x, next_y);
    }
}

void bfs(int pos_x, int pos_y)
{
    queue<pair<int, int>> q;
    q.push({pos_x, pos_y});
    mark[pos_x][pos_y] = true;

    while (!q.empty())
    {
        auto[u, v] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_u = u + jump_x[i], next_v = v + jump_y[i];

            if(biggest_island_pos[next_u][next_v])
                res = min(dis[u][v], res);

            if(next_u < 1 || next_u > m || next_v < 1 || next_v > n)
                continue;
            if(mark[next_u][next_v] || a[next_u][next_v])
                continue;
            
            mark[next_u][next_v] = true;
            dis[next_u][next_v] = dis[u][v] + 1;
            q.push({next_u, next_v});
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

    cin >> m >> n >> x >> y;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1 && !mark[i][j])
            {
                s = 0;
                saved_pos.clear();
                dfs_s(i, j);

                if(s > biggest_s)
                {
                    biggest_s = s;
                    biggest_island = saved_pos;
                }
            }
        }
    }

    for(int i = 0; i < biggest_island.size(); i++)
        biggest_island_pos[biggest_island[i].first][biggest_island[i].second] = true;
    memset(mark, false, sizeof mark);
    bfs(x, y);

    cout << res;
    
    return 0;
}
