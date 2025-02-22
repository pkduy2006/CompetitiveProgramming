#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    queue<int> a;
    vector<int> mark(1e3 + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a.push(i);
    }
    while(m > 0)
    {
        mark[a.front()]++;
        if(b[a.front()] > k)
        {
            int x = a.front();
            a.push(x);
        }
        a.pop();
        if(a.empty())
            break;
        m--;
    }
    for(int i = 1; i <= n; i++)
        cout << mark[i] << '\n';
    return 0;
}
