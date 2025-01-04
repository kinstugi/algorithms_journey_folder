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
    setIO("cowsignal");
    int row, col, k;
    cin >> row >> col >> k;
    vector<vector<char>> board(row * k, vector<char>(col * k, '.'));

    
    for (int r = 0,nr = 0; r < row; r++, nr += k){
        string tmp;
        cin >> tmp;
        for (int c = 0, nc = 0; c < col; c++, nc += k){
            if (tmp[c] == '.') continue;
            board[nr][nc] = tmp[c];

            for (int rr = nr; rr < nr + k; rr++){
                for (int cc = nc; cc < nc + k; cc++){
                    board[rr][cc] = tmp[c];
                }
            }
        }
    }

    for (int r = 0; r < row * k; r++){
        for (int c = 0; c < col * k; c++){
            cout << board[r][c] ;
        }
        cout << endl;
    }
    return 0;
}