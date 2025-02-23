#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LED.inp","r",stdin);
    freopen("LED.out","w",stdout);

    cin >> n;
    if(n % 3 == 0)
        cout << (n / 3) * 7;
    else if(n % 3 == 1)
        cout << (n / 3 - 1) * 7 + 4;
    else
        cout << (n / 3) * 7 + 1;
    
    return 0;
}
