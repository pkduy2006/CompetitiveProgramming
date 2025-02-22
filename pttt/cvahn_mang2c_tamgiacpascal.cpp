#include <bits/stdc++.h>
#define int long long
using namespace std;
int pascal[130][131];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pascal[0][1] = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        for(int j = 1; j <= i ; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            cout << pascal[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
