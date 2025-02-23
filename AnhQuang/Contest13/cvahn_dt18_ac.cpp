#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16;
const long long INF = 1e15 + 7; 
int n, k;
pair<long long, long long> a[N];

namespace sub1
{
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            long long res = INF;
            for(int j = 1; j <= k; j++)
                res = min(res, a[j].second + abs(a[j].first - i));

            cout << res << ' ';
        }
    }
}

namespace sub2
{
    long long f[N], g[N];
    pair<long long, long long> st[4 * N];

    pair<int, int> operator + (pair<int, int> x, pair<int, int> y)
    {
        pair<int, int> answer;

        answer.first = min(x.first, y.first);
        answer.second = min(x.second, y.second);

        return answer;
    } 

    void Build(int id, int l, int r)
    {
        if(l == r)
        {
            st[id] = {f[l], g[l]};
            return;
        }

        int mid = (l + r) / 2;

        Build(id * 2, l, mid);
        Build(id * 2 + 1, mid + 1, r);

        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    long long get(int id, int l, int r, int x, int y, int type)
    {
        if(r < x || y < l)
            return INF;

        if(x <= l && r <= y)
        {
            if(type == 0)
                return st[id].first;
            else
                return st[id].second;
        }

        int mid = (l + r) / 2;

        return min(get(id * 2, l, mid, x, y, type), get(id * 2 + 1, mid + 1, r, x, y, type));
    }

    void solve()
    {   
        for(int i = 1; i <= (int)4e5; i++)
            st[i].first = st[i].second = INF;
        for(int i = 1; i <= (int)1e5; i++)
            f[i] = g[i] = INF;
        
        for(int i = 1; i <= k; i++)
        {
            f[a[i].first] = a[i].second - a[i].first;
            g[a[i].first] = a[i].second + a[i].first;
        }

        Build(1, 1, n);

        for(int i = 1; i <= n; i++)
            cout << min(get(1, 1, n, 1, i - 1, 0) + i, get(1, 1, n, i, n, 1) - i) << ' '; 
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("AC.inp","r",stdin);
    freopen("AC.out","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> a[i].first;
    for(int i = 1; i <= k; i++)
        cin >> a[i].second;

    if(k <= (int)5e3)
        sub1::solve();
    else
        sub2::solve();

    return 0;
}
