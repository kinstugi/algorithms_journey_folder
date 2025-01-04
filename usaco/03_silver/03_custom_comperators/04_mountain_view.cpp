#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string file_name=""){
    ios_base::sync_with_stdio();
    cin.tie(0);
    if (file_name.size()){
        freopen((file_name + ".in").c_str(), "r", stdin);
        freopen((file_name + ".out").c_str(), "w", stdout);
    }
}

struct Mountain{
    int start, end;

    bool operator<(Mountain &other){
        if (start == other.start) { return end > other.end; }
        return start < other.start;
    }
};


int main(){
    setIO("mountains");
    int num_mountains, x, y;
    cin >> num_mountains;

    vector<Mountain> mountains(num_mountains);
    for (int i = 0; i < num_mountains; i++){
        cin >> x >> y;
        mountains[i].start = x - y;
        mountains[i].end = x + y;
    }
    sort(mountains.begin(), mountains.end());

    int right_most = -1;
    int visible_num = 0;

    for (const Mountain &mt: mountains){
        if (mt.end > right_most){
            visible_num++;
            right_most = mt.end;
        }
    }
    cout << visible_num << endl;
    return 0;
}