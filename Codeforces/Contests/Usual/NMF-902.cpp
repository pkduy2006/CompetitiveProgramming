// Hello 2025 D. Gifts Order
// https://codeforces.com/contest/2057/problem/D

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, q, a[N];

struct Node
{
    int v, w, x, y, z;

    friend Node operator+(const Node& me, const Node& her);
} st[4 * N];

Node operator+(const Node& me, const Node& her)
{
    return {max(me.v, her.v), min(me.w, her.w), max(me.x, her.x), min(me.y, her.y), max({me.z, her.z, me.v - her.w, her.x - me.y})};
}

void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id].v = st[id].w = a[l] + l;
        st[id].x = st[id].y = a[l] - l;
        st[id].z = 0;
        return;
    }
    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int pos, int val)
{
    if(pos < l || pos > r)
        return;
    if(pos == l && l == r)
    {
        st[id].v = st[id].w = val + pos;
        st[id].x = st[id].y = val - pos;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1, 1, n);
    cout << st[1].z << '\n';
    while(q--)
    {
        int p, x;
        cin >> p >> x;
        update(1, 1, n, p, x);
        cout << st[1].z << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();

    return 0;
}