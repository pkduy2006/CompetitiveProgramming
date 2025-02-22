#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, x_side, y_side, z_side, res;
pair<int, int> points[N];
long double s, max_s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> points[i].first >> points[i].second;
    
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k <= n; k++)
            {
                int first_side = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                int second_side = (points[j].first - points[k].first) * (points[j].first - points[k].first) + (points[j].second - points[k].second) * (points[j].second - points[k].second);
                int third_side = (points[k].first - points[i].first) * (points[k].first - points[i].first) + (points[k].second - points[i].second) * (points[k].second - points[i].second);

                if (first_side > second_side) swap(first_side, second_side);
                if (first_side > third_side) swap(first_side, third_side);
                if (second_side > third_side) swap(second_side, third_side);
                
                if(first_side + second_side == third_side)
                {
                    res++;
                    //cout << points[i].first << ' ' << points[i].second << ' ' << points[j].first << ' ' << points[j].second << ' ' << points[k].first << ' ' << points[k].second << '\n';
                    
                    long double s = sqrt(first_side) * sqrt(second_side) / 2;
                    if(max_s < s)
                    {
                        x_side = i;
                        y_side = j;
                        z_side = k;
                        max_s = s;
                    }
                }
            }
        }
    }

    if(res == 0)
    {
        cout << 0;
        return 0;
    }

    cout << res << '\n' << points[x_side].first << ' ' << points[x_side].second << ' ' << points[y_side].first << ' ' << points[y_side].second << ' ' << points[z_side].first << ' ' << points[z_side].second << '\n';
    cout << fixed << setprecision(3) << max_s;

    return 0;
}
