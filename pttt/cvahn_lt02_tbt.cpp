#include <bits/stdc++.h>
#define int long long

using namespace std;

string s;
bool low = 1,high;
double ans = 0, num = 0, tmp;

main()
{
    cin >> s;
    if (s[0] == '-')
    {
        low = 0;
        s.erase(s.begin());
    }
    s += '+';
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
        else
        {
            if (s[i] == '*')
            {
                tmp = 0;
                high = 1;
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (isdigit(s[j])) tmp = tmp * 10 + (s[j] - '0');
                    else
                    {
                        high = 0;
                        i = j - 1;
                        break;
                    }
                }
                num *= tmp;
                if (high) i = s.size() - 2;
            }
            else if (s[i] == '/')
            {
                tmp = 0;
                high = 1;
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (isdigit(s[j])) tmp = tmp * 10 + (s[j] - '0');
                    else
                    {
                        high = 0;
                        i = j - 1;
                        break;
                    }
                }
                num /= tmp;
                if (high) i = s.size() - 2;
            }
            else
            {
                if (low) ans += num;
                else ans -= num;
                num = 0;
                if (s[i] == '+') low = 1;
                else low = 0;
            }
        }
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}
