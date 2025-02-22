#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;

int power(int n, int k)
{
    if(k == 0)
        return 1;

    int t = power(n, k / 2);

    if(k % 2 == 0)
        return t * t;
    else
        return t * t * n;
}

bool check(int t)
{
    int cnt = 0;
    while(t > 0)
    {
        if(t % 2 == 0)
            cnt++;

        t /= 2;
    }

    if(cnt == k)
        return true;
    return false;
}

void Read()
{
    cin >> n >> k;
}

void Solve()
{
    int t = power(2, k), res = 0;
    for(int i = t; i <= n; i++)
    {
        if(check(i))
            res++;
    }

    cout << res << '\n';
}

main()
{
    freopen("so.inp","r",stdin);
    freopen("so.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
