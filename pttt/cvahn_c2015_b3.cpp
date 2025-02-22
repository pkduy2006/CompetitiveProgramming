#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, total = 1, res = 0;
    cin >> n;

    while(total <= n)
    {
        total += (1 << res);
        res++;
    }

    cout << res - 1;
    return 0;
}
