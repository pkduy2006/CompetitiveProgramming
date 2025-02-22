#include <bits/stdc++.h>
#define task "BIGPRODUCT."

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > II;
typedef pair < ll, ll > PLL;
typedef pair < double, int > DI;

const int maxn = 50000 + 10;
const int dd[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int A[maxn], B[maxn], res[2 * maxn];
string s1, s2;

void enter()
{
    //freopen(task"inp", "r", stdin);
    //reopen(task"out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> s1 >> s2;
}

void big_multiply(string s1, string s2)
{
    int d1 = 0, d2 = 0;
    for (int i = s1.size() - 1; i >= 0; --i) A[++d1] = s1[i] - '0';
    for (int i = s2.size() - 1; i >= 0; --i) B[++d2] = s2[i] - '0';
    // Reserve two string and add digits into two arrays
    // Multiply from the back of two big-number
    for (int i = 1; i <= d1; ++i)
	for (int j = 1; j <= d2; ++j)
        {
            int temp = (A[i] * B[j]);
            res[i + j - 1] += temp; // Multiply two digits and add to position [i + j - 1] in res;
            res[i + j] += (res[i + j - 1] / 10); // Accumulate the carry digit to the next position
            res[i + j - 1] %= 10; // Keep the last digit in this position
        }
    int length = (res[d1 + d2]) ? d1 + d2: d1 + d2 - 1; // Get the real length of res
    for (int i = length; i >= 1; --i)
	cout << res[i];
}

int main()
{
    enter();
    big_multiply(s1, s2);
    return 0;
}
