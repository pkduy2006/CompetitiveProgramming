#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, res;
double robot[N], d;

bool pass(int x, int y)
{
    double time_x = x - 1 + d / robot[x], time_y = y - 1 + d / robot[y];
    //cout << fixed << setprecision(5) << time_x << ' ' << time_y << '\n';
      //cout << x << ' ' << y << ' ' << time_x << ' ' << time_y << ' ';
    //if(time_x == time_y)
      //  cout << robot[x] << ' ' << robot[y];
    //cout << '\n';
    //if(time_x == time_y)
      //  return robot[y] > robot[x];
    return time_y < time_x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DUAROBOT.inp","r",stdin);
    freopen("DUAROBOT.out","w",stdout);

    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> robot[i];
    
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(pass(i, j))
                res++;
        }
    }

    cout << res;

    return 0;
}
