#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    set<int> mp;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        mp.insert(tmp);
    }

    cout << mp.size() << endl;
    return 0;
}