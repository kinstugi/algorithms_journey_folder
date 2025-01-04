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
    setIO();
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;
        int x = 0, i = 0;
        while (abs(x) <= n){
            i++;
            int d = 2 * i - 1;

            if (i % 2){ x -= d; }
            else{ x += d; }
        }

        if (i % 2){ cout << "Sakurako\n";}
        else{ cout << "Kosuke\n"; }
    }
    return 0;
}