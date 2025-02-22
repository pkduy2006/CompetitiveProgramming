#include <bits/stdc++.h>
using namespace std;
int n,a[1000][1000],b[1000][1000],c[1000],d[1000],dem = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    b[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
    {
        b[1][i] = b[1][i-1] + a[1][i];
        b[i][1] = b[i-1][1] + a[i][1];
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            b[i][j] = min(b[i-1][j], b[i][j-1]) + a[i][j];
    cout << b[n][n] << endl;
    int i = n, j = n;
    d[1] = n; c[1] = n;
    while (i > 0 && j > 0)
        if (b[i][j] == b[i-1][j] + a[i][j])
        {
            dem++;
            d[dem] = i - 1;
            c[dem] = j;
            i--;
        }
        else
        {
            dem++;
            d[dem] = i;
            c[dem] = j-1;
            j--;
        }
    for (int i = dem-1; i >= 1; i--)
        cout << d[i] << ',' << c[i] << endl;
}
