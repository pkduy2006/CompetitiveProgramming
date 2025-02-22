#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int total0 = 0, total1 = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                total0++;
            else
                total1++;
        }
        if(total1 == total0)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}
