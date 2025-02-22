#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int res = 0, n;
    cin >> n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        while(n % i == 0)
        {
            res = max(res, i);
            n /= i;
        }
    }
    if(n != 1)
        res = max(res, n);
    cout << res;
    return 0;
}
