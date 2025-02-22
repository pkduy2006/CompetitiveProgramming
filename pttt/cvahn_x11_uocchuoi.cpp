#include <bits/stdc++.h>
using namespace std;

string s, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("uochuoi.inp","r",stdin);
    freopen("uochuoi.out","w",stdout);

    cin >> s;
    for(int i = 1; i <= s.size(); i++)
    {
        if(s.size() % i == 0)
        {
            string checker = s.substr(0, i);
            bool check = true;
            for(int j = i; j < s.size(); j += i)
            {
                string tmp = s.substr(j, i);
                if(tmp != checker)
                {   
                    check = false;
                    break;
                }
            }

            if(check)
            {   
                cout << checker;
                return 0;
            }    
        }
    }
    return 0;
}
