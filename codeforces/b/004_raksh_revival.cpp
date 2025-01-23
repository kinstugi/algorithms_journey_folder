#include <bits/stdc++.h>
using namespace std;

const int xd = 2e5 + 10;
int t, n, m, k, ps[xd];
string s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m >> k >> s;
        fill(ps, ps + n, 0);
        int ans = 0, cnt = 0, sum = 0;
        
        for (int i = 0; i < n; ++i){
            sum += ps[i];
            if (sum || s[i] == '1') cnt = 0;
            else{
                cnt++;
                if (cnt == m){
                    cnt = 0;
                    ans++;
                    sum++;
                    if (i + k < n) ps[i+k]--;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}