#include <bits/stdc++.h>
using namespace std;

vector<int> list1, list2;
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
    setIO("input");

    while (cin >> a >> b){
        list1.push_back(a);
        list2.push_back(b);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int res = 0;
    for (int i = 0; i < list1.size(); i++){
        res += abs(list1[i] - list2[i]);
    }
    cout << res << endl;
}