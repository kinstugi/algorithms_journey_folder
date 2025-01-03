//https://codeforces.com/problemset/problem/146/A
#include <iostream>
using namespace std;

int digits[60];

bool helper(int n, string num){
    int l = 0, r = n-1;
    int sumA = 0, sumB = 0;
    while(l < r){
        int a = num[l] - '0', b = num[r] - '0';
        if (a != 4 && a != 7) return false;
        if (b != 4 && b != 7) return false;
        sumA += a;
        sumB += b;
        l++; r--;
    }
    return sumA == sumB;
}


int main(){
    int n; string num;
    cin >> n >> num;
    if (helper(n, num))
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    return 0;
}