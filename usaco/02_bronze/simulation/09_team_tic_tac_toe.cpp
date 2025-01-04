#include <bits/stdc++.h>
using namespace std;

const int WIDTH = 3;
vector<string> board(WIDTH);
set<set<char>> winners[WIDTH + 1];

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void insert(vector<pair<int, int>> arr){
    set<char> container;
    for (const pair<int, int> &item: arr){
        container.insert(board[item.first][item.second]);
    }
    winners[container.size()].insert(container);
}

int main(){
    setIO("tttt");
    for (int i = 0; i < WIDTH; i++ ) {cin >> board[i]; }

    for (int r = 0; r < WIDTH; r++) { insert({{r, 0}, {r, 1}, {r, 2}}); }
    for (int c = 0; c < WIDTH; c++) { insert({{0, c}, {1, c}, {2, c}}); }

    insert({{0,0}, {1,1}, {2,2}});
    insert({{0,2}, {1,1}, {2,0}});

    cout << winners[1].size() << endl << winners[2].size() << endl;
}