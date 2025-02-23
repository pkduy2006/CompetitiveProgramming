#include <bits/stdc++.h>
using namespace std;

long double a, b, c, d;
int cnt_negative;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tbs.inp","r",stdin);
    freopen("tbs.out","w",stdout);

    cin >> a >> b >> c >> d;

    if(a == 0 || b == 0 || c == 0 || d == 0)
    {
        cout << 0;
        return 0;
    }

    if(a < 0)
        cnt_negative++;
    if(b < 0)
        cnt_negative++;
    if(c < 0)
        cnt_negative++;
    if(d < 0)
        cnt_negative++;

    if(cnt_negative % 2 == 1)
        cout << -1;
    else
        cout << 1;

    return 0;
}
