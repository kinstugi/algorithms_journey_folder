#include <bits/stdc++.h>
using namespace std;

const int mod = 2019;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<int> mp(mod);
    mp[0]++;
    int power_of_ten = 1;
    int suffix = 0;
    
    long long ans = 0;

    for (int i = n-1; i > -1; i--){
        int digit = s[i] - '0';
        suffix = (suffix + digit * power_of_ten) % mod;
        power_of_ten = power_of_ten * 10 % mod;
        ans += mp[suffix];
        mp[suffix]++;
    }
    cout << ans << endl;
    return 0;
}