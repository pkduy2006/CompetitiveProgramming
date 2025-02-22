#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("RepairName.inp","r",stdin);
    //freopen("RepairName.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    s = ' ' + s;
    for(int i = 1; i < s.size(); i++)
    {
        while(s[i] == ' ' && s[i + 1] == ' ')
            s.erase(s.begin() + i + 1);
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
            s[i + 1] -= 32;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ' && 'A' <= s[i + 1] && s[i + 1] <= 'Z')
            s[i + 1] += 32;
    }
    s.erase(s.begin());
    cout << s;
    return 0;
}
