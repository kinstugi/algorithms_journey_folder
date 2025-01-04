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

const int  MAX_N = 10;

int main(){
    setIO("art");
    
    vector<int> left(MAX_N), right(MAX_N), up(MAX_N), down(MAX_N);
    for (int c = 1; c < MAX_N; ++c){
        left[c] = up[c] = INT_MAX;
        right[c] = down[c] = -1;
    }

    vector<bool> valid_start(MAX_N);
    int width;
    cin >> width;

    vector<vector<int>> art(width, vector<int>(width, 0));
    char cur_char;
    for (int r = 0; r < width; ++r){
        for (int c = 0; c < width; ++c){
            cin >> cur_char;
            int cur = cur_char - '0';

            art[r][c] = cur;
            if (cur != 0){
                left[cur] = min(left[cur], c);
                right[cur] = max(right[cur], c);
                down[cur] = max(down[cur], r);
                up[cur] = min(up[cur], r);
                valid_start[cur] = true;
            }
        }
    }

    for (int color = 1; color < MAX_N; ++color){
        for (int r = up[color]; r <= down[color]; ++r){
            for (int c = left[color]; c <= right[color]; ++c){
                if(art[r][c] != color){ valid_start[art[r][c]] = false; }
            }
        }
    }

    int total_starts = 0;
	for (bool s : valid_start) { total_starts += s ? 1 : 0; }
    cout << total_starts << "\n";
    return 0;
}