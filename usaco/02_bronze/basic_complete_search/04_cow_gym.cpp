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
    setIO("gymnastics");
    int num_of_cows, num_of_sessions;
    cin >> num_of_sessions >>  num_of_cows;
    
    vector<vector<int>> sessions(num_of_sessions, vector<int>(num_of_cows + 1));
    for (int i = 0; i < num_of_sessions; i++){
        int tmp;
        for (int j = 0; j < num_of_cows; j++) { 
            cin >> tmp;
            sessions[i][tmp] = j;
        }
    }

    int ans = 0;
    for (int r = 1; r <= num_of_cows; r++){
        for (int c = 1; c <= num_of_cows; c++){
            if (r == c) continue;

            bool flag = true;
            for (int i = 0; i < num_of_sessions; i++){
                if (sessions[i][r] > sessions[i][c]) { 
                    flag = false;
                    break;
                }
            }

            if (flag){ ans++; }
        }
    }

    cout << ans << endl;
    return 0;
}