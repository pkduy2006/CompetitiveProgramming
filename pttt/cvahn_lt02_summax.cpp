#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[142][143], sum[144][145];
main()
{
    //freopen("MaxSumMatrix.inp","r",stdin);
    //freopen("MaxSumMatrix.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0, col, line, anslength, ansheight;
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
            sum[i][j] = sum[i - 1][j - 1];
            for(int b = 1; b <= j; b++)
                sum[i][j]+=a[i][b];
            for(int c = 1; c <= i; c++)
                sum[i][j]+=a[c][j];
            sum[i][j]-= a[i][j];
        }
    }
    for(int length = 1; length <= n; length++)
    {
        for(int height = 1; height <= n; height++)
        {
            for(int i = 1; i <= n - length + 1; i++)
            {
                for(int j = 1; j <= n - height + 1; j++)
                {
                    if(sum[i + length - 1][j + height - 1] - sum[i + length - 1][j - 1] - sum[i - 1][j + height - 1] + sum[i - 1][j - 1] > res)
                    {
                        res = sum[i + length - 1][j + height - 1] - sum[i + length - 1][j - 1] - sum[i - 1][j + height - 1] + sum[i - 1][j - 1];
                        line = i;
                        col = j;
                        anslength = length;
                        ansheight = height;
                    }
                }
            }
        }
    }
    cout << line << ' ' << col << ' ' << anslength << ' ' << ansheight << '\n' << res;
    return 0;
}
