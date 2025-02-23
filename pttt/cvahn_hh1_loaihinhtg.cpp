#include<bits/stdc++.h>
using namespace std;
struct diem
{
    double x,y;
};
double tdt(diem a, diem b, diem c){
    return ((a.y - b.y)*c.x + (b.x - a.x)*c.y + a.x * b.y - a.y * b.x);
}
int main(){
    freopen("tugiac.inp","r",stdin);
    freopen("tugiac.out","w",stdout);
    double i1,i2,i3,i4,j,k,n;
    diem a,b,c,d,m;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if((a.x == b.x && a.y == b.y) or (b.y == c.y && c.x == b.x) or(c.x == d.x && c.y == d.y) or (d.x ==a.x && d.y == a.y) or (a.x == c.x && a.y == c.y) or (b.x == d.x && b.y == d.y)){
        cout << 0;
    }
    if(tdt(a,b,c) == 0 or tdt(a,b,d) == 0 or tdt(a,c,d) == 0 or tdt(a,b,d) == 0 or tdt(b,c,d) == 0 ){
        cout << 0;
    }
    else
    {
    if(tdt(a,c,b) * tdt(a,c,d) < 0 && tdt(b,d,a) * tdt(b,d,c) < 0){
        cout << 1 << endl;
        i1 = (a.x - b.x)*(a.y +b.y) / 2;
        i2 = (b.x - c.x)*(b.y +c.y) / 2;
        i3 = (c.x - d.x)*(c.y +d.y) / 2;
        i4 = (d.x - a.x)*(d.y +a.y) / 2;
        cout << setprecision(3) << fixed << abs(i1+i2+i3+i4);
    }
    else if(tdt(a,b,d) * tdt(a,b,c) < 0 && tdt(c,d,a) * tdt(c,d,b) < 0 or tdt(a,d,b) * tdt(a,d,c) < 0 && tdt(b,c,a) * tdt(b,c,d) < 0)
        cout << 3 << endl;
    else
        {
        cout << 2 << endl;
        i1 = (a.x - b.x)*(a.y +b.y) / 2;
        i2 = (b.x - c.x)*(b.y +c.y) / 2;
        i3 = (c.x - d.x)*(c.y +d.y) / 2;
        i4 = (d.x - a.x)*(d.y +a.y) / 2;
        cout << setprecision(3) << fixed << abs(i1+i2+i3+i4);
        }
    }
}
