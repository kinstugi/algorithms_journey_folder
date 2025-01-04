#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    //setIO("test");
    int t, n, k;
    cin >> t;

    while (t--){
        cin >> n >> k;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) { cin >> a[i]; }
        for (int i = 0; i < n; i++) { cin >> b[i]; }

        int second_best = b[0];
        int first_total = a[0];
        int max_score = a[0] + second_best * (k-1);
        for (int c = 1; c < min(k, n); c++){
            second_best = max(second_best, b[c]);
            max_score = max(max_score, first_total + a[c] + second_best * (k-1-c));
            first_total += a[c];
        }
        cout << max_score << "\n";
    }
    return 0;
}