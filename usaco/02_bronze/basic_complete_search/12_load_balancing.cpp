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
    setIO("balancing");
    int n, b;
    cin >> n >> b;

    vector<int> X(n), Y(n);
    set<int> vfence, hfence;

    for (int i = 0; i < n; i++) {  
        cin >> X[i] >> Y[i];
        vfence.insert(X[i] + 1);
        hfence.insert(Y[i] + 1); 
    }

    int ans = INT_MAX;
    for (int vf: vfence){
        for (int hf: hfence){

            int b_x = vf, b_y = hf;
            vector<int> quadrants(4);

            for (int r = 0; r < n; r++){
                if (X[r] < b_x && Y[r] < b_y){ quadrants[0]++; }
                else if (X[r] < b_x && Y[r] > b_y) { quadrants[1]++; }
                else if (X[r] > b_x && Y[r] > b_y) { quadrants[2]++; }
                else if (X[r] > b_x && Y[r] < b_y) { quadrants[3]++; }
            }

            int mx = 0;
            for (int quad: quadrants) { 
                mx = max(mx, quad); 
            }
            ans = min(mx, ans);
        }
    }
    cout << ans << endl;
    return 0;
}