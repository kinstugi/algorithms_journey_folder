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
    setIO("tttt");
    string game[3];

    for (int i = 0; i < 3; i++) { cin >> game[i]; }
    set<char> rows[3], cols[3], diag1, diag2, singles_set;

    for (int r = 0; r < 3; r++){ rows[r].insert(game[r][0]);  rows[r].insert(game[r][1]);  rows[r].insert(game[r][2]); }
    for (int c = 0; c < 3; c++){ cols[c].insert(game[0][c]);  cols[c].insert(game[1][c]);  cols[c].insert(game[2][c]); }

    diag1.insert(game[0][0]); diag1.insert(game[1][1]); diag1.insert(game[2][2]);
    diag2.insert(game[0][2]); diag2.insert(game[1][1]); diag2.insert(game[2][0]);

    set<pair<char, char>> pairs_set;

    for (int i = 0; i < 26; i++){
        for (int j = i+1; j < 26; j++){
            char ff = 'A' + i, ss = 'A' + j;

            for (int r = 0; r < 3; r++){
                if (rows[r].count(ff) && rows[r].count(ss) && rows[r].size() == 2) { pairs_set.insert({ff, ss}); }
            }

            for (int c = 0; c < 3; c++){
                if (cols[c].count(ff) && cols[c].count(ss) && cols[c].size() == 2) { pairs_set.insert({ff, ss}); }
            }

            if (diag1.count(ff) && diag1.count(ss) && diag1.size() == 2) { pairs_set.insert({ff, ss}); }
            if (diag2.count(ff) && diag2.count(ss) && diag2.size() == 2) { pairs_set.insert({ff, ss}); }
        }
    }

    for (int i = 0; i < 26; i++){
        char ff = 'A' + i;
        for (int r = 0; r < 3; r++){
            if (rows[r].count(ff) && rows[r].size() == 1) { singles_set.insert(ff); }
        }

        for (int c = 0; c < 3; c++){
            if (cols[c].count(ff) &&  cols[c].size() == 1) { singles_set.insert(ff); }
        }

        if (diag1.count(ff) && diag1.size() == 1) { singles_set.insert(ff); }
        if (diag2.count(ff) && diag2.size() == 1) { singles_set.insert(ff); }
    }

    cout << singles_set.size() << endl;
    cout << pairs_set.size() << endl;
    return 0;   
}