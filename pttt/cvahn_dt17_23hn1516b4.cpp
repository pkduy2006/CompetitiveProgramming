#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
const int M = 1e9 + 7;
const int jump_x[] = {-1, 0, 1, 0};
const int jump_y[] = {0, 1, 0, -1};
int m, n, start_x, start_y, end_x, end_y, a[N][N];
bool mark[N][N];

bool check(int d)
{
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    memset(mark, false, sizeof mark);
    mark[start_x][start_y] = true;
    while (!q.empty())
    {
        auto s = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int next_x = s.first + jump_x[i], next_y = s.second + jump_y[i];
            if(next_x < 1 || next_x > m || next_y < 1 || next_y > n)
                continue;
            if(mark[next_x][next_y] || abs(a[s.first][s.second] - a[next_x][next_y]) > d)
                continue;

            if(next_x == end_x && next_y == end_y)
                return true;
            mark[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai4.inp","r",stdin);
    freopen("Bai4.out","w",stdout);

    cin >> m >> n >> start_x >> start_y >> end_x >> end_y;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    int l = 0, r = M;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}
