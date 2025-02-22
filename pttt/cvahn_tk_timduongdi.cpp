#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int m, n, start_x, start_y, end_x, end_y, a[N][N];
bool mark[N][N];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, -1, 0, 1};

void dfs(int x, int y, int d)
{
    mark[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + jump_x[i], next_y = y + jump_y[i];

        if(mark[next_x][next_y] || abs(a[x][y] - a[next_x][next_y]) > d || next_x > m || next_x < 1 || next_y > n || next_y < 1)
            continue;
        
        dfs(next_x, next_y, d);
    }
}

bool check(int d)
{
    memset(mark, false, sizeof(mark));
    dfs(start_x, start_y, d);

    return mark[end_x][end_y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("timduongdi.inp","r",stdin);
    freopen("timduongdi.out","w",stdout);

    cin >> m >> n >> start_x >> start_y >> end_x >> end_y;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    int l = 0, r = 2 * 1e9;

    while (l <= r)
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
