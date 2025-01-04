#include <bits/stdc++.h>
using namespace std;

void setIO(string file = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

void processPoints(pair<int, int> p1, pair<int, int> p2, int R, int C, set<pair<int, int>> &seen){
    int dr = p1.first - p2.first;
    int dc = p1.second - p2.second;

    int nr = p1.first + dr, nc = p1.second + dc;
    if (0 <= nr && nr < R && 0 <= nc && nc < C){ seen.insert({nr, nc});}

    nr = p2.first - dr; nc = p2.second - dc;
    if (0 <= nr && nr < R && 0 <= nc && nc < C){ seen.insert({nr, nc});} 
}

int main(){
    setIO("sample");
    vector<string> grid;
    string s;

    while(getline(cin, s)){
        grid.push_back(s);
    }
    
    int R = grid.size(), C = grid[0].size();
    map<char, vector<pair<int, int>>> table;

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] == '.') continue;
            table[grid[r][c]].push_back({r,c});
        }
    }
    set<pair<int, int>> seen;
    for(const auto &item: table){
        int sz = item.second.size();
        for (int i = 0; i < sz; i++){
            for (int k = i+1; k < sz; k++){
                processPoints(item.second[i], item.second[k], R, C, seen);
            }
        }
    }
    cout << seen.size() << endl;
   
    return 0;
}