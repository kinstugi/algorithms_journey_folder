#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int turn = 0;
    for (int i = 1; i < n; i++){
        if ((s[i-1] == '0' && s[i] == '1') || (s[i-1] == '1' && s[i] == '0')){
            if (turn % 2){
                s[i-1] = '0';
                s[i] = '0';
            }
            turn++;
        }
    }
    
    for (char ch: s){
        if (ch == '0') continue;
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}