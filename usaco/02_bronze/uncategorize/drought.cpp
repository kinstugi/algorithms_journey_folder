#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> hunger(n+1);

    for (int i = 1; i <= n; i++) { cin >> hunger[i]; }

    ll bags_needed = 0;
    for (int i = 1; i < n; i++){
        if (hunger[i+1] > hunger[i]){
            // then we will reduce hunger[i+1] and hunger[i+2] until hunger[i+1] == hunger[i]
            if (i + 2 > n) {
                cout << -1 << endl;
                return;
            }

            ll difference = hunger[i+1] - hunger[i];
            hunger[i+1] -= difference;
            hunger[i+2] -= difference;

            if (hunger[i+2] < 0){
                cout << -1 << endl;
                return;
            }

            bags_needed += 2 * difference;
        }else if (hunger[i] > hunger[i+1]){
            if (i % 2) {
                cout << -1 << endl;
                return;
            }
            ll difference = hunger[i] - hunger[i+1];
            bags_needed += i * difference; 
        }
    }

    cout << bags_needed << endl;
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    //setIO("test");
    int t;
    cin >> t;

    while (t--){ solve(); }
    return 0;
}