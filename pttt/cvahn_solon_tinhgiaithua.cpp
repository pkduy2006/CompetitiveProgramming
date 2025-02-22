#include <bits/stdc++.h>

using namespace std;
const int nm = 10000000;
long long gt[nm], ngt;
void nhan(int m)
{
    int nho = 0;
    for(int i = 1; i <= ngt; i++)
    {
        nho = nho + gt[i]*m;
        gt[i] = nho % 10;
        nho = nho/10;
    }
    while(nho > 0)
    {
        ngt++;
        gt[ngt] = nho % 10;
        nho = nho / 10;
    }
}
int main()
{
    long long n;
    cin >> n;
    ngt = 1;
    gt[1] = 1;
    for(int i = 2; i <= n; i++) nhan(i);
    for(int i = ngt; i >= 1; i--)
    {
        cout << gt[i];
    }
    return 0;
}
