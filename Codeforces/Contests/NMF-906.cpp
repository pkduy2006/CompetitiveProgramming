// Hello 2025 C. Trip to the Olympiad
// https://codeforces.com/contest/2057/problem/C 

#include <bits/stdc++.h>
using namespace std;

int ntests, l, r, res, cnt, maxor;

void solve()
{
    res = 0, cnt = 0, maxor = 0;
    
    cin >> l >> r;

    for(int i = 30; i >= 0; i--)
    {
        if(l & (1 << i))
            cnt += 1 << i;
        else
        {
            int ans = cnt + (1 << i);
            for(int j = i - 1; j >= 0; j--)
            {
                if(!(l & (1 << j)) && !(r & (1 << j)) && ans + (1 << j) <= r)
                    ans += (1 << j);
            }
            if(maxor < (l ^ ans) + (ans ^ r) + (l ^ r) && ans <= r)
            {
                res = ans;
                maxor = (l ^ ans) + (ans ^ r) + (l ^ r);
            }
        }
    }

    cout << l << ' ' << res << ' ' << r << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();

    return 0;
}