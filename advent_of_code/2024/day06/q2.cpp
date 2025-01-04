#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dxns = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void setIO(string file = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout); 
    }
}

bool solveCycle(int r, int c, vector<string> &grid){
    int dxn = 0, R = grid.size(), C = grid[0].size();
    vector<bool> vis(R * C * 4, false);

    while (true){
        int hash = (r * C + c) * 4 + dxn;
        if (vis[hash]){ return true; }
        vis[hash] = true;

        int rr = r + dxns[dxn].first, cc = c + dxns[dxn].second;
        if (rr < 0 || rr >= R || cc < 0 || cc >= C){ return false; }
        
        if (grid[rr][cc] == '#'){
            dxn = (dxn + 1) % 4;
        }else{
            r = rr; c = cc;
        }
    }

    return 0;
}

int main(){
    setIO("input");
    string s;
    vector<string> grid;

    while(getline(cin, s)){
        grid.push_back(s);
    }
    int R = grid.size(), C = grid[0].size();
    int answer = 0;
    int guard_r, guard_c;

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] == '^') { 
                guard_r = r; guard_c = c;
                grid[r][c] = '.';
            }
        }
    }

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] == '.'){
                if (r == guard_r && c == guard_c) continue;
                grid[r][c] = '#';
                answer += solveCycle(guard_r, guard_c, grid);
                grid[r][c] = '.';
            }
        }
    }
    cout << answer << endl;
    return 0;
}