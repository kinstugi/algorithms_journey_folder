#include <iostream>
#include <algorithm>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("typo");
    string txt;
    cin >> txt;

    int opened = 0, closed = 0;
    for (int i = 0; i < txt.size(); i++){
        if (txt[i] == ')') { closed++ ;}
        else { opened++; }
    }

    if (closed == 0) { cout << (opened / 2) << endl; }
    else if (opened == 0) { cout << (closed / 2) << endl; }
    else {
        int mn = min(opened, closed);
        int mx = max(opened, closed);

        int res = mx - 1;
        cout << res << endl;
    }
    return 0;
}