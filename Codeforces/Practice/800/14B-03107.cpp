//Codeforces Round 990 (Div. 2) A. Alyona and a Square Jigsaw Puzzle
//https://codeforces.com/problemset/problem/2047/A

#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e2 + 7;
int ntests, a[N], n, sum, res;
 
void solve()
{
    sum = 0;
    res = 0;
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        int b = sqrt(sum);
        if(sqrt(sum) == b && b % 2 == 1)
        {
            //cout << sum << ' ';
            res++;
        }
    }
 
    cout << res << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}