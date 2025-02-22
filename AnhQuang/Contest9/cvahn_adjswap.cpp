#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N];
long long res = 0;

namespace sub1
{
    int pos;

    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[j] == i)
                {
                    pos = j;
                    break;
                }
            }

            if(pos < i)
            {
                for(int j = i; j > pos; j++)
                {   
                    swap(a[j], a[j + 1]);
                    res++;
                }
            }
            else
            {
                for(int j = pos; j > i; j--)
                {   
                    swap(a[j - 1], a[j]);
                    res++;
                }
            }
        }

        cout << res;
    }
}

namespace sub2
{
    int st[4 * N];
    
    int get(int id, int l, int r, int x, int y)
    {
        if(r < x || y < l)
            return 0;
        
        if(x <= l && r <= y)
            return st[id];

        int mid = (l + r) / 2;

        return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
    }

    void update(int id, int l, int r, int value)
    {
        if(value < l || r < value)
            return;

        if(r == l && value == l)
        {
            st[id] = 1;
            return;
        }

        int mid = (l + r) / 2;

        update(id * 2, l, mid, value);
        update(id * 2 + 1, mid + 1, r, value);

        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            res += get(1, 1, n, a[i] + 1, n);
            update(1, 1, n, a[i]);
        }

        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ADJSWAP.INP","r",stdin);
    freopen("ADJSWAP.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)  
        cin >> a[i];

    //if(n <= (int) 5e3)
     //   sub1::solve();
    //else
        sub2::solve();

    return 0;
}
