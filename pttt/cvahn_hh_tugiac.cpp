#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-9;
pair<double, double> lines[5];

bool check(int x, int y, int z)
{
    double a = lines[y].second - lines[x].second;
    double b = lines[x].first - lines[y].first;
    double c = lines[x].first * lines[y].second - lines[x].second * lines[y].first;

    return a * lines[z].first + b * lines[z].second == c;
}

bool review(int x, int y, double m, double n)
{
    double limitLeft = min(lines[x].first, lines[y].first);
    double limitRight = max(lines[x].first, lines[y].first);
    double limitDown = min(lines[x].second, lines[y].second);
    double limitUp = max(lines[x].second, lines[y].second);

    return limitLeft <= m && m <= limitRight && limitDown <= n && n <= limitUp;
}

bool findIntersect(int x, int y, int z, int t)
{
    double firstA = lines[y].second - lines[x].second;
    double firstB = lines[x].first - lines[y].first;
    double firstC = lines[x].first * lines[y].second - lines[x].second * lines[y].first;

    double secondA = lines[t].second - lines[z].second;
    double secondB = lines[z].first - lines[t].first;
    double secondC = lines[z].first * lines[t].second - lines[z].second * lines[t].first;

    double d = firstA * secondB - secondA * firstB;

    if(d == 0)
        return false;
    else
    {
        double m = (secondB * firstC - firstB * secondC) / d;
        double n = (firstA * secondC - secondA * firstC) / d;

        if(review(x, y, m, n) && review(z, t, m, n))
            return true;
    }

    return false;
}

double findS()
{
    double ans = 0;

    for(int i = 0; i < 4; i++)
        ans += (lines[i].first - lines[i + 1].first) * (lines[i].second + lines[i + 1].second) / 2;

    return abs(ans);
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("tugiac.inp","r",stdin);
    freopen("tugiac.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++)
        cin >> lines[i].first >> lines[i].second;
    lines[4].first = lines[0].first;
    lines[4].second = lines[0].second;

    if(check(0, 1, 2) || check(0, 1, 3))
    {
        cout << 0;
        return 0;
    }

    if(findIntersect(0, 2, 1, 3))
    {
        cout << 1 << '\n';
        cout << fixed << setprecision(3) << findS();

        return 0;
    }

    if(findIntersect(0, 1, 2, 3) || findIntersect(0, 3, 1, 2))
    {
        cout << 3 << '\n';

        return 0;
    }

    cout << 2 << '\n';
    cout << fixed << setprecision(3) << findS();

    return 0;
}
