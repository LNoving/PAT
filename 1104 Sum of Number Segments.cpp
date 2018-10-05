#include <stdio.h>
int main(){
    int n;
    double ans = 0.0, a, tail = 0.0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &a);
        //tail += a * i;
        //ans += tail;
        ans += a * i * (n - i + 1);//上面的是我想的解法，分治的思想，很好理解，但是case2过不了。这个是优化过的计算方法
    }
    printf("%.2lf", ans);
}
