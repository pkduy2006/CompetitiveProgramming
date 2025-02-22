#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while(ntest--)
    {
        string s;
        cin >> s;
        vector< pair < int, int> > mark;
        for(int i = 0; i < s.size(); i++)
        {
            bool check = true;
            for(int j = 0; j < mark.size(); j++)
            {
                if(s[i] == s[mark[j].first])
                {
                    mark[j].second++;
                    check = false;
                    break;
                }
            }
            if(check == true)
                mark.push_back(make_pair(i, 1));
        }
        bool check = true;
        for(int i = 0; i < mark.size(); i++)
        {
            if(mark[i].second == 1)
            {
                cout << mark[i].first + 1 << '\n';
                check = false;
                break;
            }
        }
        if(check == true)
            cout << -1 << '\n';
    }
    return 0;
}
