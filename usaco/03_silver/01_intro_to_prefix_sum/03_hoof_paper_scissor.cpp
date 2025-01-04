#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("hps");
    int num_games;
    cin >> num_games;
    map<char, vector<int>> prefix_sums = {{'P', vector<int>(num_games+1)}, {'S', vector<int>(num_games+1)}, {'H', vector<int>(num_games+1)}};

    for (int i = 1; i <= num_games; i++){
        char ch; cin >> ch;
        prefix_sums[ch][i] = 1;
        
        for (auto &item: prefix_sums){
            item.second[i] += item.second[i-1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= num_games; i++){
        int p = prefix_sums['P'][i] + max(prefix_sums['S'][num_games] - prefix_sums['S'][i], prefix_sums['H'][num_games] - prefix_sums['H'][i]);
        int s = prefix_sums['S'][i] + max(prefix_sums['P'][num_games] - prefix_sums['P'][i], prefix_sums['H'][num_games] - prefix_sums['H'][i]);
        int h = prefix_sums['H'][i] + max(prefix_sums['P'][num_games] - prefix_sums['P'][i], prefix_sums['S'][num_games] - prefix_sums['S'][i]);
        ans = max(ans, max(p,max(s,h)));
    }
    cout << ans << endl;
    return 0;
}