#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125;
int a[N], n, res = 0;

bool check(int k)
{
    if(k < 2)
        return true;

    for(int i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
            return true;
    }

    return false;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        if(!check(a[i]))
            continue;

        int t = sqrt(a[i]);
        if(t * t == a[i])
        {
            if(check(t))
                res++;
        }
        else
            res++;
    }

    cout << res;
}

main()
{
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
