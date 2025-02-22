#include <bits/stdc++.h>
using namespace std;

string s, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MSNP.inp","r",stdin);
    freopen("MSNP.out","w",stdout);
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
            res += "0000";
        else if(s[i] == '1')
            res += "0001";
        else if(s[i] == '2')
            res += "0010";
        else if(s[i] == '3')
            res += "0011";
        else if(s[i] == '4')
            res += "0100";
        else if(s[i] == '5')
            res += "0101";
        else if(s[i] == '6')
            res += "0110";
        else if(s[i] == '7')
            res += "0111";
        else if(s[i] == '8')
            res += "1000";
        else if(s[i] == '9')
            res += "1001";
        else if(s[i] == 'A')
            res += "1010";
        else if(s[i] == 'B')
            res += "1011";
        else if(s[i] == 'C')
            res += "1100";
        else if(s[i] == 'D')
            res += "1101";
        else if(s[i] == 'E')
            res += "1110";
        else 
            res += "1111";
    }
    while (res.front() == '0' && res.size() > 1)
        res.erase(res.begin());
    
    cout << res;

    return 0;
}
