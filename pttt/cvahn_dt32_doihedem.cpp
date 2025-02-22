#include <bits/stdc++.h>
using namespace std;

string s, res = "";

int power(int x, int y)
{
    if(y == 0)
        return 1;

    int tmp = power(x, y / 2);

    if(y % 2 == 0)
        return tmp * tmp;
    else
        return tmp * tmp * x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> s;
    
    while (s.size() % 4 != 0)
        s = '0' + s;
    
    for(int i = s.size() - 1; i >= 0; i -= 4)
    {
        string tmp = s.substr(i - 3, 4);
        reverse(tmp.begin(), tmp.end());

        int cnt = 0;
        for(int i = 0; i < 4; i++)
        {   
            if(tmp[i] == '1')
                cnt += power(2, i);
        }

        if(cnt < 10)
            res += cnt + '0';
        else if(cnt == 10)
            res += 'A';
        else if(cnt == 11)
            res += 'B';
        else if(cnt == 12)
            res += 'C';
        else if(cnt == 13)
            res += 'D';
        else if(cnt == 14)
            res += 'E';
        else
            res += 'F';
    }

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
