#include <bits/stdc++.h>
using namespace std;

int N = 8;
vector<vector<int>> graph(8);
set<string> seen;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("lineup");

    string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows, cows + 8);
    unordered_map<string, int> cow_inds;

    for (int i = 0; i < N; i++){ cow_inds[cows[i]] = i; }

    int n;
    cin >> n;
    string cowA, cowB, tmp;
    for (int i = 0; i < n; i++){
        cin >> cowA >> tmp >> tmp >> tmp >> tmp >> cowB;
        int c1 = cow_inds[cowA], c2 = cow_inds[cowB];
        
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    vector<bool> added(N, false);
    vector<int> order;

    for (int c = 0; c < N; c++){
        if (!added[c] && graph[c].size() < 2){
            added[c] = true;
            order.push_back(c);

            if (graph[c].size() == 1){
                int prev = c;
                int at = graph[c][0];
                while (graph[at].size() == 2){
                    added[at] = true;
                    order.push_back(at);

                    int a = graph[at][0];
                    int b = graph[at][1];
                    int tmp_at = a == prev ? b : a;
                    prev  = at;
                    at = tmp_at;
                }
                added[at] = true;
                order.push_back(at);
            }
        }
    }
    
    for (int c: order)
    cout << cows[c] << endl;
    return 0;
}