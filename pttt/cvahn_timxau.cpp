#include <bits/stdc++.h>
#define int long long
using namespace std;

int k;
string s;
vector<string> t;

void Read()
{
    cin >> k >> s;
}

void Solve()
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        char m = s[0];
        s.erase(s.begin());
        s += m;
        t.push_back(s);
    }

    sort(t.begin(), t.end());
    if(k > n - 1 || k == 0)
        cout << -1;
    else
        cout << t[k - 1];
}

main()
{
    freopen("timxau.inp","r",stdin);
    freopen("timxau.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
