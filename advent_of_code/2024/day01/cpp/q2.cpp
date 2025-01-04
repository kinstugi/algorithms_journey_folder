#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> list1;
map<int, int> mp;
int a, b;

void setIO(string file=""){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (file.size()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int main(){
    setIO("test");

    while (cin >> a >> b){
        list1.push_back(a);
        mp[b] += 1;
    }

    ll  res = 0;
    for (int num : list1){
        res += (ll)num * mp[num];
    }
    cout << res << endl;
}