#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 25;
int a, b, mark[N];

void Build(int n)
{
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            mark[n - a]++;
            if(i * i != n)
                mark[n - a]++;
        }
    }
}

void Read()
{
    cin >> a >> b;

    for(int i = a; i <= b; i++)
        Build(i);
}

void Solve()
{
    int t = *max_element(mark, mark + b - a), res = 0, ans = 0;
    for(int i = a; i <= b; i++)
    {
        if(mark[i - a] == t)
        {
            res = i;
            break;
        }
    }

    for(int i = a; i <= b; i++)
    {
        if(mark[i - a] == t)
            ans++;
    }

    cout << res << ' ' << mark[res - a] << ' ' << ans << ' ';
}

main()
{
    freopen("UOCSO.inp","r",stdin);
    freopen("UOCSO.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
