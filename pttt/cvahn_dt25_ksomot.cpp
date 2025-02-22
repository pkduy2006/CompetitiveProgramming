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

int n, k, res = 0;
vector<int> bitmasks, num;

int convert()
{
    int answer = 0;

    for(int i = num.size() - 1; i >= 0; i--)
    {
        if(num[i] == 1)
            answer += (1 << i);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ksomot.inp","r",stdin);
    freopen("ksomot.out","w",stdout);

    cin >> n >> k;
    int t = n;
    while(t > 0)
    {
        bitmasks.push_back(t % 2);
        t /= 2;
    }

    if(bitmasks.size() < k)
    {
        cout << 0;

        return 0;
    }

    if(bitmasks.size() == k)
    {
        cout << 1;

        return 0;
    }

    for(int i = 1; i <= k; i++)
        num.push_back(1);
    for(int i = k + 1; i <= bitmasks.size(); i++)
        num.push_back(0);
    sort(num.begin(), num.end());

    int tmp = convert();

    if(tmp <= n)
        res++;

    while(next_permutation(num.begin(), num.end()))
    {
        tmp = convert();

        if(tmp <= n)
            res++;
    }

    cout << res;

    return 0;
}
