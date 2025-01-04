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
    setIO("mowing");
    int n, steps;
    char dxn;
    cin >> n;

    int x = 0, y = 0, current_time = 1;
    map<pair<int, int>, int> time_table;
    time_table[{0, 0}] = 0;
    int ans = INT32_MAX;

    while (n--){
        cin >> dxn >> steps;

        for (int d = 1; d <= steps; d++){
            if (dxn == 'N'){
                x++;
            }else if (dxn == 'S'){
                x--;
            }else if (dxn == 'E'){
                y--;
            }else{
                y++;
            }

            if (time_table.count({x, y})) {
                ans = min(ans, current_time - time_table[{x,y}]);
            }
            time_table[{x,y}] = current_time;
            current_time++;
        }
    }   
    if (ans == INT32_MAX)
    cout << -1 << endl;
    else
    cout << ans << endl;
    return 0;
}