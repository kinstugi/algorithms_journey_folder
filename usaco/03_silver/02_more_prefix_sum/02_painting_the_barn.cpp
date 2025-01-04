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

const int SZ = 1001;

int main(){
    setIO("paintbarn");
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> barn(SZ+1, vector<int>(SZ+1));

    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        r1++; c1++; r2++; c2++;
        barn[r1][c1]++;
        barn[r1][c2]--;
        barn[r2][c1]--;
        barn[r2][c2]++;
    }
    
    for (int r = 1; r <= SZ; r++){
        for (int c = 1; c <= SZ; c++){
            barn[r][c] +=  barn[r][c-1] + barn[r-1][c] - barn[r-1][c-1];
        }
    }
    int area = 0;
    for (int r = 0; r < SZ; r++){
        for (int c = 0; c < SZ; c++){
            area += barn[r][c] == k;
        }
    }

    cout << area << endl;
    return 0;
}