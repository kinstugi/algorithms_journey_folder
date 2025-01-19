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

i64 fact(int n){
    i64 res = 1;
    for (int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);
    int t, n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        cout << 1 << " ";

        if (n >= 3 || d % 3 == 0){
            cout << 3 << " ";
        }

        if (d == 5){
            cout << 5 << " ";
        }

        if (n >= 3 || d == 7){
            cout << 7 << " ";
        }

        if (n >= 9){
            cout << 9 << " ";
        }else{
            i32 res = (fact(n) % 9) * (d % 9);
            if ((res) % 9 == 0){
                cout << 9 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}