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
    setIO();
    int n_sides, n_queries;
    cin >> n_sides >> n_queries;
    
    vector<vector<int>> forest(n_sides + 1, vector<int>(n_sides+1));

    for (int r = 1; r <= n_sides; r++){
        for (int c = 1; c <= n_sides; c++){
            char tree;
            cin >> tree;

            forest[r][c] = forest[r][c-1] + forest[r-1][c] - forest[r-1][c-1] + (tree == '*'); 
        }
    }

    int r1, c1, r2, c2;
    for (int i = 0; i < n_queries; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        int res = forest[r2][c2] - forest[r2][c1-1] - forest[r1-1][c2] + forest[r1-1][c1-1];
        cout << res << endl;
    }
    return 0;
}