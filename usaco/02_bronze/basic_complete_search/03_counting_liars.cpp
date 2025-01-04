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
    setIO();
    int n;
	cin >> n;
	vector<pair<int, char>> arr(n);

	for (int i = 0; i < n; i++) { cin >> arr[i].second >> arr[i].first; }
	sort(arr.begin(), arr.end());

	vector<int> lying_left(n);
	for (int i = 1; i < n; i++){
		lying_left[i] += lying_left[i-1];
		if (arr[i-1].second == 'L' && arr[i].first >= arr[i-1].first){
			lying_left[i]++;
		}
	}

	vector<int> lying_right(n);
	for (int i = n-2; i >-1; i--){
		lying_right[i]+= lying_right[i+1];
		if (arr[i+1].second == 'G' && arr[i].first <= arr[i+1].first){
			lying_right[i]++;
		}
	}

	int ans = n;
	for (int i = 0; i < n; i++){
		ans = min(ans, lying_left[i] + lying_right[i]);
	}
	cout << ans << endl;
    return 0;
}