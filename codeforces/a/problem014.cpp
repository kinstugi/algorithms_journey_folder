#include <iostream>
//https://codeforces.com/problemset/problem/148/A
using namespace std;

int arr[100002] = {0};

int main(){
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    if (k == 1 || l == 1 || m == 1 || n == 1)
    cout << d << endl;
    else{
        for (int i = k; i <= d; i += k)
        arr[i] = 1;

        for (int i = l; i <= d; i += l)
        arr[i] = 1;

        for (int i = m; i <= d; i += m)
        arr[i] = 1;

        for (int i = n; i <= d; i += n)
        arr[i] = 1;

        int ans = 0;
        for (int i=1; i <= d; ++i)
        ans += arr[i];

        cout << ans << endl;
    }
    return 0;
}