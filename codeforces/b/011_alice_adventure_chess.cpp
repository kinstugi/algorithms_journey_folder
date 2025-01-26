#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, gr, gc;
    cin >> n >> gr >> gc;

    string dxn;
    cin >> dxn;
    
    int r = 0, c = 0;
    for (int i = 0; i < 100; i++){
        for(char ch: dxn){
            if (ch == 'N') c++;
            else if (ch == 'S') c--;
            else if (ch == 'E') r++;
            else if (ch == 'W') r--;

            if (gr == r && gc == c){
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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