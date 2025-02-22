#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
queue<int> q;

void Read()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
}

void Solve()
{
    k %= n;

    while(k--)
    {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
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
