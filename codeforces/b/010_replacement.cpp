#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;

    int zero = 0, one = 0;
    for (char ch: s){
        if (ch == '0') 
        zero++;
        else
        one++;
    }

    for(char ch: t){
        if (zero <= 0 || one <= 0){
            cout << "No\n";
            return;
        }

        if (ch == '0')
        one--;
        else
        zero--;
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