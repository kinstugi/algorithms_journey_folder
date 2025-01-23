#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));

        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++)
            cin >> grid[r][c];
        }

        int ans = 0;
        for (int r = 0; r < n; r++){
            int rr = r, cc = 0;
            int mn = 0;
            while (rr < n && cc < n){
                if (grid[rr][cc] < 0){
                    mn = min(mn, grid[rr][cc]);
                }
                rr++; cc++;
            }
            ans += abs(mn);
        }

        for (int c = 1; c < n; c++){
            int rr = 0, cc = c;
            int mn = 0;
            while (rr < n && cc < n){
                if (grid[rr][cc] < 0){
                    mn = min(mn, grid[rr][cc]);
                }
                rr++; cc++;
            }
            ans += abs(mn);
        }

        cout << ans << "\n";
    }
    return 0;
}