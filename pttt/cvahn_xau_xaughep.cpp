#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, res = "";
    getline(cin, s);
    for(int i = 1; i <= s.size() / 2; i++)
    {
        string ans = "";
        for(int j = 0; j < i; j++)
            ans+=s[j];
        if(s.size() % ans.size() == 0)
        {
            bool check = true;
            for(int t = 0; t < s.size(); t+=ans.size())
            {
                for(int k = t; k < t + ans.size(); k++)
                {
                    if(s[k] != ans[k - t])
                        check = false;
                }
            }
            if(check == true)
            {
                if(ans.size() > res.size())
                    res = ans;
            }
        }
    }
    if(res.size() == 0)
        cout << 0;
    else
        cout << res;
    return 0;
}
