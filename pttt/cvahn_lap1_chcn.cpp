#include <bits/stdc++.h>
using namespace std;

int t, n;

void Solve()
{
    cin >> n;
    if(n % 2 == 1 || n < 4)
    {
        cout << -1 << '\n';
        return;
    }

    for(int i = 1; i <= n / 4; i++)
        cout << i * (n / 2 - i) << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
