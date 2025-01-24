#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        cin >> arr[i];

        bool flag = true;
        int cur_max = arr[0];
        for (int num: arr){
            cur_max = max(cur_max, num);
            if (cur_max - num > 1){
                flag = false;
                break;
            }
        }

        if (flag)
        cout << "Yes\n";
        else
        cout << "No\n";
    }

    return 0;
}