#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e2 + 11;
int n, a, b;
long double f[6 * N][N], total; // số cách để lắc được tổng kết quả là i sau j lần

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("DICE.inp","r",stdin);
    freopen("DICE.out","w",stdout);

    cin >> n >> a >> b;

    f[0][0] = 1;

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= 600; i++)
        {
            for(int k = 1; k <= 6; k++)
            {
                if(i - k >= 0)
                    f[i][j] += f[i - k][j - 1];
            }

            f[i][j] /= 6;
        }
    }

    for(int i = a; i <= b; i++)
        total += f[i][n];

    cout << fixed << setprecision(6) << total;

    return 0;
}
