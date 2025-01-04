#include <bits/stdc++.h>
using namespace std;

void setIO(string name = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool isArrayIncreasing(vector<int> &arr){
    int mxGap = 0, d = 0;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] <= arr[i-1]) { d++; }
        mxGap = max(mxGap, arr[i] - arr[i-1]);
    }
}

int main(){
    setIO("test");
    string line;
    int num;

    while (getline(cin, line)){
        if (!line.size()) break;
        istringstream iss(line);
        vector<int> level;

        while (iss >> num){ level.push_back(num); }
    }
    return 0;
}