#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[139][140];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n, m1, n1, res = 0, ansline = 0, anscol = 0;
    cin >> m >> n >> m1 >> n1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= m - m1 + 1; i++)
    {
        for(int j = 1; j <= n - n1 + 1; j++)
        {
            int sum = 0;
            for(int line = i; line <= i + m1 - 1; line++)
            {
                for(int col = j; col <= j + n1 - 1; col++)
                    sum += a[line][col];
            }
            if(sum > res)
            {
                res = sum;
                ansline = i;
                anscol = j;
            }
        }
    }
    cout << res << '\n' << ansline << ' ' << anscol;
    return 0;
}
