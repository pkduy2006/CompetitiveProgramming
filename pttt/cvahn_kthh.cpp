#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, check=0;
    cin >> n;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            check+=i;
            if(n/i!=n&&n/i!=i)
                check+=n/i;
        }
    }
    if(check==n&&n!=1)
        cout << 1;
    else
        cout << 0;
    return 0;
}
