#include <bits/stdc++.h>
using namespace std;

long long n;
string res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DOITLP.inp","r",stdin);
    freopen("DOITLP.out","w",stdout);

    cin >> n;
    while (n > 0)
    {
        int tmp = n % 16;
        if(0 <= tmp && tmp <= 9)
            res += ('0' + tmp);
        else if(tmp == 10)
            res += 'A';
        else if(tmp == 11)
            res += 'B';
        else if(tmp == 12)
            res += 'C';
        else if(tmp == 13)
            res += 'D';
        else if(tmp == 14)
            res += 'E';
        else
            res += 'F';
        
        n /= 16;
    }
    reverse(res.begin(), res.end());
    
    cout << res;

    return 0;
}
