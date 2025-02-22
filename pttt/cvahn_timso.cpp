#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, r;
vector<int> res, ans;
set<int> a;

int check(int n)
{
    ans.push_back(n);
    a.insert(n);

    while(true)
    {
        string s = to_string(n);
        int cnt = 0;

        for(int i = 0; i < s.size(); i++)
            cnt += (s[i] - '0') * (s[i] - '0');

        if(a.count(cnt) == 0)
        {
            ans.push_back(cnt);
            a.insert(cnt);
        }
        else
        {
            ans.push_back(cnt);
            return ans.size();
        }

        n = cnt;
    }
}

void Read()
{
    cin >> l >> r;
}

void Solve()
{
    int last = -1;
    for(int i = l; i <= r; i++)
    {
        ans.clear();
        a.clear();

        if(check(i) > res.size())
        {
            res.clear();

            last = i;
            for(int i = 0; i < ans.size(); i++)
                res.push_back(ans[i]);
        }
    }

    cout << last << ' ' << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
}

main()
{
    freopen("timso.inp","r",stdin);
    freopen("timso.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
