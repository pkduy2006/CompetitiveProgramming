#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("CCHUNHAT.INP", "r", stdin);
    freopen("CCHUNHAT.OUT", "w", stdout);
    int n, x[10001], y[10001], dem = 0, check = 0;
    double eps = 1e-5;
    double vec1, vec2;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for(int i = 1; i <= n - 3; i++)
        for (int j = i + 1; j <= n - 2; j++)
            for (int k = j + 1; k <= n - 1; k++)
    {
        double vec1_12 = x[j] - x[i];
        double vec2_12 = y[j] - y[i];
        double vec1_13 = x[k] - x[i];
        double vec2_13 = y[k] - y[i];
        double vec1_23 = x[k] - x[j];
        double vec2_23 = y[k] - y[j];
        double vec1_21 = - vec1_12;
        double vec2_21 = - vec2_12;
        double vec1_31 = - vec1_13;
        double vec2_31 = - vec2_13;
        double vec1_32 = - vec1_23;
        double vec2_32 = - vec2_23;

        if(abs(vec1_12 * vec1_13 + vec2_12 * vec2_13) < eps)
        {
            vec1 = vec1_12 + x[k];
            vec2 = vec2_12 + y[k];
            check = 1;
        }
        else if(abs(vec1_21 * vec1_23 + vec2_21 * vec2_23) < eps)
        {
            vec1 = vec1_21 + x[k];
            vec2 = vec2_21 + y[k];
            check = 1;
        }
        else if(abs(vec1_32 * vec1_31 + vec2_32 * vec2_31) < eps)
        {
            vec1 = vec1_32 + x[i];
            vec2 = vec2_32 + y[i];
            check = 1;

        }
        for(int l = k + 1; l <= n; l++)
        {
            if(check == 1 && x[l] == vec1 && y[l] == vec2)
                dem++;

        }
        check = 0;
    }
    cout << dem;

    return 0;
}
