#include <bits/stdc++.h>
using namespace std;
int a[1000116];
int main()
{
    int n;
    long long sum=0;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        sum+=a[i];
    cout << sum;
    return 0;
}
