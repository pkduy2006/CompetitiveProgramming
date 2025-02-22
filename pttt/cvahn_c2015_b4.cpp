#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> ans;
int res = 0;
bool check = false;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            res = res * 10 + (s[i] - 48);
            check = true;
        }
        else
        {
            if(check == true)
            {
                ans.insert(res);
                res = 0;
                check = false;
            }
        }
    }
    if(check == true)
        ans.insert(res);
    if(ans.size() == 0)
    {
        cout << 0;
        return 0;
    }

    cout << ans.size() << '\n';
    for(auto i = ans.begin(); i != ans.end(); i++)
        cout << (*i) << '\n';
    return 0;
}
