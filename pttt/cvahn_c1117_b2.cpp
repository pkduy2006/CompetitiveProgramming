#include <bits/stdc++.h>
using namespace std;

int s, k, m, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);

    cin >> s >> k >> m;
    if(m > k)
    {
        cout << 0;
        
        return 0;
    }
    while (true)
    {
        int cnt = s / k;
        if(cnt == 0)
            break;
        res += cnt * (k / m);
        s -= cnt * k;
        s += cnt * (k - (k / m) * m);
        //cout << s << '\n';
    }
    
    cout << res;

    return 0;
}
