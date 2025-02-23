#include <bits/stdc++.h>
#define int long long
#define TASK "xepgach"

using namespace std;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(TASK".inp","r",stdin); freopen(TASK".out","w",stdout);

    int d = 0;
    int n; cin >> n;
    vector<int> h(n);
    int sum = 0;
    for(auto &x : h)
    {
        cin >> x;
        sum += x;
    }

    int avr = sum / n;
    for (auto x : h) {
        if (x < avr) d += avr - x ;
    }

    cout << d;
    return 0;
}
