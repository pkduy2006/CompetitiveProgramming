#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> res;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, s1;
    getline(cin, s1);
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        bool check = true;
        for(int j = i; j < i + s1.size(); j++)
        {
            if(s[j] != s1[j - i])
                check = false;
        }
        if(check == true)
            res.push_back(i + 1);
    }
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}
