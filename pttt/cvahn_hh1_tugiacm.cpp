#include<bits/stdc++.h>

using namespace std;
const double eps = 1e-5;
struct diem
{
	int x, y;
};
diem a, b, c, d, m;
double a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4;
void dt(diem a, diem b, double &a1, double &b1, double &c1)
{
	a1 = a.y - b.y;
	b1 = b.x - a.x;
	c1 = a.x * b.y - b.x * a.y;
}
double tdt(diem a, double a1, double b1, double c1)
{
	return(a.x * a1 + a.y * b1 + c1);
}
int check(diem a, double a1, double b1, double c1)
{
	double s;
	s = a.x * a1 + a.y * b1 + c1;
	if(s < 0) return -1;
	return 1;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("tugiacm.inp", "r", stdin);
	freopen("tugiacm.out", "w", stdout);
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	cin >> m.x >> m.y;
	dt(a, b, a1, b1, c1);
	dt(b, c, a2, b2, c2);
	dt(c, d, a3, b3, c3);
	dt(d, a, a4, b4, c4);
	
	if((m.x == a.x && m.y == a.y) || (m.x == b.x && m.y == b.y) ||
	   (m.x == c.x && m.y == c.y) || (m.x == d.x && m.y == d.y)) cout << 4;
	else if(abs(tdt(m, a1, b1, c1)) < eps || abs(tdt(m, a2, b2, c2)) < eps ||
	        abs(tdt(m, a3, b3, c3)) < eps || abs(tdt(m, a4, b4, c4)) < eps) cout <<3;
	else if((check(m, a1, b1, c1) == check(c, a1, b1, c1) == check(d, a1, b1, c1)) &&
			(check(m, a2, b2, c2) == check(a, a2, b2, c2) == check(d, a2, b2, c2)) &&
			(check(m, a3, b3, c3) == check(a, a3, b3, c3) == check(b, a3, b3, c3)) &&
			(check(m, a4, b4, c4) == check(c, a4, b4, c4) == check(b, a4, b4, c4))) cout << 1;
	else cout << 2;
}
