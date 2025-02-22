#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

int change(int t)
{
    int ans = 0;
    while(t > 0)
    {
        ans += t % 10;
        t /= 10;
    }

    return ans;
}

void Read()
{
    cin >> n;
}

void Solve()
{
    int res = n;
    while(res >= 10)
        res = change(res);

    cout << res << '\n';
}

main()
{
    freopen("Digits.inp","r",stdin);
    freopen("Digits.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
