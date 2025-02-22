#include <bits/stdc++.h>
using namespace std;

vector<pair<double, double>> factor;
int n, k;

bool cmp(pair<double, double> me, pair<double, double> her)
{
    return me.first / me.second < her.first / her.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sxps.inp","r",stdin);
    freopen("sxps.out","w",stdout);

    cin >> n >> k;
    factor.push_back({0, 1});
    factor.push_back({1, 1});
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i - 1; j++)
        {
            if(__gcd(j, i) == 1)
                factor.push_back({j, i});
        }
    }

    sort(factor.begin(), factor.end(), cmp);

    cout << factor[k - 1].first << '/' << factor[k - 1].second;

    return 0;
}
