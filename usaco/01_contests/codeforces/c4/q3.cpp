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
    int n, num;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++){
        cin >> num;
        int res = num - 1 + i;
        mp[res] = i-1;
    }

    while (mp.find(n) != mp.end() && mp[n]){
        int steps = mp[n];
        int new_n = n + steps;
        for (int i = n + 1; i <= new_n; i++){
            mp[i-1] = i-1;
        }
        n = new_n;
    }

    cout << n << endl;
}

int main(){
    setIO("test");
    int t;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}