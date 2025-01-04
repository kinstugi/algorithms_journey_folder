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
    int arr_size;
    cin >> arr_size;
    map<ll, ll> mp = {{0, 1}};

    ll cur_sum = 0, tmp, ans = 0;

    for (int i = 0; i < arr_size; i++){
        cin >> tmp;
        cur_sum = ((cur_sum % arr_size) + (tmp % arr_size)) % arr_size;
        if (cur_sum < 0){ cur_sum = arr_size + cur_sum; }
        ans += mp[cur_sum];
        mp[cur_sum]++;
    }
    cout << ans << endl;
    return 0;
}