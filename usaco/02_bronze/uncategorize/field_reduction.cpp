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
  setIO("reduce");
  int n;
  cin >> n;
  
  vector<pair<pair<int, int>, int>> v(n);
  vector<pair<int, int>> p(n);

  for (int i = 0; i < n; i++) { 
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
    p[i] = v[i].first;
  }

  int mn = INT_MAX;
  vector<int> x, y;

  sort(v.begin(), v.end());
  for (const auto &item: v) { x.emplace_back(item.second); }

  sort(v.begin(), v.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
    return a.first.second < b.first.second;
  });
  for (int i = 0; i < n; i++) { y.emplace_back(v[i].second); }

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        for (int l = 0; l < 4; l++){
          if (i+j > 3 || k+l > 3) continue;

          int min_x = p[x[i]].first, max_x = p[x[n-1-j]].first, min_y = p[y[k]].second, max_y = p[y[n-1-l]].second;
          int cnt = 0;

          for (int m = 0; m < n; m++){
            if (p[m].first >= min_x && p[m].first <= max_x && p[m].second >= min_y && p[m].second <= max_y) continue;
            cnt++;
          }

          if (cnt <= 3){
            mn = min(mn, (max_x - min_x) * (max_y - min_y));
          }
        }
  
  cout << mn << endl;
  return 0;
}