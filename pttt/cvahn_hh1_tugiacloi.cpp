#include <iostream>
#include <cmath>
using namespace std;

double eps = 1e-5;

struct points {
    double x, y;
};
points A, B, C, D;

double Cal (points a, points b) {
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main () {
    freopen ("Tugiacloi.inp", "r", stdin);
    freopen ("Tugiacloi.out", "w", stdout);
    cin.tie (0) -> sync_with_stdio (0);
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    double AB = Cal (A, B);
    double BC = Cal (B, C);
    double CD = Cal (C, D);
    double DA = Cal (D, A);
    double AC = Cal (A, C);
    double BD = Cal (B, D);
    if (abs (A.x - B.x - D.x + C.x) < eps && abs (A.y - B.y - D.y + C.y) < eps) {
        if ((abs (AB - BC) < eps && abs (BC - CD) < eps && abs (CD - DA) < eps) && !(abs (AC - BD) < eps))
            cout << 2;
        else if (!(abs (AB - BC) < eps && abs (BC - CD) < eps && abs (CD - DA) < eps) && (abs (AC - BD) < eps))
            cout << 3;
        else if ((abs (AB - BC) < eps && abs (BC - CD) < eps && abs (CD - DA) < eps) && (abs (AC - BD) < eps))
            cout << 4;
        else cout << 1;
    }
    else cout << 5;   
    return 0;
}
