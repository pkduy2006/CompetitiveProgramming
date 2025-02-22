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
        string ans = s.substr(0, i);
        if(s.size() % ans.size() == 0)
        {
            bool check = true;
            for(int t = 0; t < s.size(); t+=ans.size())
            {
                string review = s.substr(t, ans.size());
                if(review != ans)
                    check = false;
            }
            if(check == true)
            {
                cout << ans;
                return 0;
            }
        }
    }
    cout << s;
    return 0;
}
