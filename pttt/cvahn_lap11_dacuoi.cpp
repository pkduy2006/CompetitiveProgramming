#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17 + 16;
long long n, res = INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(long long i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            res = min(res, (n / i + i) * 2);
    }

    cout << res;

    return 0;
}
