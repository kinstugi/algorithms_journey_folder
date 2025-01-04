#include <bits/stdc++.h>
using namespace std;

vector<int> graph[151];
int seen[151], field_color[151], N, M;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("revegetate");
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int node = 1; node <= N; node++){
        int colors_available[5] = {0, 1, 2, 3, 4};
        for (int nei: graph[node]){ colors_available[field_color[nei]] = 0; }

        for (int color: colors_available){
            if (color){
                field_color[node] = color;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++){
        cout << field_color[i];
    }
    return 0;
}