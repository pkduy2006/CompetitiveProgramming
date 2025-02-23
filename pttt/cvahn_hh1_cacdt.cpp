#include <bits/stdc++.h>
using namespace std;
signed main () {
    freopen("Cacdt.inp", "r", stdin);
    freopen("Cacdt.out", "w", stdout);
    int x1[10001], x2[10001], y1[10001], y2[10001];
    int n, dem = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    for(int i = 1; i <= n - 1; i++)
    {
        double a = y1[i] - y2[i];
        double b = x2[i] - x1[i];
        for(int j = i + 1; j <= n; j++)
        {
            double a1 = y1[j] - y2[j];
            double b1 = x2[j] - x1[j];
            double D = a * b1 - a1 * b;
            if(D != 0)
                dem++;
        }
    }
    cout << dem;}
