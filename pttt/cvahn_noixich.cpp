#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e4 + 1;
int a[N];

int main () {
    freopen ("Noixich.inp", "r", stdin);
    freopen ("Noixich.out", "w", stdout);
    int n;
    cin >> n;
    int i;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    int time = n - 1;
    for (i = 1; a[i] < n - 1; i++) {
        time--;
        n -= (1 + a[i]);
    }
    cout << time;
}
