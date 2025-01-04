#include <bits/stdc++.h>
using namespace std;

int main() {
	int mark_num;
	int remember_num;
	cin >> mark_num >> remember_num;

	// All net changes in the score
	vector<int> changes(mark_num + 1);
	vector<int> scores(remember_num);
	for (int i = 1; i <= mark_num; ++i) {
		cin >> changes[i];
		changes[i] += changes[i - 1];
	}
	for (int &p : scores) { cin >> p; }

	set<int> poss_starts;
	for (int m = 1; m <= mark_num; ++m) {
		poss_starts.insert(scores.front() - changes[m]);
	}

	int ans = 0;
	for (int s : poss_starts) {
		// What all the scores are going to now be given the starting score
		set<int> points;
		for (int i = 1; i <= mark_num; ++i) { points.insert(s + changes[i]); }

		bool valid = true;
		for (int p : scores) { valid &= points.count(p); }

		ans += valid;
	}
	cout << ans << endl;
}