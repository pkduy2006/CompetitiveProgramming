#include <bits/stdc++.h>
#define int long long
using namespace std;
int g[1027][1028];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                a += g[i][j];
            if(i + j == n + 1)
                b += g[i][j];
            if(i + 1 == j || j + 1 == i)
                c += g[i][j];
            if(i + j == n || i + j == n + 2)
                d += g[i][j];
            if(i < j)
                e += g[i][j];
            if(i + j > n + 1)
                f += g[i][j];
        }
    }
    cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f;
    return 0;
}
