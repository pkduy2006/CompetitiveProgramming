#include <bits/stdc++.h>
using namespace std;

int n, x;
map<int, int> value;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("THONGKE.inp","r",stdin);
    freopen("THONGKE.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        value[x]++;
    }

    for(auto [x, cnt] : value)
        cout << x << ':' << cnt << '\n';
    
    return 0;
}
