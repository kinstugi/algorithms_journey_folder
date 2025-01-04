#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
	int arr_size;
	cin >> arr_size;

	vector<int> nums(arr_size), left(arr_size), right(arr_size);

	for(int i = 0; i < arr_size; i++) { cin >> nums[i]; }
	for (int i = 1, cur = 0; i < arr_size; i++){
		int res = gcd(cur, nums[i-1]);
		left[i] = res;
		cur = res;
	}

	for (int i = arr_size - 2, cur = 0; i > -1; i--){
		int res = gcd(cur, nums[i+1]);
		right[i] = res;
		cur = res;
	}
	int ans = 0;
	for (int i = 0; i < arr_size; i++ ) { ans = max(ans, gcd(left[i], right[i])); }
	cout << ans << endl;
}

int main(){
    setIO("test");

	solve();
    return 0;
}