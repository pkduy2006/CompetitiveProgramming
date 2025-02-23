#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int p, x, y, type, par[N];

struct DisJoinSet
{
    int root(int v)
    {
        return par[v] < 0 ? v : (par[v] = root(par[v]));
    }

    bool Merge(int x, int y)
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

void ss()
{
    cin >> x >> y >> type;

    if(type == 1)
        dsu.Merge(x, y);
    else
    {
        if(dsu.root(x) == dsu.root(y))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("bin.inp","r",stdin);
    freopen("bin.out","w",stdout);

    fill(par, par + N, -1);
    cin >> p;
    while(p--)
        ss();

    return 0;
}
