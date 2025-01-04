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
    setIO("maxcross");
    ll num_crosswalk, num_continuous_block, num_spoiled, tmp;
    cin >> num_crosswalk >> num_continuous_block >> num_spoiled;
    
    vector<ll> prefix_sum(num_crosswalk + 1, 0);
    for (int i = 0; i < num_spoiled; i++){
        cin >> tmp;
        prefix_sum[tmp] = 1;
    }

    for(int i = 1; i <= num_crosswalk; i++){
        prefix_sum[i] += prefix_sum[i-1];
    }

    ll ans = INT_MAX;
    for (int i = num_continuous_block; i <= num_crosswalk; i++){
        ans = min(ans, prefix_sum[i] - prefix_sum[i - num_continuous_block]);
    }
    cout << ans << endl;
    return 0;
}