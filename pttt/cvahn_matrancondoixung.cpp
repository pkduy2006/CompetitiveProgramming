#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125;
int a[N][N];

bool check(int c, int b, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[c + i][b + j] != a[c + j][b + i])
                return false;
        }
    }

    return true;
}

main()
{
    freopen("matsym.inp","r",stdin);
    freopen("matsym.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, resA = 1, resB = 1, resN = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int t = 1; t <= n - max(i, j) + 1; t++)
            {
                if(check(i, j, t))
                {
                    if(t > resN)
                    {
                        resA = i;
                        resB = j;
                        resN = t;
                    }
                }
            }
        }
    }

    cout << resA << ' ' << resB << ' ' << resN;

    return 0;
}
