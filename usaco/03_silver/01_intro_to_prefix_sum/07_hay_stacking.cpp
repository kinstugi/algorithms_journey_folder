#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO();
    int num_bales, num_instructions;
    cin >> num_bales >> num_instructions;

    vector<int> haybales(num_bales+3);

    int start, end;
    for (int i = 0; i < num_instructions; i++){
        cin >> start >> end;
        haybales[start]++;
        haybales[end+1]--;
    }

    for (int i = 1; i <= num_bales; i++ ){ haybales[i] += haybales[i-1]; }

    sort(haybales.begin()+1, haybales.begin()+num_bales+1);
    int d = num_bales / 2 + 1;
    cout << haybales[d] << endl;
    return 0;
}