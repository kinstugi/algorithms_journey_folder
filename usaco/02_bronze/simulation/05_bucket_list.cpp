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
    setIO("blist");
    int n, s, t, b;
    cin >> n;
    vector<int> timeline(1005);

    while (n--){
        cin >> s >> t >> b;

        timeline[s] += b;
        timeline[t] -= b;
    }

    for (int i = 1; i < 1005; i++){ timeline[i] += timeline[i-1]; }
    int ans = 0;
    for (int num: timeline) { ans = max(ans, num); }
    cout << ans << endl;
    return 0;
}