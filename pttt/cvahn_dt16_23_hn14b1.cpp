#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 25, INF = 1e17 + 25;
int a[N], st[4 * N], res = 0, n;

void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int x, int y)
{
    if(r < x || y < l)
        return INF;

    if(x <= l && r <= y)
        return st[id];

    int mid = (l + r) / 2;

    return min(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    Build(1, 1, n);

    for(int i = 2; i <= n; i++)
    {
        int m = get(1, 1, n, 1, i - 1);

        if(abs(a[i] - m) > res)
            res = a[i] - m;
    }

    cout << res;
}

main()
{
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
