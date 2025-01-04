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

int solveCycle(int r, int c, vector<string> &grid){
    int dxn = 0, R = grid.size(), C = grid[0].size();
    set<pair<int, int>> seen;

    while (true){
        seen.insert({r,c});
        int rr = r + dxns[dxn].first, cc = c + dxns[dxn].second;
        if (rr < 0 || rr >= R || cc < 0 || cc >= C){ break; }
        
        if (grid[rr][cc] == '#'){
            dxn = (dxn + 1) % 4;
        }else{
            r = rr; c = cc;
        }
    }

    return (int)seen.size();
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

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] == '^') { 
                answer = solveCycle(r, c, grid);
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}