#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int mp[102][102], ans[102][102];
int n, m;

int get_safe_val(int x, int y) {
	if (x > n || x <= 0) return -1;
	if (y > m || y <= 0) return -1;
	return ans[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;

		vector<pair<int, pair<int, int>>> value;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mp[i][j], ans[i][j] = mp[i][j], value.emplace_back(mp[i][j], pii(i, j));

		sort(value.begin(), value.end(), greater<>());

		for (const auto &i : value) {
			int cost = i.first;
			int x = i.second.first, y = i.second.second;

			int f = 0;
			if (get_safe_val(x - 1, y) == cost + 1) f = 1;
			if (get_safe_val(x, y - 1) == cost + 1) f = 1;
			if (get_safe_val(x + 1, y) == cost + 1) f = 1;
			if (get_safe_val(x, y + 1) == cost + 1) f = 1;

			if (f) continue;
			ans[x][y]++;
		}

		//cout << "=start==\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << ans[i][j] << " ";
			cout << "\n";
		}
		//cout << "=end==\n";
	}
}
