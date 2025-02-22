#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n, q, p[N][30], t[N];

void Solve(int pos, int steps)
{
    for(int i = 29; i >= 0; i--)
    {
        if((steps >> i) & 1)
            pos = p[pos][i];
    }

    cout << pos << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TELE.inp","r",stdin);
    freopen("TELE.out","w",stdout);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    
    for(int i = 1; i <= n; i++)
        p[i][0] = t[i];
    for(int i = 1; i <= 29; i++)
    {
        for(int u = 1; u <= n; u++)
            p[u][i] = p[p[u][i - 1]][i - 1];
    }

    while (q--)
    {
        int u, k;
        cin >> u >> k;

        Solve(u, k);
    }

    return 0;
}
