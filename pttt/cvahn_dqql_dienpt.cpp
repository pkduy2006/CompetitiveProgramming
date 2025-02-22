#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7;

double a[109], m, NearestM, res = 0, ans[110];
int sign[111], SmallSign[112], n;

double SmallCal(double a, double b, int d)
{
    if(d == 1)
        return a + b;
    if(d == 2)
        return a - b;
    if(d == 3)
        return a * b;
    else
        return a / b;
}

double Calculate()
{
    int indexer = 1;
    ans[1] = a[1];

    for(int i = 1; i < n; i++)
    {
        if(sign[i] == 3 || sign[i] == 4)
            ans[indexer] = SmallCal(ans[indexer], a[i + 1], sign[i]);
        else
        {
            SmallSign[indexer] = sign[i];
            indexer++;
            ans[indexer] = a[i + 1];
        }
    }
    for(int i = 1; i < indexer; i++)
        ans[1] = SmallCal(ans[1], ans[i + 1], SmallSign[i]);
    return ans[1];
}

void Solve(int i)
{
    for(int j = 1; j <= 4; j++)
    {
        sign[i] = j;
        if(i == n - 1)
        {
            double ans = Calculate();
            if(m - ans < NearestM && m >= ans)
            {
                NearestM = m - ans;
                res = ans;
            }
        }
        else
            Solve(i + 1);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    NearestM = m;

    Solve(1);

    cout << fixed << setprecision(3) << res;
    return 0;
}
