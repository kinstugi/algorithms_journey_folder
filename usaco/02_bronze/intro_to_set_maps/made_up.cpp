#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n),  B(n), C(n);
    
    for (int i = 0; i < n; i++) { cin >> A[i]; }
    for (int i = 0; i < n; i++) { cin >> B[i]; }
    for (int i = 0; i < n; i++) { cin >> C[i]; }

    unordered_map<int, int> mp_A, mp_C, mp_B;
    for (int a:  A){ mp_A[a]++;}
    for (int i = 0; i < n; ++i){
        mp_B[B[C[i]-1]]++; 
    }

    long long ans = 0;
    for (auto &item: mp_A){
        if (!mp_B.count(item.first)) continue;
        ans += (long long)item.second * mp_B[item.first];
    }
    cout << ans << endl;
    return 0;
}