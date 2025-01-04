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
    map<ll, ll> mp;
    ll num_count, target_num, num;
    cin >> num_count >> target_num;

    for (ll i = 1; i <= num_count; i++){
        cin >> num;
        int diff = target_num - num;
        if (mp.count(diff)){
            cout << mp[diff] << " " << i << endl;
            return 0;
        }
        mp[num] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}