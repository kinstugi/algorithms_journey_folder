#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> sum(26, vector<int>(n + 1));
	rep(i, n) {
		rep(j, 26) {
			sum[j][i + 1] = sum[j][i];
		}
		sum[s[i] - 'A'][i + 1]++;
	}
	ll ans = 0;
	for (int i = 1; i < n - 1; i++) {
		rep(j, 26) {
			ll l = sum[j][i];
			ll r = sum[j][n] - sum[j][i + 1];
			ans += l * r;
		}
	}
	cout << ans << '\n';
}
