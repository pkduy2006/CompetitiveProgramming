#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, k;
vector<pair<int, int>> a;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second < x.second * y.first;
}

void Read()
{
    cin >> n >> k;
}

void Solve()
{

    a.push_back({0, 1});
    a.push_back({1, 1});
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(__gcd(i, j) == 1)
                a.push_back({j, i});
        }
    }

    sort(a.begin(), a.end(), cmp);

    cout << a[k - 1].first << '/' << a[k - 1].second;
}

main()
{
    freopen("sxps.inp","r",stdin);
    freopen("sxps.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
