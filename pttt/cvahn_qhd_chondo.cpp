#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N= 1e3 + 7;

int n,v,i,j,A[N],B[N],C[N][N];
vector <int> ans;

void taobang()
{
    for (i = 1; i <= n; i++){
        for (j = 0; j <= v; j++){
            if (j >= A[i]){
                C[i][j] = max(C[i-1][j], C[i-1][j-A[i]]+B[i]);
            }
            else{
                C[i][j] = C[i-1][j];
            }
        }
    }
}

void truyhoi()
{
    i = n; j = v;
    while (i > 0){
        if (C[i][j] == C[i-1][j]){
            i--;
        }
        else{
            ans.push_back(i);
            j = j-A[i];
            i--;
        }
    }
}

main()
{
    cin >> n >> v;
    for (i = 1; i <= n; i++)
        cin >> A[i] >> B[i];
    taobang();
    truyhoi();
    cout << C[n][v] << endl;
    for (i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
