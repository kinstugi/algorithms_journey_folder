#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        if (n > 1 && (k == 1 || k == n)){
            cout << -1 << "\n";
            continue;
        }else if (n == 1 && k == 1){
            cout << 1 << "\n1\n";
            continue;
        }

        if (k % 2){
            cout << 3 << "\n";
            cout << 1 << " " << k-1 << " " << k+2 << "\n";
        }else{
            cout << 3 << "\n";
            cout << 1 << " " << k << " " << k+1 <<  "\n";
        }
        
    }
    return 0;
}