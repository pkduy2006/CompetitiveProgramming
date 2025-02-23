#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 16;
int t[N], r[N], n, f[N][2], res;
vector<int> answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt","r",stdin);
    freopen("ticket.inp","r",stdin);
    freopen("ticket.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    for(int i = 1; i < n; i++)
        cin >> r[i];

    memset(f, 0x3f3f3f, sizeof(f));
    f[1][0] = t[1];
    f[2][1] = r[1];
    f[2][0] = t[1] + t[2];
    for(int i = 3; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0], f[i - 1][1]) + t[i];
        f[i][1] = min(f[i - 2][0], f[i - 2][1]) + r[i - 1];
    }

    res = min(f[n][0], f[n][1]);
    cout << res << '\n';
    for(int i = n; i >= 1; i--)
    {
        if(res == f[i][0])
            res -= t[i];
        else
        {
            answer.push_back(i);
            res -= r[i - 1];
            i--;
        }
    }
    for(int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i] << ' ';
    
    return 0;
}
