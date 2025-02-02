#include <bits/stdc++.h>
using namespace std;

const int N = 57;
const int INF = 1e9 + 7;
int n, k, a[N][N], res = INF, sum;
bool mark[N];
vector<int> journey, cycle;

bool check1() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                continue;
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    if(k == l)
                        continue;
                    if(a[i][j] != a[k][l])
                        return false;
                }
            }
        }
    }
    return true;
}

void Walk(int b) {
    if(journey.size() == k) {
        if(sum + a[journey.back()][1] < res) {
            res = sum + a[journey.back()][1];
            cycle = journey;
        }
        return;
    }
    vector<pair<int, int>> next_node;
    for(int i = 2; i <= n; i++) {
        if(!mark[i])
            next_node.push_back({a[b][i], i});
    }
    sort(next_node.begin(), next_node.end());
    for(auto& [value, node] : next_node) {
        if(sum + value >= res)
            continue;
        mark[node] = true;
        sum += value;
        journey.push_back(node);
        Walk(node);
        mark[node] = false;
        sum -= value;
        journey.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    if(check1()) {
        res = 0;
        for(int i = 1; i < k; i++)
            res += a[i][i + 1];
        res += a[k][1];
        cout << res << '\n';
        for(int i = 1; i <= k; i++)
            cout << i << ' ';
    }
    else {
        journey.push_back(1);
        mark[1] = true;
        Walk(1);
        cout << res << '\n';
        for(int node : cycle) 
            cout << node << ' ';
    }

    return 0;
}
