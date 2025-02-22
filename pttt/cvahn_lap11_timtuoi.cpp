#include <bits/stdc++.h>
using namespace std;

int t, x, y;

void Solve()
{
    cin >> x >> y;
    if(x - 2 * y < 0)
        cout << -1 << '\n';
    else
        cout << x - 2 * y << '\n';

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
