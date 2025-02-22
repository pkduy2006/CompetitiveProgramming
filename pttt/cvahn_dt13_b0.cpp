#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, dp[N], res = 1;
vector<int> ans;

struct com
{
    int x, y, t, idx;
} a[N];

bool cmp(com m, com n)
{
    if(m.y == n.y)
    {
        if(m.x == n.x)
            return m.t < n.t;

        return m.x < n.x;
    }

    return m.y < n.y;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].t;
        a[i].idx = i;
    }
}

void Solve()
{
    sort(a + 1, a + 1 + n, cmp);

    dp[1] = a[1].t;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = a[i].t;
        for(int j = 1; j < i; j++)
        {
            if(a[i].x > a[j].y)
                dp[i] = max(dp[i], dp[j] + a[i].t);
        }

        if(dp[i] > dp[res])
            res = i;
    }

    ans.push_back(a[res].idx);
    while(dp[res] > a[res].t)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dp[res] - a[res].t == dp[i])
            {
                ans.push_back(a[i].idx);
                res = i;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << ' ' << *max_element(dp + 1, dp + 1 + n) << '\n';
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("thuemay.inp","r",stdin);
    freopen("thuemay.out","w",stdout);
    Read();

    Solve();

    return 0;
}
