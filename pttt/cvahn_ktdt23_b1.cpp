#include <bits/stdc++.h>
using namespace std;

int t, res;

void ss()
{
    int x;
    cin >> x;

    res = 1;
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % (i * i) == 0)
            res = i;
    }

    cout << res << ' ' << x / (res * res) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI1.inp","r",stdin);
    freopen("BAI1.out","w",stdout);

    cin >> t;
    while (t--)
        ss();
    
    return 0;
}
