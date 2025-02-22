#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long g[50];
int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FUNCTION.INP","r",stdin);
    freopen("FUNCTION.OUT","w",stdout);

    g[1] = 1;
    for(long long i = 2; i <= 41; i++)
    {
        long long tmp = __gcd(g[i - 1], i);
        g[i] = g[i - 1] * i / tmp;
    }

    cin >> t;
    while (t--)
    {
        long long n, res = 0;
        cin >> n;

        for(int i = 2; i <= 41; i++)
        {   
            res += (n / g[i - 1] - n / g[i]) * i;
            res %= MOD;
        }

        cout << res << '\n';
    }
    
    return 0;
}
