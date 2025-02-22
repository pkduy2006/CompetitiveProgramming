#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, a[N], tmp, res, pos = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DAYCONDN.inp","r",stdin);
    freopen("DAYCONDN.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {   
        if(a[i] > 0)
            tmp++;
        else
        {
            if(res < tmp)
            {
                res = tmp;
                pos = i - tmp;
            }
            tmp = 0;
        }
    }
    if(res < tmp)
    {
        res = tmp;
        pos = n - tmp + 1;
    }

    cout << res << '\n';
    for(int i = pos; i <= pos + res - 1; i++)
        cout << a[i] << ' ';

    return 0;
}
