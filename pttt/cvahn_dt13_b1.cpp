#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 25;
int n, a[N], dp[N], b[N]; // thời gian ngắn nhất để i người có được vé
vector<int> ans;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
        cin >> b[i];
}

void Solve()
{
    dp[1] = a[1];
    for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);

    cout << dp[n] << '\n';

    int idx = n;
    while(idx >= 1)
    {
        if(dp[idx] == dp[idx - 2] + b[idx - 1])
        {
            ans.push_back(idx);
            idx -= 2;
        }
        else
            idx--;
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans)
        cout << i << ' ';
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("ticket.inp","r",stdin);
    freopen("ticket.out","w",stdout);

    Read();

    Solve();

    return 0;
}
