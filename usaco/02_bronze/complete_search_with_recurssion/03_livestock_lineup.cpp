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
    setIO("lineup");
    string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows, cows+8);
    int n; cin >> n;

    string tmp;
    vector<pair<string, string>> relative_order(n);

    for (int i = 0; i < n; i++){ cin >> relative_order[i].first >> tmp>> tmp >> tmp >> tmp >>  relative_order[i].second; }

    do {
        int cnt = 0;
        for(const pair<string, string> item: relative_order){
            for (int i = 1; i < 8; i++){
                if ((item.first == cows[i] && item.second == cows[i-1]) || (item.first == cows[i-1] && item.second == cows[i])) { 
                    cnt++;
                    break;
                }
            }
        }

        if (cnt == (int)relative_order.size()){
            for (string cow: cows){cout << cow << endl;}
            break;
        }
    }while (next_permutation(cows, cows+8));

    return 0;
}