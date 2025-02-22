#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int t, n, a[N];
char k;

void Solve()
{
    int res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        string tmp = to_string(a[i]);
        for(int j = 0; j < tmp.size(); j++)
        {
            if(tmp[j] == k)
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
    freopen("DEMCHUSO.inp","r",stdin);
    freopen("DEMCHUSO.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
