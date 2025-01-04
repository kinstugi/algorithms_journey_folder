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
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    set<int> vb, hb;
    for (int i = 0; i < n; i++) { 
        cin >> X[i] >> Y[i];
        vb.insert(X[i] + 1);
        hb.insert(Y[i] + 1);  
    }

    int ans = INT_MAX;
    for (int v: vb){
        
        for (int h: hb){
            vector<int> quadrants(4);

            for (int i = 0; i < n; i++){
                if (X[i] < v && Y[i] < h) { quadrants[0]++; }
                else if (X[i] < v && Y[i] > h) {quadrants[1]++; }
                else if (X[i] > v && Y[i] < h) { quadrants[2]++; }
                else { quadrants[3]++; }
            }

            int mx = 0;
            for (int qd: quadrants){ 
                mx = max(mx, qd);
            }
            ans = min(mx, ans);
        }
    }
    cout << ans << endl;
    return 0;
}