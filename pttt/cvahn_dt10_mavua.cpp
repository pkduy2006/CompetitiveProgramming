#include <bits/stdc++.h>
#define int long long
using namespace std;

int jump_x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int jump_y[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visitpos[189][190];
int lastX, lastY, n, firstX, firstY;

struct pos
{
    int first, second, dis;
};
int bfs(int x, int y, int z)
{
    queue <pos> q;
    q.push({x ,y, 0});
    visitpos[x][y] = true;
    while(!q.empty())
    {
        int next_x = q.front().first, next_y = q.front().second, next_dis = q.front().dis;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int u = next_x + jump_x[i];
            int v = next_y + jump_y[i];
            if(u <= n && u > 0 && v > 0 && v <= n && !visitpos[u][v])
            {
               visitpos[u][v] = true;
               if(u == lastX && v == lastY)
                    return next_dis + 1;
               q.push({u, v, next_dis + 1});
            }
        }
    }
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> firstX >> firstY >> lastX >> lastY;
    cout << bfs(firstX, firstY, 0);
    return 0;
}
