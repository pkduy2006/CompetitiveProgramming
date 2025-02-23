#include <bits/stdc++.h>
using namespace std;

int n, x, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bs.inp","r",stdin);
    freopen("bs.out","w",stdout);

    cin >> n >> x;

    for(int i = 1; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            if(i <= n && x / i <= n && i * i != n)
                res += 2;
            else if(i <= n && x / i <= n && i * i == n)
                res++;
        }
    }

    cout << res;

    return 0;
}
