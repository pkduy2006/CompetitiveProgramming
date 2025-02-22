// author: August9th

#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
int a[N], n;
vector<int> odd, even;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        
        if(a[i] % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    
    for(int i = 0; i < even.size(); i++)
        cout << odd[i] << ' ' << even[i] << ' ';
    
    return 0;
}
