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
    setIO("circlecross");
    string cows;
    cin >> cows;

    vector<int> last_seen(26, -1);
    for (int i = 0; i < cows.size(); i++){
        last_seen[cows[i] - 'A'] = i;
    }

    int ans = 0;
    for (int i = 0; i < cows.size(); i++){
        char ch = cows[i];

        for (int j = i; j < last_seen[ch - 'A']; j++){
            if (last_seen[cows[j] - 'A'] > last_seen[ch - 'A']) { ans++; }
        }
    }

    cout << ans << endl;
    return 0;
}