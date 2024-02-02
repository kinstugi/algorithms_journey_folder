#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int graph[1001][1001];

int dfs(int r, int c, int R, int C){
    if( r < 0 || c < 0 || r >= R || c >= C) return 0;
    if (graph[r][c] <= 0) return 0;
    int tot = graph[r][c];
    graph[r][c] *= -1;
    return tot + dfs(r,c-1, R,C) + dfs(r,c+1, R,C) + dfs(r-1,c,R, C) +  dfs(r+1,c,R,C);
}

int main() {
	setIO("data");
    int t, n, m;
    cin >> t;

    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> graph[i][j];
            }
        }
        int mx = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (graph[i][j] <= 0) continue;
                mx = max(mx, dfs(i,j,n,m));
            }
        }
        cout << mx << '\n';
    }
}