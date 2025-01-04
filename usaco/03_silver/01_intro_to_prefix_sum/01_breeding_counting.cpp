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
    setIO("bcount");
    int num_cows, num_queries, tmp, a, b;
    cin >> num_cows >> num_queries;

    vector<vector<int>> prefix_sum(4, vector<int>(num_cows+1));

    for (int i = 1; i <= num_cows; i++) { 
        cin >> tmp;
        prefix_sum[tmp][i] = 1;
        for (int k = 1; k <= 3; k++){
            prefix_sum[k][i] += prefix_sum[k][i-1];
        }
    }

    for (int i = 0; i < num_queries; i++){
        cin >> a >> b;
        for (int k = 1; k <= 3; k++){
            int cnt = prefix_sum[k][b] - prefix_sum[k][a-1];
            cout << cnt ;
            if (k < 3){ cout << " "; }
        }
        if (i+1 < num_queries)
        cout << endl;
    }

    return 0;
}