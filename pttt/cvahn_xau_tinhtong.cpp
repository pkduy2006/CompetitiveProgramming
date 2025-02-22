#include <bits/stdc++.h>
#define int long long
using namespace std;
int convert(string s)
{
    int ans = 0, cnt = 1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        ans += (s[i] - '0') * cnt;
        cnt *= 10;
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    int i = 0, res = 0;
    while(i < s.size())
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            string ans = "";
            int j;
            for(j = i; j <= s.size(); j++)
            {
                if('0' <= s[j] && s[j] <= '9')
                    ans+=s[j];
                else
                    break;
            }
            int num = convert(ans);
            res += num;
            i = j + 1;
        }
        else
            i++;
    }
    cout << res;
    return 0;
}
