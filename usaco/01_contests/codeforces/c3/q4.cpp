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

void solve(int n){
    vector<int> arr(n);
    map<int, int> mp;
    mp[0] = -1;
    int total = 0;
    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        total += tmp;
        if (mp.find(total) != mp.end()){
            while (!intervals.empty()){
                // if do not overlap break
                bool res = mp[total] <= intervals.back().first && intervals.back().first <= i;
                if (!res) { break; }
            
            }
            intervals.push_back({mp[total], i});
        }
        mp[total] = i;
    }


}

int main(){
    setIO();
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;
        solve(n);
    }
    return 0;
}