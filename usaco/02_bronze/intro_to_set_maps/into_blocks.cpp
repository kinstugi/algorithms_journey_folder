#include <bits/stdc++.h>

int
main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, _;
	std::cin >> n >> _;
	std::vector<int> a(n);
	std::array<int, 200010> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		m[a[i]] = i;
	}
	std::array<int, 200010> occurence = {};
	int ans = 0;
	for (int i = 0; i < n;) {
		int j;
		int last = m[a[i]];
		int maxi = 0;
		for (j = i; j <= last; j++) {
			last = std::max(last, m[a[j]]);
			maxi = std::max(maxi, ++occurence[a[j]]);
		}
		ans += j - i - maxi;
		i = j;
	}
	std::cout << ans << '\n';
}