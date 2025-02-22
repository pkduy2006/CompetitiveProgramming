#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,u,v,t[10001],dem;
bool kt;
vector<int> a[10001];
void hop(int x, int y)
{
    while (t[x] != x) x = t[x];
    while (t[y] != y) y = t[y];
    if (t[x] > t[y]) t[x] = t[y];
    else t[y] = t[x];
}
bool ktlt(int x, int y)
{
    while (t[x] != x) x = t[x];
    while (t[y] != y) y = t[y];
    if (x != y) return 1;
    else return 0;
}
void themcanh(int i, int j)
{
    a[i].push_back(j);
    a[j].push_back(i);
    hop(i,j);
    kt = true;
    dem++;
}
void noilele()
{
    do
    {
        kt = false;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (ktlt(i,j) && a[i].size() % 2 == 1 && a[j].size() % 2 == 1)
                {
                    themcanh(i,j);
                    kt = true;
                }
    } while(kt);
}
void noilechan()
{
    do
    {
        kt = false;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (ktlt(i,j) && ((a[i].size() % 2 == 1 && a[j].size() % 2 == 0) || 
                                  (a[i].size() % 2 == 0 && a[j].size() % 2 == 1)))
                {
                    themcanh(i,j);
                    kt = true;
                }
    } while (kt);
}
void noilienthong()
{
    do
    {
        kt = false;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (ktlt(i,j))
                {
                    themcanh(i,j);
                    kt = true;
                }
    } while (kt);
}
void themduong()
{
    noilele();
    noilechan();
    noilienthong();
    do
    {
        kt = false;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (a[i].size() % 2 == 1 && a[j].size() % 2 == 1)
                    themcanh(i,j);
    } while (kt);
}
int main()
{
    freopen("TDuongdi.INP","r",stdin);
    freopen("TDuongdi.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) t[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        hop(x,y);
    }
    dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t[i] == i) dem++;
        if (a[i].size() == 0 || a[i].size() % 2 != 0) dem++;
    }
    if (dem > 1)
    {
        dem = 0;
        themduong();
        cout << dem;
    }
    else
        cout << 0;
}
