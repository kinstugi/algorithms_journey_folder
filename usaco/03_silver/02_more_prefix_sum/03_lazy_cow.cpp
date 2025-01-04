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
    setIO("lazy");
    
    int n, k;
    cin >> n >> k;

    int new_n = 2 * n - 1;
    vector<vector<int>> field(new_n, vector<int>(new_n, -1));

    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){ cin >> field[r+c][n-r+c-1]; }
    }

    vector<vector<int>> prefix(new_n+1, vector<int>(new_n+1));
    for (int r = 0; r < new_n; r++){
        for (int c = 0; c < new_n; c++){
            int val = max(field[r][c], 0);
            prefix[r+1][c+1] = val + prefix[r+1][c] + prefix[r][c+1] - prefix[r][c];
        }
    }

    int most_grass = 0;
    for (int r = k; r < new_n - k; r++){
        for (int c = k; c < new_n - k; c++){
            if (field[r][c] == -1) continue;
            most_grass = max(
                most_grass, 
                prefix[r+k+1][c+k+1] - prefix[r+k+1][c-k] - prefix[r-k][c+k+1] + prefix[r-k][c-k]
            );
        }
    }
    if (k >= n){ most_grass = prefix[new_n][new_n]; }
    cout << most_grass << endl;
    return 0;
}