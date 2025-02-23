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
#pragma GCC optimize("unroll-lMps")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 6;
const int M = 1e9;
const int MOD = 1e9 + 7;

int n;
int r, c;
int first_res_a, second_res_a, res_b;

int calculate(int x) {
    return ((x + 1) * (((x - 1) / 2) + 1)) / 2;
}

void ss1()
{
    int s = 0, previous_s = 0;
    for (int i = 1; i * i <= M; i++)
    {
        s += (i * 2 - 1);

        if (s >= n)
        {
            first_res_a = i;
            break;
        }

        previous_s += (i * 2 - 1);
    }

    cout << first_res_a << " ";

    if (first_res_a % 2 == 0)
        second_res_a = n - previous_s;
    else
        second_res_a = s + 1 - n;

    cout << second_res_a << '\n';
}

void ss2()
{
    int s = calculate(2 * r - 1);
    int previous_s = calculate(2 * r - 3);
    if (r % 2 == 0)
        res_b = previous_s + c;
    else
        res_b = s + 1 - c;

    cout << res_b;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PYRAMID.inp","r",stdin);
    freopen("PYRAMID.out","w",stdout);

    cin >> n >> r >> c;

    ss1();
    ss2();

    return 0;
}
