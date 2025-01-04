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
    setIO("test");
    int n; cin >> n;
    vector<pair<double, double>> pts(n+2);

    for (int i = 1; i <= n; i++){
        cin >> pts[i].first >> pts[i].second;
    }

    double res = 0;
    for (int i = 1; i <= n+1; i++){
        double a = pts[i].first - pts[i-1].first;
        double b = pts[i].second - pts[i-1].second;

        res += sqrt(a*a + b*b);
    }

    cout << fixed << setprecision(9) <<res << endl;

    return 0;
}