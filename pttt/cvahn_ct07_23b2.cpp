#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 16;
int a[N], b[N], n, f[N][N];
vector<int> trace;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Daydx.inp","r",stdin);
    freopen("Daydx.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    reverse(b + 1, b + 1 + n);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }
    }

    cout << f[n][n] << '\n';

    int x = n, y = n;
    while (x > 0 && y > 0)
    {
        if(a[x] == b[y])
        {
            trace.push_back(a[x]);
           // cout << a[x] << ' ' << b[y] << '\n';
            x--;
            y--;
        }
        else 
        {
            if(f[x - 1][y] < f[x][y - 1])
                y--;
            else
                x--;
        }
    }

    for(int i = trace.size() - 1; i >= 0; i--)
        cout << trace[i] << ' ';
    
    return 0;
}
