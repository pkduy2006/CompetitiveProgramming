#include <bits/stdc++.h>
using namespace std;
const  int mn = 1e5+1;
long long i,j,k,m,n,a[mn],x,y,d=0,h=1;
vector<long long> v;
bool ktnt(int n){
    if(n < 2){return 1;}
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0) return 0;
    }
    return 1;
}
bool tknp(int left, int right, int x) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if(x == v[mid]) {return 1;}
        else
        if(x > v[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}
int main() 
{
    cin >> n;
    cin >> x >> y;
    for(i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int u = 0;
    i = 2;
    v.push_back(0);
    v.push_back(x);
    while(v[i-1] <= a[n]){
        m = v[i-1] + y;
        v.push_back(m);
        h++;
        i++;
    }
    for(i = 1; i <= n; i++){
        if(ktnt(a[i]) == 1){
            if(tknp(1,h,a[i]) == 1) d++;
        }
    }
    cout << d;
    return 0;
}
