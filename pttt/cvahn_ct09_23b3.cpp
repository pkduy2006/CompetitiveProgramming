#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18 + 9;
int n, k, maxA, minB = INF;
vector<pair<int, int>> point;

namespace sub2
{
    void solve()
    {
        cout << max(0ll, minB - maxA + 1);
    }
}

namespace sub1and3
{
    void solve()
    {
        int cur = 0, res = 0;
        
        sort(point.begin(), point.end());

        for(int i = 0; i < point.size(); i++)
        {
            cur += point[i].second;

            if(cur == k)
                res += point[i + 1].first - point[i].first;
        }

        cout << res;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dc.inp","r",stdin);
    freopen("dc.out","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        maxA = max(a, maxA);
        minB = min(b, minB);
        point.push_back({a, 1});
        point.push_back({b + 1, -1});
    }

    if(n == k)
        sub2::solve();
    else
        sub1and3::solve();

    return 0;
}
