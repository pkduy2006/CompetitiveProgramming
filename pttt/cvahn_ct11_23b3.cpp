#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 16, D = 1e5 + 16;
int n, f[N][D], a[N], sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ct.inp","r",stdin);
    freopen("ct.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        sum += a[i];
    }
    memset(f, -1, sizeof f);
    f[0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < D; j++)
            f[i][j] = f[i - 1][j];

        for(int j = 0; j < D; j++)
        {
            if(f[i - 1][j] == -1)
                continue;

            int d1 = j + a[i];
            int d2 = abs(j - a[i]);
            int val = f[i - 1][j] + a[i];

            f[i][d1] = max(f[i][d1], val);
            f[i][d2] = max(f[i][d2], val);
        }
    }

    cout << f[n][0] / 2;

    return 0;
}
