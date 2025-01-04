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
    setIO("pails");
    ll x, y, m;
    cin >> x >> y >> m;

    ll ans = 0;
    int div = m / x;
    
    for (int i = 0; i <= div; i++){
        for (int j = 0; j <= div; j++){
            ll tot = x * i + j * y;
            if (tot > m) continue;
            ans = max(ans,  tot);
        }
    }
    cout << ans << endl;
    return 0;
}