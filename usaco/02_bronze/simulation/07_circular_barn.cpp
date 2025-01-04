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
    setIO("cbarn");
    int n;
    cin >> n;
    vector<ll> rooms(n);

    for (int i = 0; i < n; i++) { cin >> rooms[i]; }

    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++){
        ll cur_index = (i+1) % n, cur_cnt = 0, step = 1;

        while(cur_index != i){
            cur_cnt += step * rooms[cur_index];
            cur_index = (cur_index + 1) % n;
            step++;
        }

        ans = min(ans, cur_cnt);
    }
    cout << ans << endl;
    return 0;
}