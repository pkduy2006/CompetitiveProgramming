#include <bits/stdc++.h>
using namespace std;
int main()
{
    double ps=1, m, x, emux=1, i=0;
    cin >> x >> m;
    while(ps>=m)
    {
        i++;
        ps=ps*x/i;
        emux+=ps;
    }
    cout << fixed << setprecision(5) << emux;
    return 0;
}
