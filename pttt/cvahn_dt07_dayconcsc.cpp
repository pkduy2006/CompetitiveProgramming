#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, a[N], res_cnt, res_dif;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dccsc.inp","r",stdin);
    freopen("dccsc.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int dif = a[j] - a[i], cnt = 2, last = a[j];

            for(int k = j + 1; k <= n; k++)
            {
                if(a[k] - last == dif)
                {
                    cnt++;
                    last = a[k];
                }
            }

            if(res_cnt < cnt)
            {
                res_cnt = cnt;
                res_dif = dif;
            }
        }
    }

    if(res_cnt == 0)
        cout << 0;
    else
        cout << res_cnt << ' ' << res_dif;

    return 0;
}
