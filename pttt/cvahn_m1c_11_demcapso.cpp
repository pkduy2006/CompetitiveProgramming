#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int t, n, a[N];

void Solve()
{
    int res = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = i * x;
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
                res++;
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DEMCAPSO.inp","r",stdin);
    freopen("DEMCAPSO.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
