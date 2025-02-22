#include <bits/stdc++.h>
using namespace std;

string s, tmp;
vector<string> name;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TACHHDT.inp","r",stdin);
    freopen("TACHHDT.out","w",stdout);

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
    name.push_back(tmp);
    
    cout << name[0] << '\n';
    for(int i = 1; i < name.size() - 1; i++)   
        cout << name[i] << ' ';
    cout << '\n';
    cout << name.back();

    return 0;
}
