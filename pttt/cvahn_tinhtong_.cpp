#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, res=0;
    cin >> n;
    while(n>0)
    {
        res+=(n%10);
        n/=10;
    }
    cout << res;
    return 0;
}
