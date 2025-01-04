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

struct Cow{
    int l, r;
    bool operator<(Cow &other){
        return l < other.l;
    }
};

int main(){
    setIO("lifeguards");
    int n;
    cin >> n;

    vector<Cow> cows(n);

    for (int i = 0; i < n; i++){ cin >> cows[i].l >> cows[i].r; }
    sort(cows.begin(), cows.end());

    int total_time = 0;
	// right = max ending point of lifeguards considered so far
	int left = 0, right = 0;

	// calculate total_time
	for (int i = 0; i < n; i++) {
		if (cows[i].r > right) {
			left = max(right, cows[i].l);
			total_time += cows[i].r - left;
			right = cows[i].r;
		}
	}

	Cow last;
	last.l = cows[n - 1].r;
	cows.push_back(last);

	// min time a cow spends alone
	int min_alone_time = total_time;
	right = 0;
	for (int i = 0; i < n; i++) {
		int curr_res = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, right);
		min_alone_time = min(min_alone_time, curr_res);
		right = max(right, cows[i].r);
	}
    cout << total_time - max(min_alone_time, 0) << endl;
    return 0;
}