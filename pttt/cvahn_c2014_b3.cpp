#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        s[i] -= 65;
        s[i] += 5;
        s[i] %= 26;
        s[i] += 65;

        cout << s[i];
    }

    return 0;
}
