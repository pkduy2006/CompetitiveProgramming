#include<bits/stdc++.h>
using namespace std;
int a[4], b[4], dt[4], sum, maxlen;
main()
{

    freopen("ghephinh.inp","r",stdin);
    freopen("ghephinh.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 1; i <= 3; i++)
    {
        cin >> a[i] >> b[i];
        dt[i] = a[i] * b[i];
        sum += dt[i];
    }
        maxlen = max ({a[1], a[2], a[3], b[1], b[2], b[3]});
        int dtm = maxlen * maxlen;
        if(sum == dtm)
        {
            cout << maxlen;
            return 0;
        }
        else cout << 0;

}
