#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int a[N], n;
vector<pair<int, int>> res;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);
    res.push_back({a[1], 1});

    for(int i = 2; i <= n; i++)
    {
        if(a[i] != a[i - 1])
            res.push_back({a[i], 1});
        else
            res.back().second++;
    }

    for(int i = 0; i < res.size(); i++)
        cout << res[i].first << ':' << res[i].second << '\n';
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
