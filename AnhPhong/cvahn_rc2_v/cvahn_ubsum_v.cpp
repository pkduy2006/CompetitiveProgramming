#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int INF = 1e17 + 11;
int t, n;

void Read()
{
    cin >> n;
}

void Solve()
{
    int l = 1, r = n, answer = INF;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        int SumLeft = mid * (mid + 1) / 2, sumRight = (n - mid) * (n + mid + 1) / 2;
        answer = min(answer, abs(2 * SumLeft - 3 * sumRight));

        if(2 * SumLeft - 3 * sumRight > 0)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << answer << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UBSUM.inp","r",stdin);
    freopen("UBSUM.out","w",stdout);

    cin >> t;
    while (t--)
    {
        Read();

        Solve();
    }
    
    return 0;
}
