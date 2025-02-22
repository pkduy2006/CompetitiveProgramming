#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, res=0, cnt=2;
    cin >> n;
    while(n>1)
    {
        if(n%cnt==0)
        {
            cout << cnt << ' ';
            res+=cnt;
            n/=cnt;
            while(n%cnt==0)
            {
                cout << cnt << ' ';
                res+=cnt;
                n/=cnt;
            }
        }
        cnt++;
    }
    cout << endl;
    cout << res;
    return 0;
}
