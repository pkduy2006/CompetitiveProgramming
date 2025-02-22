#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int t, h[N], n;

void Solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];

    int res = 1, max_height = h[1];
    for(int i = 2; i <= n; i++)
    {
        if(h[i] >= max_height)
        {   
            res++;
            max_height = max(max_height, h[i]);
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NNNCONANG.inp","r",stdin);
    freopen("NNNCONANG.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
}
