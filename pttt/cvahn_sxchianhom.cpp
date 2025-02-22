#include <bits/stdc++.h>

using namespace std;

int n,h,i,dem,bd;
vector <int> A;

int main(){
    freopen("chianhom.inp","r",stdin); freopen("chianhom.out","w",stdout);
    cin >> n >> h;
    A.resize(n);
    for (i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    dem = 1;
    bd = 0;
    for (i = 0; i < n; i++){
        if (A[i]-A[bd] > h){
            bd = i;
            dem++;
        }
    }
    cout << dem;
    return 0;
}
