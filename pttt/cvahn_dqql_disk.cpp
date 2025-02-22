#include <bits/stdc++.h>
#define int long long
using namespace std;

int price[115], numberDisk[116], a[117][118], total = 0, minMoney = 1e9 + 7, ans, m, n, mark[120];
vector<int> res, last;

void AddDisk(int t)
{
    for(int i = 1; i <= numberDisk[t]; i++)
        mark[a[t][i]]++;
}

void RemoveDisk(int t)
{
    for(int i = 1; i <= numberDisk[t]; i++)
        mark[a[t][i]]--;
}

bool checkDisk()
{
    for(int i = 1; i <= m; i++)
    {
        if(mark[i] == 0)
            return false;
    }
    return true;
}

void Solve(int t)
{
    for(int i = last[t - 1] + 1; i <= n; i++)
    {
        last[t] = i;
        total += price[i];
        AddDisk(i);

        if(checkDisk() && total < minMoney)
        {
            minMoney = total;
            res = last;
            ans = t;
        }
        if(t < n && total < minMoney)
            Solve(t + 1);

        total -= price[i];
        RemoveDisk(i);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    last.resize(121);
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i] >> numberDisk[i];
        for(int j = 1; j <= numberDisk[i]; j++)
            cin >> a[i][j];
    }

    Solve(1);

    cout << minMoney << '\n';
    for(int i = 1; i <= ans; i++)
        cout << res[i] << ' ';
    return 0;
}
