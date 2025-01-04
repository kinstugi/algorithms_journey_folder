#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> bessie, seen, res;

bool recur(int i, int cur){
    if (i+1 == n) return true;

    int nxt = bessie[i] - cur;
    if (seen[nxt] || nxt == 0) return false;

    seen[nxt] = true;
    res.push_back(nxt);

    if (recur(i+1, nxt)) return true;

    seen[nxt] = false;
    res.pop_back();
    return false;
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("photo");
    cin >> n;
    bessie.resize(n-1);

    for (int i = 0; i < n-1; i++) { cin >> bessie[i]; }
    seen.resize(n+1);
    
    for (int i = 1; i <= bessie[0]; i++) { 
        seen[i] = true;
        res.push_back(i);
        if (recur(0, i)) break;
        seen[i] = false;
        res.pop_back();
    }

    for (int i = 0; i < n; i++) { 
        cout << res[i];
        if (i != n-1){ cout << " "; } 
    }
    // cout << endl;
    return 0;
}