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
    ll n, team, health, teams[4] = {0, 0, 0, 0};
    cin >> n;
    map<int, vector<ll>> mp;

    ll total_health = 0;

    for (int i = 0; i < n; i++){
        cin >> team >> health;
        mp[team].push_back(health);

        total_health += health;
        teams[team] += health;
    }

    if (total_health % 3){
        cout << -1 << endl;
        return 0;
    }

    ll target_div = total_health / 3;
     

    return 0;
}