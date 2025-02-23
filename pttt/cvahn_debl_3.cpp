#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, k, sum[N][N], a[N][N], res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i = 1; i <= n - k + 1; i++)
    {
        for(int j = 1; j <= n - k + 1; j++)
            res = max(res, sum[i + k - 1][j + k - 1] - sum[i - 1][j + k - 1] - sum[i + k - 1][j - 1] + sum[i - 1][j - 1]);
    }

    cout << res;

    return 0;
}
