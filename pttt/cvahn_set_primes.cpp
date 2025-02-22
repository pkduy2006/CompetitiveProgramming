#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
set<int> a;
bool check(int k)
{
    if(k < 2)
        return false;
    for(int i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
            return false;
    }
    return true;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s = to_string(n);
    for(int j = 1; j <= s.size(); j++)
    {
        for(int i = 0; i < s.size() - j + 1; i++)
        {
            string t = s.substr(i, j);
            int ans = 0, digit = 1;
            for(int b = t.size() - 1; b >= 0; b--)
            {
                ans += (t[b] - '0') * digit;
                digit *= 10;
            }
            if(check(ans))
                a.insert(ans);
        }
    }
    if(a.size() == 0)
        cout << "NO PRIMES";
    else
        cout << a.size();
    return 0;
}
