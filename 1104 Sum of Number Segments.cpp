#include <stdio.h>
int main(){
    int n;
    double ans = 0.0, a, tail = 0.0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &a);
        //tail += a * i;
        //ans += tail;
        ans += a * i * (n - i + 1);//�����������Ľⷨ�����ε�˼�룬�ܺ���⣬����case2�����ˡ�������Ż����ļ��㷽��
    }
    printf("%.2lf", ans);
}
