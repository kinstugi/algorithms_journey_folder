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
    setIO("lifeguards");
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++){ cin >> intervals[i].first >> intervals[i].second; }

    int ans = 0;
    for (int i = 0; i < n; i++){
        vector<int> times(1003);
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (j == i) continue;

            times[intervals[j].first] += 1;
            times[intervals[j].second] -= 1; 
        }

        for (int i = 1; i < 1001; i++) { times[i] += times[i-1]; }
        for (int num: times){
            if (num > 0) {cnt++;}
        }
        ans = max(ans,  cnt);
    }
    cout << ans << endl;
    return 0;
}