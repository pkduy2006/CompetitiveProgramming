#include <bits/stdc++.h>
using namespace std;
signed main () {
    freopen("Cacdtvg.inp", "r", stdin);
    freopen("Cacdtvg.out", "w", stdout);
    int n;
    cin >> n;
    double eps = 1e-5;
    int dem = 0;
    int x1[10001], x2[10001], y1[10001], y2[10001];
    for(int i = 1; i <= n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    for(int i = 1; i <= n - 1; i++)
    {
        double vec_a = x1[i] - x2[i];
        double vec_b = y1[i] - y2[i];
        for(int j = i + 1; j <= n; j++)
        {
            double vec_a1 = x1[j] - x2[j];
            double vec_b1 = y1[j] - y2[j];
            if(abs(vec_a * vec_a1 + vec_b * vec_b1 - 0) < eps)
                dem++;

        }
    }
    cout << dem;
    return 0;
}
