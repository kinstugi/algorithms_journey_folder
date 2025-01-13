// C++ template for AtCoder created by nazfox

#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using str = string;
template <typename T> using vec = vector<T>;
template <typename T> using vvec = vec<vec<T> >;
#define rep(i, n) for (i32 i = 0; i < (n); i++)
#define rrep(i, n) for (i32 i = (n) - 1; i >= 0; i--)
#define each(e, v) for (auto& e : v)
#define itr(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ritr(it, v) for (auto it = (v).rbegin(); it != (v).rend(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define debug(x) cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl;
template <typename T> inline T min(vector<T>& v){return *min_element(all(v));}
template <typename T> inline T max(vector<T>& v){return *max_element(all(v));}
template <typename T> inline T argmin(vector<T>& v){return (min_element(all(v)) - v.begin());}
template <typename T> inline T argmax(vector<T>& v){return (max_element(all(v)) - v.begin());}
template <typename T> inline bool chmin(T& a, const T& b){bool c=a>b;if(c)a=b;return c;}
template <typename T> inline bool chmax(T& a, const T& b){bool c=a<b;if(c)a=b;return c;}
template <typename T> inline void sort(vector<T>& v){sort(all(v));}
template <typename T> inline void rsort(vector<T>& v){sort(rall(v));}
template <typename T> inline void reverse(vector<T>& v){reverse(all(v));}

bool comp(const pair<i32, i32> &a, const pair<i32, i32> &b){
    return a.second > b.second;
}

int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    i32 t, n, k, tmp;
    cin >> t;

    while(t--){
        cin >> n >> k;
        map<i32, i32> mp;
        rep(i, n){ 
            cin >> tmp;
            mp[tmp]++;
        }
        vector<pair<i32, i32> > arr;
        for(const auto &item: mp){
            arr.push_back(make_pair(item.first, item.second));
        }
        sort(arr.begin(), arr.end(), comp);
        
        while(k && arr.size() > 1){
            if (arr.back().second > k){
                arr.back().second -= k;
                arr[0].second += k;
                k = 0;
            }else{
                arr[0].second += arr.back().second;
                k -= arr.back().second;
                arr.pop_back();
            }
        }

        cout << arr.size() << "\n";
    }
    return 0;
}