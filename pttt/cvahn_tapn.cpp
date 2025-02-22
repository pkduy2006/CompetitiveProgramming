#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> res;

int power(int x, int y)
{
    if(y == 0)
        return 1;

    int t = power(x, y / 2);

    if(y % 2 == 1)
        return t * t * x;
    else
        return t * t;
}

void Read()
{
    cin >> n >> m;
}

void Solve()
{
    res.push_back(0);
    res.push_back(1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = power(2, i - 1); j <= power(2, i) - 1; j++)
        {
            res.push_back(2 * res[j] + 1);
            res.push_back(3 * res[j] + 1);
        }
    }

    sort(res.begin() + power(2, n), res.begin() + power(2, n + 1) - 1);

    cout << res[power(2, n) + m - 1];
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Tapn.inp","r",stdin);
    freopen("Tapn.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
