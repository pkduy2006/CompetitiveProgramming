#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int n, a[N][N], x = 1, y = 1, res[N][N], cnt = 1, limit_up_x = 1, limit_down_x, limit_left_y = 1, limit_right_y;
vector<int> second_a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            second_a.push_back(a[i][j]);
        }
    }

    sort(second_a.begin(), second_a.end());

    res[1][1] = second_a.front();
    second_a.erase(second_a.begin());
    x = 1;
    y = 2;
    limit_down_x = limit_right_y = n;
    while (!second_a.empty())
    {
        res[x][y] = second_a.front();
        second_a.erase(second_a.begin());
        
        //cout << cnt << ' ' << x << ' ' << y << ' ' << limit_up_x << ' ' << limit_down_x << ' ' << limit_left_y << ' ' << limit_right_y << '\n';
        if(x == limit_up_x && y == limit_right_y)
            cnt = 2;
        else if(x == limit_down_x && y == limit_right_y)
            cnt = 3;
        else if(x == limit_down_x && y == limit_left_y)
            cnt = 4;
        else if(x == limit_up_x + 1 && y == limit_left_y)
        {
            cnt = 1;
            limit_up_x++;
            limit_down_x--;
            limit_right_y--;
            limit_left_y++;
        }

        if(cnt == 1)
            y++;
        else if(cnt == 2)
            x++;
        else if(cnt == 3)
            y--;
        else
            x--;
    }

    cout << n << '\n';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;   
}
