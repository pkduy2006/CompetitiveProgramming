#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[141][142], value[143][144];
main()
{
    //freopen("SymetricMatrix.inp","r",stdin);
    //freopen("SymetricMatrix.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, pos1, pos2, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int length = 2; length <= n; length++)
    {
        for(int i = 1; i <= n - length + 1; i++)
        {
            for(int j = 1; j <= n - length + 1; j++)
            {
                bool check = true;
                for(int line = i; line <= i + length - 1; line++)
                {
                    for(int col = j; col <= j + length - 1; col++)
                        value[line - i + 1][col - j + 1] = a[line][col];
                }
                for(int k = 1; k <= length; k++)
                {
                    for(int t = 1; t <= length; t++)
                    {
                        if(value[k][t] != value[t][k])
                            check = false;
                    }
                }
                if(check == true)
                {
                    if(length > res)
                    {
                        res = length;
                        pos1 = i;
                        pos2 = j;
                    }
                    break;
                }
            }
        }
    }
    cout << pos1 << ' ' << pos2 << ' ' << res;
    return 0;
}
