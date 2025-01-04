#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arrangement[3] = {0, 1, 2};
ll X[3], Y[3];
const int N = 3;

void solve(){
    for (int i = 0; i < 3; i++) { cin >> X[i] >> Y[i]; }

    ll total_area = 0;
    for (int i = 0; i < 3; i++){ total_area += X[i] * Y[i]; }

    ll side = 1;
    while (side * side < total_area){ side++; }

    if (side * side != total_area){
        cout << -1 << endl;
        return;
    }

    for (int mask = 0; mask < (1 << N); mask++){
        vector<string> grid(side, string(side, 'Z'));
        int num_placed = 0;

        for (int i = 0; i < side; i++){
            for (int j = 0; j < side; j++){
                if (grid[i][j] != 'Z') continue;

                if (num_placed == N){
                    goto outer;
                }

                int w = X[num_placed], h = Y[num_placed];

                if (mask & (1 << num_placed)){
                    swap(w, h);
                }

                for (int r = i; r < i + h; r++){
                    for (int c = j; c < j + w; c++){
                        if (r >= side || c >= side || grid[r][c] != 'Z') { goto outer; }
                        grid[r][c] = 'A' + num_placed;
                    }
                }

                num_placed++;
            }
        }

        assert(N == num_placed);

        cout << side << endl;
        for(string s: grid) { cout << s << endl; }
        return;
        outer:;
    }
    cout << -1 << endl;
}

int main(){

    solve();
    
    return 0;
}