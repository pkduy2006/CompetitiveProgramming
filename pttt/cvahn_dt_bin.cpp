#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;

int n, p;
vector<int> par(N, -1);

int root(int v)
{
    return par[v] < 0 ? v : root(par[v]);
}

void mergeTree(int x, int y)
{
    int root_x = root(x), root_y = root(y);
    if(root_x == root_y)
        return;

    if(par[root_x] < par[root_y])
        swap(root_x, root_y);
    par[root_x] += par[root_y];
    par[root_y] = root_x;
}

main()
{
    freopen("bin.inp","r",stdin);
    freopen("bin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> p;
    n = 10000;

    for(int i = 1; i <= p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if(z == 1)
            mergeTree(x, y);
        else
        {
            if(root(x) == root(y))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}
