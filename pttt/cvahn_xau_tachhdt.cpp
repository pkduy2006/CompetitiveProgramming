#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int pos1 = 0, pos2;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
            pos1 = i;
        else
            break;
    }
    for(int i = s.size(); i >= 0; i--)
    {
        if(s[i] != ' ')
            pos2 = i;
        else
            break;
    }
    for(int i = 0; i <= pos1; i++)
        cout << s[i];
    cout << '\n';
    for(int i = pos1 + 2; i <= pos2 - 2; i++)
        cout << s[i];
    cout << '\n';
    for(int i = pos2; i < s.size(); i++)
        cout << s[i];
    return 0;
}
