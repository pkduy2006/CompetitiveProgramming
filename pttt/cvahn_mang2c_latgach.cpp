#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1041][1042];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n, black = 0, white = 0;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j - 1] == 0 && a[i - 1][j] == 1 && a[i][j] == 2 && a[i - 1][j - 1] == 3)
                black++;
            else if(a[i][j - 1] == 1 && a[i - 1][j] == 0 && a[i][j] == 3 && a[i - 1][j - 1] == 2)
                white++;
        }
    }
    cout << black << ' ' << white;
    return 0;
}
