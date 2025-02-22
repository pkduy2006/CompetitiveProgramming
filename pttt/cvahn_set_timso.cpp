#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> res, ans;
set<int> check;
int a, b, answer = 0;
int build(int t)
{
    check.insert(t);
    res.push_back(t);
    while(1)
    {
        string s = to_string(t);
        t = 0;
        for(int i = 0; i < s.size(); i++)
            t+= (s[i] - '0') * (s[i] - '0');
        res.push_back(t);
        if(check.count(t) == 0)
            check.insert(t);
        else
        {
            check.clear();
            return res.size();
        }
    }
    return 0;
}
main()
{
    //freopen("FindNumber.inp","r",stdin);
    //freopen("FindNumber.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for(int i = a; i <= b; i++)
    {
        if(build(i) > ans.size())
        {
            ans.clear();
            ans = res;
            answer = i;
        }
        res.clear();
    }
    cout << answer << ' ' << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
