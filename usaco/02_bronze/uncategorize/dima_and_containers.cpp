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

struct Compare{
	bool operator()(int a, int b){
		return a < b;
	}
};

int main(){
	setIO("test");
    int n, tmp;
    cin >> n;

	vector<int> nums;
	priority_queue<int, vector<int>, Compare> pq;

    while (n--){
        cin >> tmp;
		if (tmp){
			nums.push_back(tmp);
			pq.push(tmp);
			while (pq.size() > 3) { pq.pop(); }
		}else{
			
			for (int num: nums){
				if (!pq.empty() && num == pq.top()){
					if (pq.size() == 3)
					cout << "pushFront\n"; 
					else if (pq.size() == 2)
					cout << "pushQueue\n";
					else if (pq.size() == 1)
					cout << "pushStack\n";
					pq.pop();
				}else if (pq.empty() || num != pq.top()){
					cout << "pushBack " << endl;
				}
			}

			if (nums.size() >= 3){
				cout << 3 << " popStack popQueue popFront\n";
			}else if (nums.size() >= 2){
				cout << "2 popStack popQueue\n";
			}else if (nums.size() >= 1){
				cout << "1 popStack\n";
			}else{
				cout << 0 << endl;
			}
			nums.clear();
			while (!pq.empty()) { pq.pop(); }
		}
    }
    return 0;
}