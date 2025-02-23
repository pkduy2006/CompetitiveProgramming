#include <iostream>
#include <cmath>
using namespace std;

double eps = 1e-5;

struct points {
    double x, y;
};
points A, B, C;

double Cal (int xa, int ya, int xb, int yb) {
    return sqrt ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

int main () {
    freopen ("Tamgiacv.inp", "r", stdin);
    freopen ("Tamgiacv.out", "w", stdout);
    cin.tie (0) -> sync_with_stdio (0);
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    double AB = Cal (A.x, A.y, B.x, B.y);
    double BC = Cal (B.x, B.y, C.x, C.y);
    double CA = Cal (A.x, A.y, C.x, C.y);
    if (abs (AB * AB + BC * BC - CA * CA) < eps)
        cout << A.x - B.x + C.x << ' ' << A.y - B.y + C.y;
    else cout << 0;
    return 0;
}
