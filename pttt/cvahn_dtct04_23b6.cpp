#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 1;
int a[N], n;

int main () 
{
    freopen ("Noixich.inp", "r", stdin);
    freopen ("Noixich.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort (a + 1, a + n + 1);
    int timer = n - 1;
    for (int i = 1; a[i] < n - 1; i++) 
    {
        timer--;
        n -= (1 + a[i]);
    }
    
    cout << timer;
    
    return 0;
}
