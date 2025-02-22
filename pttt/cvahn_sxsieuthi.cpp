#include <bits/stdc++.h>

using namespace std;

int n,k,i,sum,temp,dem;
vector <int> A;

bool comp(int l, int r)
{
    return (l > r);
}

int main()
{
    freopen("sieuthi.inp","r",stdin); freopen("sieuthi.out","w",stdout);
    cin >> n >> k;
    A.resize(n);
    for (i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end(),comp);
    dem = 0;
    sum = 0;
    temp = 0;
    for (i = 0; i < n; i++){
        dem++;
        temp += A[i];
        if (dem == k){
            sum += temp-A[i];
            temp = 0;
            dem = 0;
        }
    }
    sum += temp;
    cout << sum;
    return 0;
}
