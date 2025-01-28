#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);

    for (int i = 0; i < n; i++)
    cin >> A[i];

    for (int i = 0; i < n; i++)
    cin >> B[i];

    int negCnt = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++){
        C[i] = A[i] - B[i];
        negCnt += C[i] < 0;
        mn = min(mn, C[i]);
    }

    if (negCnt > 1){
        cout << "No\n";
        return;
    }
    
    sort(C.begin(), C.end());
    for (int num: C){
        if (num >= 0 && abs(mn) > num && mn < 0){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}