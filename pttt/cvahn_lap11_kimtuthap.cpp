#include <bits/stdc++.h>
using namespace std;

int n, res, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(cnt + i * (i + 1) / 2 <= n)
        {   
            res++;
            cnt += i * (i + 1) / 2;
        }
        else
            break;
    }

    cout << res;

    return 0;
}
