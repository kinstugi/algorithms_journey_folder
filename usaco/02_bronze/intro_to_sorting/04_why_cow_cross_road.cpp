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
    setIO("cowqueue");
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) { 
        cin >> intervals[i].first >> intervals[i].second; 
    }

    sort(intervals.begin(), intervals.end());
    int t = 0, cur_t  = 0;

    for (pair<int, int> &itv: intervals){
        if (itv.first < cur_t){
            itv.first = cur_t;   
        }
        cur_t = itv.first + itv.second;
    }

    cout << cur_t << endl;
    return 0;
}