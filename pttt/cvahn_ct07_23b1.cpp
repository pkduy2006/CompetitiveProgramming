#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, res, res_cnt;
pair<int, int> f[N];
struct guest
{
    int a, b, c;
}g[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("thuemay.inp","r",stdin);
    freopen("thuemay.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> g[i].a >> g[i].b >> g[i].c;

    sort(g + 1, g + 1 + n, [&] (const guest& me, const guest& her)
    {
        return me.a < her.a || (me.a == her.a && me.b < her.b) || (me.a == her.a && me.b == her.b && me.c < her.c);
    });

    for(int i = 1; i <= n; i++)
    {
        f[i] = {g[i].c, 1};
        for(int j = 1; j < i; j++)
        {
            if(g[j].b < g[i].a)
            {
                if(f[i].first < f[j].first + g[i].c)
                {
                    f[i].first = f[j].first + g[i].c;
                    f[i].second = f[j].second + 1; 
                }
            }
        }

        if(f[i].first > res)
        {
            res = f[i].first;
            res_cnt = f[i].second;
        }
    }

    cout << res_cnt << ' ' << res;

    return 0;
}
