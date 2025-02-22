#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25, maxN = 1e6 + 25;
int n, x, y, a[N], res = 0;
bool mark[maxN], remark[maxN];

void Read()
{
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Build()
{
    fill(mark, mark + maxN, true);

    mark[0] = false;
    mark[1] = false;

    for(int i = 2; i <= sqrt(maxN); i++)
    {
        if(mark[i])
        {
            for(int j = i * i; j <= maxN; j += i)
                mark[j] = false;
        }
    }
}

void Solve()
{
    Build();
    fill(remark, remark + maxN, false);

    while(x <= maxN)
    {
        remark[x] = true;
        x += y;
    }

    for(int i = 1; i <= n; i++)
    {
        if(mark[a[i]] && remark[a[i]])
        {
            res++;
        }
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
