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
    ll n, w, h, mx_w = INT_MIN, mx_h = INT_MIN;
    cin >> n;


    for (int i = 0; i < n; i++){
        cin >> w >> h;
        mx_w = max(w, mx_w);
        mx_h = max(h, mx_h);
    }
    ll ans = mx_h * 2 + 2 * mx_w;
    cout << ans << endl;
    
}

int main(){
    setIO();
    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}