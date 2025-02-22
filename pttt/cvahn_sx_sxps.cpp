#include <bits/stdc++.h>
#define int long long
using namespace std;
vector< pair <int, int> > factor;
bool cmp(pair < int, int> a, pair <int, int> b)
{
    return a.first * b.second < a.second * b.first;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    factor.push_back(make_pair(0, 1));
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(__gcd(i, j) == 1)
                factor.push_back(make_pair(i, j));
        }
    }
    factor.push_back(make_pair(1, 1));
    sort(factor.begin(), factor.end(), cmp);
    cout << factor[k - 1].first << '/' << factor[k - 1].second;
    return 0;
}
