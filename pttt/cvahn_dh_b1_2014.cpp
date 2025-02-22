#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 25;
int n, a[N], res = 0;
vector<pair<int, int>> l;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);
    l.clear();
    int cnt = 1, res = 0;

    for(int i = 2; i <= n; i++)
    {
        if(a[i] == a[i - 1])
            cnt++;
        else
        {
            if(cnt >= 2)
                l.push_back({a[i - 1], cnt});

            cnt = 1;
        }

        if(i == n && cnt >= 2)
            l.push_back({a[i], cnt});
    }

    for(int i = 0; i < l.size(); i++)
    {
        if(l[i].second >= 4)
            res = l[i].first * l[i].first;
    }

    if(l.size() < 2 && res == 0)
    {
        cout << -1 << '\n';
        return;
    }

    if(l.size() < 2 && res != 0)
    {
        cout << res << '\n';
        return;
    }

    sort(l.begin(), l.end());

    cout << max(res, l[l.size() - 1].first * l[l.size() - 2].first) << '\n';
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
