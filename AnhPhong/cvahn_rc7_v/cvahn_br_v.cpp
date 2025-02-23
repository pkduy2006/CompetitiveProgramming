#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int st[4 * N], n, q, a[N];

void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = l;

        return;
    }

    int mid = (l + r) / 2;

    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);

    if(a[st[id * 2]] <= a[st[id * 2 + 1]])
        st[id] = st[id * 2];
    else
        st[id] = st[id * 2 + 1];
}

void update(int id, int l, int r, int pos)
{
    if(pos < l || r < pos)
        return;
    
    if(pos == l && r == l)
    {
        st[id] = pos;

        return;
    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, pos);
    update(id * 2 + 1, mid + 1, r, pos);

    if(a[st[id * 2]] <= a[st[id * 2 + 1]])
        st[id] = st[id * 2];
    else
        st[id] = st[id * 2 + 1];
}

int get(int id, int l, int r, int value)
{
    if(a[st[id]] < value && l == r)
        return st[id];

    int mid = (l + r) / 2;

    if(a[st[id * 2]] < value)
        return get(id * 2, l, mid, value);
    else
        return get(id * 2 + 1, mid + 1, r, value);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BR.inp","r",stdin);
    freopen("BR.out","w",stdout);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int p, w;
            cin >> p >> w;

            a[p] = w;
            update(1, 1, n, p);
        }
        else
        {
            int x;
            cin >> x;

            if(a[st[1]] >= x) 
                cout << -1 << '\n';
            else
                cout << get(1, 1, n, x) << '\n';
        }
    }
    
    return 0;
}
