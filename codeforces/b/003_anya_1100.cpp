#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n;

bool check_1100(int i){
    if (i < 0) return false;
    if (i >= n - 3) return false;
    return s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0';
}

void solve(){
    cin >> s;
    n = (int) s.length();
    int count = 0;

    for (int i = 0; i < n; i++) { count += check_1100(i); }

    int q_cnt, i, v;
    cin >> q_cnt;
    while(q_cnt--){
        cin >> i >> v;
        i--;
        if (s[i] != '0' + v){
            bool before = check_1100(i-3) || check_1100(i-2) || check_1100(i-1) || check_1100(i);
            s[i] = v + '0';
            bool after = check_1100(i-3) || check_1100(i-2) || check_1100(i-1) || check_1100(i);
            count += after - before;
        }
        if (count)
        cout << "Yes\n";
        else
        cout << "No\n";
    }
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