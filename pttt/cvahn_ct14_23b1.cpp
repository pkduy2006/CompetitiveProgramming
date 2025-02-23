#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 16;
int p, par[N];

struct DisJoinSet
{
    int root(int x)
    {
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
    }

    bool open_valve(int x, int y)
    {
        if((x = root(x)) == (y = root(y)))
            return false;
        if(par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
}dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bin.inp","r",stdin);
    freopen("bin.out","w",stdout);

    fill(par, par + N, -1);

    cin >> p;
    for(int i = 1; i <= p; i++)
    {
        int x, y, type;
        cin >> x >> y >> type;

        if(type == 1)
            dsu.open_valve(x, y);
        else
        {
            if(dsu.root(x) == dsu.root(y))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }

    return 0;
}
