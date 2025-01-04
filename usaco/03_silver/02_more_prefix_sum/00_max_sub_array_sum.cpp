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


int main(){
    setIO();
    ll n, max_sum = INT_MIN;
    cin >> n;

    ll cur_total = 0, cur_min = 0;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cur_total += tmp;

        max_sum = max(max_sum, cur_total - cur_min);
        cur_min = min(cur_min, cur_total);
    }
    cout << max_sum << endl;
    return 0;
}