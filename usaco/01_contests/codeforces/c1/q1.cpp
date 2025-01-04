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

void solve(){
    int num_fams, num_rows;
    cin >> num_fams >> num_rows;

    vector<int> families(num_fams);

    for (int i = 0; i < num_fams; i++) { cin >> families[i]; }
    int happy = 0, rem = 0;

    for (int fam: families){
        int div = fam / 2;
        happy += div; 
        num_rows -= div;
        rem += fam % 2;
    }

    happy *= 2;

    while (rem > 0 && num_rows > 0 && rem > num_rows){
        rem -= 2;
        num_rows -= 1;
    }
    happy += max(rem, 0);
    cout << happy << endl;
}

int main(){
    setIO();
    int t;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}