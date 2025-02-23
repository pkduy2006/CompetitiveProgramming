#include <bits/stdc++.h>
#define int long long
using namespace std;
double x3,x4,y3,y4,r3,r4;
signed main()
{
	freopen("Haidtron.inp","r",stdin);
    freopen("Haidtron.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> x3 >> y3 >> r3 >> x4 >> y4 >> r4;
	double OO = sqrt( (x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4) );
	if (OO == abs(r3 - r4)) cout << 1;
	else if (OO > abs(r3 - r4) && OO < abs(r3 + r4)) cout << 2;
	else if (OO < abs(r3 - r4)) cout << 3;
	else if (OO == r3 + r4) cout << 4;
	else if (OO > r3 + r4) cout << 5;
	return 0;
}
