#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int a[N], n, res = 0, resPlus = 0;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int dif = a[j] - a[i];
            int next = a[j] + dif, cnt = 2;

            for(int t = j + 1; t <= n; t++)
            {
                if(a[t] == next)
                {
                    cnt++;
                    next = a[t] + dif;
                }
            }

            if(cnt > res)
            {
                res = cnt;
                resPlus = dif;
            }
        }
    }

    if(n == 1)
        cout << 0;
    else
        cout << res << ' ' << resPlus;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
