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
    setIO("triangles");
    int n;
    cin >> n;
    vector<int> X(n), Y(n);

    for (int i = 0; i < n; i++) { cin >> X[i] >> Y[i]; }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (i == j && j == k) continue;
                // cout << i << " " << j << " " << k << endl;

                if (X[i] == X[j] && Y[i] == Y[k]){
                    ans = max(ans, abs(Y[i] - Y[j]) * abs(X[i] - X[k]));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}