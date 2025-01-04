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
    vector<pair<int, int>> intervals;
    int start, end;

    for (int i = 0; i < n; i++){
        cin >> start >> end;
        intervals.push_back({start, 1});
        intervals.push_back({end, -1});
    }

    sort(intervals.begin(), intervals.end());
    int customer_count = 0, max_customer = 0;
    for (const auto &item: intervals){
        customer_count += item.second;
        max_customer = max(max_customer, customer_count);
    }

    cout << max_customer << endl;
    return 0;
}