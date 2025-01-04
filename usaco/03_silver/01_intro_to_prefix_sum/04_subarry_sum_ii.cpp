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
    int num_elements, target_sum;
    cin >> num_elements >> target_sum;

    map<ll, ll> mp = {{0, 1}};
    ll ans = 0, cur_sum = 0, tmp;

    for (int i = 0; i < num_elements; i++){
        cin >> tmp;
        cur_sum += tmp;
        
        ll dd = cur_sum - target_sum;
        if (mp.find(dd) != mp.end()){
            ans += mp[dd];
        }
        mp[cur_sum]++;
    }
    cout << ans << endl;
    return 0;
}