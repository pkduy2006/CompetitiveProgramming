#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 11;
int n, q, st[4 * N];

void Build(int id, int l, int r)
{
    if(l == r)
    {
        cin >> st[id];

        return;
    }
    
    int mid = (l + r) / 2;
    
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1]; 
}

void update(int id, int l, int r, int pos, int value)
{
    if(pos < l || r < pos)
        return;

    if(pos == l && l == r)
    {   
        st[id] += value;
        
        return;
    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, pos, value);
    update(id * 2 + 1, mid + 1, r, pos, value);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int x, int y)
{
    if(r < x || y < l)
        return 0;

    if(x <= l && r <= y)
        return st[id];

    int mid = (l + r) / 2;

    return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RSUM.inp","r",stdin);
    freopen("RSUM.out","w",stdout);

    cin >> n >> q;
    Build(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int pos, value;
            cin >> pos >> value;

            update(1, 1, n, pos, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << get(1, 1, n, l, r) << '\n';
        }
    }
    
    return 0;
}
