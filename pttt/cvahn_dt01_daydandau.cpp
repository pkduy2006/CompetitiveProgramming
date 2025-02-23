#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int a[N], n, cnt, res, c;
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("daycondd.inp","r",stdin);
    freopen("daycondd.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        cnt = 1;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[j] * a[j - 1] < 0)
                cnt++;
            else
                break;
        }
        if(res < cnt)
        {
            res = cnt;
            c = 1;
            b.clear();
            for(int j = i; j <= i + res - 1; j++)
                b.push_back(a[j]);
        }
        else if(res == cnt)
            c++;
    }

    cout << c << ' ' << res << '\n';
    for(int i = 0; i < b.size(); i++)   
        cout << b[i] << ' ';

    return 0;
}
