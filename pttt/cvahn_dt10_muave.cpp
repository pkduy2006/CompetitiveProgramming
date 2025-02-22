#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int n, k, m, mark[N];
queue<pair<int, int>> q;

void Read()
{
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        q.push({x, i});
    }
}

void Solve()
{
    while(m--)
    {
        int tmp = q.front().first, idx = q.front().second;
        mark[idx]++;
        q.pop();

        if(tmp > k)
            q.push({tmp, idx});
    }

    for(int i = 1; i <= n; i++)
        cout << mark[i] << ' ';
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
