#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int n, res = INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i * 5 <= n; i++)
    {
        int tmp = n - i * 5;
        if(tmp % 3 == 0)
            res = min(res, i + tmp / 3);
    }
    
    if(res == INF)
        cout << -1;
    else
        cout << res;
        
    return 0;
}
