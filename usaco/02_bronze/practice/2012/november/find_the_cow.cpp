#include <bits/stdc++.h>
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
    setIO("cowfind");
    string txt;
    cin >> txt;

    int N = txt.size();
    vector<int> after(N);

    for (int i = N-2; i > - 1; i--){
        if (txt[i] == ')' && txt[i+1] == ')') { after[i] = after[i+1] +1; }
        else { after[i] += after [i+1]; }
    }

    int ans = 0;
    for (int i = 0; i < N-1; i++){
        if (txt[i] == '(' && txt[i+1] == '(') { ans += after[i]; }
    }
    cout << ans << endl;
    return 0;
}