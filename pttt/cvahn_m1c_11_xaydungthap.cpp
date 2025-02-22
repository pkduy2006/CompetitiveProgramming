#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, res;
map<int, int> tower; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("XAYDUNGTHAP.inp","r",stdin);
    freopen("XAYDUNGTHAP.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        tower[x]++;
        res = max(res, tower[x]);
    }

    cout << res << ' ' << tower.size();

    return 0;
}
