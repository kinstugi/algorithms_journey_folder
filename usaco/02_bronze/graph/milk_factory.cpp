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

vector<bool> seen(101, false);


int main(){
    setIO("factory");
    int n, a, b;
    cin >> n;

    vector<int> out_deg(n+1);
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        out_deg[a]++;
    }

    int z_cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++){
        if (out_deg[i] == 0){
            z_cnt++;
            ans = i;
        }
    }

    if (z_cnt > 1 || z_cnt == 0)
    cout << -1 << endl;
    else
    cout << ans << endl;

    return 0;
}