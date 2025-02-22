#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 11;
int n;
pair<double, double> lines[N];

double Build(int p, int q, int r)
{
    double a = lines[p].second - lines[q].second;
    double b = lines[q].first - lines[p].first;
    double c = lines[p].first * lines[q].second - lines[p].second * lines[q].first;

    return a * lines[r].first + b * lines[r].second + c;
}

bool CheckFourPoint(int t, int m)
{
    for(int i = 1; i <= n; i++)
    {
        if(Build(t, m, i) * Build(t, m, i + 1) < 0)
            return false;
    }

    return true;
}

bool CheckConvex()
{
    for(int i = 1; i < n; i++)
    {
        if(!CheckFourPoint(i, i + 1))
            return false;
    }

    return true;
}

bool CheckTwoPoint(int p, int q)
{
    return Build(p, p + 1, q) * Build(p, p + 1, q + 1) < 0 && Build(q, q + 1, p) * Build(q, q + 1, p + 1) < 0;
}

bool checkFake()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 2; j <= n; j++)
        {
            if(CheckTwoPoint(i, j))
                return true;
        }
    }

    return false;
}

double findS()
{
    double ans = 0;

    for(int i = 1; i <= n; i++)
        ans += (lines[i].first - lines[i + 1].first) * (lines[i].second + lines[i + 1].second) / 2;

    return abs(ans);
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Dagiac.inp","r",stdin);
    freopen("Dagiac.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> lines[i].first >> lines[i].second;
    lines[n + 1] = lines[1];

    if(CheckConvex())
    {
        cout << 1 << '\n';
        cout << fixed << setprecision(3) << findS();
    }
    else
    {
        if(checkFake())
            cout << 3;
        else
        {
            cout << 2 << '\n';
            cout << fixed << setprecision(3) << findS();
        }
    }

    return 0;
}
