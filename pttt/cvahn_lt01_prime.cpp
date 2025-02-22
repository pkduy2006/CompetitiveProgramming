#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> a;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s = to_string(n);
    for(int j = 1; j <= s.size(); j++)
    {
        for(int i = 0; i < s.size() - j + 1; i++)
        {
            string t = s.substr(i, j);
            int ans = 0, digit = 1;
            for(int i = t.size() - 1; i >= 0; i--)
            {
                ans += (t[i] - '0') * digit;
                digit *= 10;
            }
            bool check = true;
            if(ans < 2)
                check = false;
            for(int i = 2; i <= sqrt(ans); i++)
            {
                if(ans % i == 0)
                {
                    check = false;
                    break;
                }
            }
            if(check == true)
                a.insert(ans);
        }
    }
    if(a.size() != 0)
        cout << a.size();
    else
        cout << "No primes";
    return 0;
}
