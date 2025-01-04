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
    setIO("speeding");
    int n, m;

    vector<int> road_segments(101);
    int d = 1, seg, speed;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> seg >> speed;
        int bnd = seg + d;
        while (d < bnd){
            road_segments[d] = speed;
            d++;
        }
    }

    d = 1;
    int ans = 0;
    for (int i = 0; i < m; i++){
        cin >> seg >> speed;
        int bnd = d + seg;
        while (d < bnd){
            ans = max(ans, speed - road_segments[d]);
            d++;
        }
    }
    cout << ans << endl;
    return 0;
}