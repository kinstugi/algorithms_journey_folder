#include <iostream>

int main(){
    //freopen("sample.in", "r", stdin);

    int t, n, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        int d = abs(a - b) - 1;
        if (d % 2)
        printf("yes\n");
        else
        printf("no\n");
    }
    return 0;
}