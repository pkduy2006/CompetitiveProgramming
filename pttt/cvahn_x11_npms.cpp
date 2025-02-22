#include <bits/stdc++.h>
using namespace std;

string s, res;

int convert(string x)
{
    return (x[0] - '0') * 8 + (x[1] - '0') * 4 + (x[2] - '0') * 2 + (x[3] - '0');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("npms.inp","r",stdin);
    freopen("npms.out","w",stdout);

    cin >> s;
    
    while (s.size() % 4 != 0)
        s = '0' + s;
    
    for(int i = 0; i < s.size(); i += 4)
    {
        string tmp = s.substr(i, 4);
        int a = convert(tmp);
        
        if(a <= 9)
            res += a + '0';
        else if(a == 10)
            res += 'A';
        else if(a == 11)
            res += 'B';
        else if(a == 12)
            res += 'C';
        else if(a == 13)
            res += 'D';
        else if(a == 14)
            res += 'E';
        else 
            res += 'F';
    }
    while (res[0] == '0' && res.size() > 1)
        res.erase(res.begin());

    cout << res;

    return 0;
}
