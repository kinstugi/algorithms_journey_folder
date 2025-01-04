#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Essentially, the solution is to use nested loops to iterate through the columns input matrix,
then calculate the sum of each column, and sort the elements of each column in non-descending 
order. Then calculate the absolute difference between the sum of the column and a running sum of the sorted elements.
This difference is multiplied by the number of elements that come before it in the sorted order to obtain the contribution of 
that element to the final answer. The contributions of all elements in a column are then summed up to obtain the final answer 
for that column, and this process is repeated for all columns.

The idea behind this approach is that the current element is being used as a representative of all the elements in the column that are smaller than it. Therefore, the difference between the sum of all elements and the sum of all elements before the current element is the sum of all the elements that are greater than the current element. This difference is then multiplied by the number of rows minus one minus the number of rows before the current element to obtain the total number of inversions.
*/

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int r = 0; r < n; ++r){
            for (int c = 0; c < m; ++c){
                cin >> grid[r][c];
            }
        }

        ll ans = 0;
        for (int c = 0; c < m; ++c){
            vector<ll> tmp;
            ll sum = 0;

            for (int r = 0; r < n; ++r){
                sum += grid[r][c];
                tmp.push_back(grid[r][c]);
            }

            ll cur = 0;
            sort(tmp.begin(), tmp.end());

            for (int r = 0; r < n; ++r){
                cur += tmp[r];
                ans += llabs((sum - cur) - (n - 1 -r) * tmp[r]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}