#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("sample.in", "r", stdin);
    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for(int num: arr){ cout << num << " "; }
    }
    return 0;
}