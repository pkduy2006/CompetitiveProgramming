#include <bits/stdc++.h>
using namespace std;

int t, x, y;
struct buffalo
{
    int stand, lie, old;
};
vector<buffalo> res;

void Solve()
{
    res.clear();
    cin >> x >> y;

    for(int i = 0; i <= x; i++)
    {
        for(int j = x - i; j >= 0; j--)
        {
            int tmp = x - i - j;
            if(tmp % 3 != 0)
                continue;
            
            if(i * 5 + j * 3 + tmp / 3 == y)
                res.push_back({i, j, tmp});
        }
    }

    cout << res.size() << '\n';
    for(auto i : res)
        cout << i.stand << ' ' << i.lie << ' ' << i.old << '\n';
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
