#include <bits/stdc++.h>
using namespace std;

string s, tmp;
vector<string> name;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CHUANHOA.inp","r",stdin);
    freopen("CHUANHOA.out","w",stdout);

    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
            tmp += s[i];
        else
        {
            if(tmp != "")
                name.push_back(tmp);
            tmp = "";
        }
    }
    if(tmp != "")
        name.push_back(tmp);

    for(int i = 0; i < name.size(); i++)
    {
        string x = name[i];

        if('a' <= x[0] && x[0] <= 'z')  
        {
            int third_guy = x[0];
            third_guy -= 32;
            x[0] = (char) third_guy;
        }

        for(int i = 1; i < x.size(); i++)
        {
            if('A' <= x[i] && x[i] <= 'Z')
            {
                int third_guy = x[i];
                third_guy += 32;
                x[i] = (char) third_guy;
            }
        }
        name[i] = x;
    }

    for(string x : name)
        cout << x << ' ';

    return 0;
}
