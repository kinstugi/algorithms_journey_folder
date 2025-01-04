#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            cin >> grid[r][c];
        }
    }

    int ans = 0, tmp = 0;

    for (int r = 0; r < n; r++){
        int odd = 0, even = 0;
        for (int c = 0; c < n; c++){
            if (c % 2)
            odd += grid[r][c];
            else
            even += grid[r][c];
        }
        tmp += max(odd, even);
    }
    
    ans = max(ans,  tmp);
    tmp = 0;

    for (int c = 0; c < n; c++){
        int odd = 0, even = 0;
        for (int r = 0; r < n; r++){
            if (r % 2)
            odd += grid[r][c];
            else
            even += grid[r][c];
        }
        tmp += max(odd, even);
    }
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}