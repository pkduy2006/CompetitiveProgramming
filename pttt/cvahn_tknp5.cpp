#include <bits/stdc++.h>
using namespace std;

const int N = 2003;
vector<int>id[N];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;

		id[x + 1001].push_back(i);
	}

	int res = n;
	for (int i = 1; i < N; i++) {
		int sz = id[i].size();
		if (sz == 0) continue;

		int tmp = id[i][0];
		for (int j = 0; j < (sz - 1); j++) {
			tmp = max(tmp, id[i][j + 1] - id[i][j]); 
		}
		tmp = max(tmp, n + 1 - id[i][sz - 1]);

		res = min(res, tmp);
	}
	cout << res << '\n';

	return 0;
}
