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
    int n; cin >> n;
    vector<ll> X(n) , Y(n);

    for (int i = 0; i < n; i++ ) { cin >> X[i]; }
    for (int i = 0; i < n; i++ ) { cin >> Y[i]; }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ll  dx = abs(X[i] - X[j]), dy = abs(Y[i] - Y[j]);
            ans = max(ans, dx*dx  + dy*dy);
        }
    }
    cout << ans << endl;
    return 0;
}