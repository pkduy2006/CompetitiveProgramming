#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double eps = 1e-5;

struct points {
    double x, y;
};
points A, B, C;

double Cal (int xa, int ya, int xb, int yb) {
    return sqrt ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

int main () {
    freopen ("Badiem.inp", "r", stdin);
    freopen ("Badiem.out", "w", stdout);
    cin.tie (0) -> sync_with_stdio (0);
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    double AB = Cal (A.x, A.y, B.x, B.y);
    double BC = Cal (B.x, B.y, C.x, C.y);
    double CA = Cal (A.x, A.y, C.x, C.y);
    if (abs (AB - BC - CA) < eps) {
        cout << 1;
        return 0;
    }
    else if (abs (CA - BC - AB) < eps || abs (BC - CA - AB) < eps) {
        cout << 2;
        return 0;
    }
    else {
        double p = (AB + BC + CA) / 2;
        cout << setprecision (3) << fixed << sqrt (p * (p - BC) * (p - CA) * (p - AB)) << '\n';
        cout << setprecision (3) << fixed << AB + BC + CA;
        return 0;
    }
}
