#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e2 + 16;
int n, f[N], sum, res;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FIBONACI.inp","r",stdin);
    freopen("FIBONACI.out","w",stdout);

    cin >> n;
    
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        sum += f[i];
    }

    for(int i = 1; i <= n; i++)
    {
        if(f[i] > sum / n)
            res++;
    }

    for(int i = 1; i <= n; i++)
        cout << f[i] << ' ';
    cout << '\n' << res;

    return 0;
}
